#ifndef GEOMETRY_H
#define GEOMETRY_H

namespace Geo
{
	void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	void drawRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	void drawCircle(float x, float y, float radius);
	void drawHalfCircle(float x, float y, float radius);
	void drawBottomHalfCircle(float x, float y, float radius);
	void drawOval(float x_center, float y_center, float w, float h);
	void drawLine(int x1, int y1, int x2, int y2);
}

#endif // !GEOMETRY_H
