#ifndef GEOMETRY_H
#define GEOMETRY_H

namespace Geo
{
	void drawTriangle(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3);
	void drawRectangle(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4);
	void drawCircle(float x, float y, float radius);
	void drawHalfCircle(float x, float y, float radius);
	void drawOval(float x_center, float y_center, float w, float h);
	void drawLine(int x1, int y1, int x2, int y2);
}

#endif // !GEOMETRY_H
