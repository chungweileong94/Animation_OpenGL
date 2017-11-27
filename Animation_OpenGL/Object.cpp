#include "Object.h"
#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"

void Obj::Knife::draw()
{
	glScalef(scale, scale, 0);
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
	glScalef(scale, scale, 0);
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
	glScalef(scale, scale, 0);
	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(220), Helper::hexToFloat(31));
	Geo::drawCircle(28, 28, 28);
	Geo::drawCircle(60, 65, 28);
	Geo::drawCircle(99, 50, 28);
	Geo::drawCircle(140, 28, 28);
	Geo::drawRectangle(28, 0, 28, 40, 140, 40, 140, 0);
}

void Obj::Wood::draw()
{

}

void Obj::Bird::draw()
{
	glScalef(scale, scale, 0);
	//w:392 h:230
	//tail
	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(201), Helper::hexToFloat(14));
	Geo::drawTriangle(0, 151, 77, 140, 18, 173);
	glColor3f(Helper::hexToFloat(237), Helper::hexToFloat(28), Helper::hexToFloat(36));
	Geo::drawTriangle(20, 131, 77, 140, 23, 143);

	//body
	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(242), Helper::hexToFloat(0));
	Geo::drawOval(133, 115, 137, 115);

	//eyes
	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255));
	Geo::drawOval(190, 130, 38, 50);
	Geo::drawOval(158, 130, 38, 50);
	glColor3f(Helper::hexToFloat(0), Helper::hexToFloat(0), Helper::hexToFloat(0));
	Geo::drawOval(203, 125, 10, 18);
	Geo::drawOval(172, 125, 10, 18);

	//mouth
	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(127), Helper::hexToFloat(39));
	Geo::drawTriangle(168, 80, 177, 101, 214, 75);

	//wing
	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(201), Helper::hexToFloat(14));
	Geo::drawOval(90, 85, 70, 40);
}

void Obj::Bird::drop()
{
	velocity -= gravity;
	y += velocity;
}

void Obj::Bird::fly()
{
	velocity += lift;
}
