#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"
#include "Object.h"

const char* title = "Assignment 2";
const int width = 600;
const int height = 600;

void render();
void reshape(int newWidth, int newHeight);

void main(int argc, char** argv) {
	FreeConsole(); //hide console
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 50);
	glutCreateWindow(title);

	glutDisplayFunc(render);
	glutReshapeFunc(reshape);

	glClearColor(Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255));

	glutMainLoop();
}

void render()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	glClear(GL_COLOR_BUFFER_BIT);


	glPushMatrix();
	glTranslated(60, 86, 0);
	Obj::Knife().draw();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void reshape(int newWidth, int newHeight)
{
	if (newWidth != width || newHeight != height)
	{
		glutReshapeWindow(width, height);
	}
}
