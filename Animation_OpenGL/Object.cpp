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
