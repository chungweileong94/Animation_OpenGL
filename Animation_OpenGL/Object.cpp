#include "Object.h"
#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"

void Obj::Knife::draw()
{
	glColor3f(Helper::hexToFloat(180), Helper::hexToFloat(193), Helper::hexToFloat(200));
	//Geo::drawTriangle(0, 0, 0, 50, 20, 0, true);
	Geo::drawHalfCircle(0, 0, 30, true);
}
