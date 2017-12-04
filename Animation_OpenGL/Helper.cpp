#include "Helper.h"

float Helper::hexToFloat(int hex)
{
	return hex / 255.0f;
}

void Helper::drawText(const char * text, GLint length, GLfloat x, GLfloat y, int windowWidth, int windowHeight, bool smallText)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, 0, windowHeight);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();

	//width of the string
	unsigned int current_line_string_width = 0;
	unsigned int larger_string_width = 0;
	for (const char *c = text; *c != NULL; c++)
	{
		if (*c == '\\')
		{
			larger_string_width = (current_line_string_width > larger_string_width) ? current_line_string_width : larger_string_width;
			current_line_string_width = 0;
		}
		else
		{
			current_line_string_width += glutBitmapWidth(smallText ? GLUT_BITMAP_HELVETICA_12 : GLUT_BITMAP_HELVETICA_18, *c);
		}
	}
	larger_string_width = (current_line_string_width > larger_string_width) ? current_line_string_width : larger_string_width;

	glRasterPos2f(x - larger_string_width / 2, y);
	for (const char *c = text; *c != NULL; c++)
	{
		if (*c == '\\')
			glRasterPos2f(x - larger_string_width / 2, y - 19);
		else
			glutBitmapCharacter(smallText ? GLUT_BITMAP_HELVETICA_12 : GLUT_BITMAP_HELVETICA_18, *c);
	}
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}
