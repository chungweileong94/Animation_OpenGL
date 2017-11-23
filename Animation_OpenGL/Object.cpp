#include "Object.h"
#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"

void Obj::Knife::draw()
{
	//w:81 h:243
	glColor3f(Helper::hexToFloat(200), Helper::hexToFloat(191), Helper::hexToFloat(231));
	Geo::drawTriangle(14, 87, 40.5, 243, 40.5, 87);
	glColor3f(Helper::hexToFloat(127), Helper::hexToFloat(127), Helper::hexToFloat(127));
	Geo::drawTriangle(40.5, 87, 40.5, 243, 67, 87);
	glColor3f(Helper::hexToFloat(185), Helper::hexToFloat(122), Helper::hexToFloat(87));
	Geo::drawRectangle(0, 87, 81, 87, 81, 70, 0, 70);
	glColor3f(Helper::hexToFloat(64), Helper::hexToFloat(0), Helper::hexToFloat(0));
	Geo::drawRectangle(27, 70, 54, 70, 54, 0, 27, 0);
}

void Obj::Mountain::draw()
{
	glColor3f(Helper::hexToFloat(65), Helper::hexToFloat(89), Helper::hexToFloat(141));
	Geo::drawTriangle(359, 0, 601, 284, 846, 0);
	glColor3f(Helper::hexToFloat(112), Helper::hexToFloat(146), Helper::hexToFloat(190));
	Geo::drawTriangle(0, 0, 308, 375, 616, 0);

	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255));
	Geo::drawTriangle(220, 268, 308, 375, 396, 268);
	Geo::drawTriangle(526, 198, 601, 284, 676, 198);
}

void Obj::Cloud::draw()
{
	glColor3f(Helper::hexToFloat(253), Helper::hexToFloat(238), Helper::hexToFloat(31));
	Geo::drawCircle(28, 28, 28);
	Geo::drawCircle(60, 65, 28);
	Geo::drawCircle(99, 50, 28);
	Geo::drawCircle(140, 28, 28);
	Geo::drawRectangle(28, 0, 28, 40, 140, 40, 140, 0);
}
