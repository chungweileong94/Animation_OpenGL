#include <GL\glut.h>
#include <math.h>
#include "Geometry.h"
#define PI 3.14159265358979323846

void Geo::drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();
}

void Geo::drawRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	glBegin(GL_QUADS);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();
}

void Geo::drawCircle(float x, float y, float radius)
{
	float t = 0;
	const int vertices = 1000;

	glBegin(GL_POLYGON);
	for (int i = 0; i < vertices; ++i)
	{
		glVertex2f(x + radius*cos(t), y + radius*sin(t));
		t += 2 * PI / vertices;
	}
	glEnd();
}

void Geo::drawHalfCircle(float x, float y, float radius)
{
	float t = 0;
	const int vertices = 500;

	glBegin(GL_POLYGON);
	for (int i = 0; i < vertices; ++i)
	{
		glVertex2f(x + radius*cos(t), y + radius*sin(t));
		t += PI / vertices;
	}
	glEnd();
}

void Geo::drawBottomHalfCircle(float x, float y, float radius)
{
	float t = 0;
	const int vertices = 500;

	glBegin(GL_POLYGON);
	for (int i = 0; i < vertices; ++i)
	{
		glVertex2f(x + radius*cos(t), y - radius*sin(t));
		t += PI / vertices;
	}
	glEnd();
}


void Geo::drawOval(float x, float y, float width, float height)
{
	float t = 0;
	const int vertices = 1000;

	glBegin(GL_POLYGON);
	for (int i = 0; i < vertices; ++i)
	{
		glVertex2f(x + width / 2 * cos(t), y + height / 2 * sin(t));
		t += 2 * PI / vertices;
	}
	glEnd();
}

void Geo::drawLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}