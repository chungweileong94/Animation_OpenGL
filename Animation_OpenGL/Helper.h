#ifndef HELPER_H
#define HELPER_H

#include <GL\glut.h>

namespace Helper
{
	float hexToFloat(int hex);
	void drawText(const char * text, GLint length, GLfloat x, GLfloat y, int windowWidth, int windowHeight);
}

#endif // !HELPER_H
