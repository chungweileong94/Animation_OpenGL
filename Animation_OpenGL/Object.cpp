#include "Object.h"
#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"
#include <math.h>

#define PI 3.14159265

void Obj::Knife::draw()
{
	glTranslatef(x, y, 0);
	glScalef(scale, scale, 0);

	glPushMatrix();

	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	//w:81 h:243
	glColor3f(Helper::hexToFloat(200), Helper::hexToFloat(191), Helper::hexToFloat(231));
	Geo::drawTriangle(14, 87, 40.5, 243, 40.5, 87);
	glColor3f(Helper::hexToFloat(127), Helper::hexToFloat(127), Helper::hexToFloat(127));
	Geo::drawTriangle(40.5, 87, 40.5, 243, 67, 87);
	glColor3f(Helper::hexToFloat(185), Helper::hexToFloat(122), Helper::hexToFloat(87));
	Geo::drawRectangle(0, 87, 81, 87, 81, 70, 0, 70);
	glColor3f(Helper::hexToFloat(64), Helper::hexToFloat(0), Helper::hexToFloat(0));
	Geo::drawRectangle(27, 70, 54, 70, 54, 0, 27, 0);

	glPopMatrix();
}

void Obj::Knife::reset(float xPos, float maxHeight)
{
	x = xPos;
	y = rand() % (int)maxHeight + 1;
	speed = rand() % 2 + 1;
}

void Obj::Mountain::draw()
{
	glTranslatef(x, y, 0);
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
	glTranslatef(x, y, 0);
	glScalef(scale, scale, 0);
	//shadow
	int shadowX = 3, shadowY = 3;
	glColor3f(Helper::hexToFloat(color[0] - 50), Helper::hexToFloat(color[1] - 50), Helper::hexToFloat(color[2] - 50));
	Geo::drawCircle(28 + shadowX, 28 + shadowY, 28);
	Geo::drawCircle(60 + shadowX, 65 + shadowY, 28);
	Geo::drawCircle(99 + shadowX, 50 + shadowY, 28);
	Geo::drawCircle(140 + shadowX, 28 + shadowY, 28);
	Geo::drawRectangle(28 + shadowX, 0 + shadowY, 28 + shadowX, 40 + shadowY, 140 + shadowX, 40 + shadowY, 140 + shadowX, 0 + shadowY);

	glColor3f(Helper::hexToFloat(color[0]), Helper::hexToFloat(color[1]), Helper::hexToFloat(color[2]));
	Geo::drawCircle(28, 28, 28);
	Geo::drawCircle(60, 65, 28);
	Geo::drawCircle(99, 50, 28);
	Geo::drawCircle(140, 28, 28);
	Geo::drawRectangle(28, 0, 28, 40, 140, 40, 140, 0);
}

void Obj::Wood::draw()
{
	glTranslatef(x, y, 0);
	glScalef(scale, scale, 0);

	//w: 158 h:391
	glColor3f(Helper::hexToFloat(150), Helper::hexToFloat(94), Helper::hexToFloat(63));
	Geo::drawRectangle(0, 0, 0, 391, 158, 391, 158, 0);

	glColor3f(Helper::hexToFloat(91), Helper::hexToFloat(57), Helper::hexToFloat(38));
	glLineWidth(5);
	Geo::drawLine(39, 203, 39, 334);
	Geo::drawLine(50, 24, 50, 138);
	Geo::drawLine(75, 87, 75, 210);
	Geo::drawLine(116, 30, 116, 120);
	Geo::drawLine(134, 188, 134, 328);

	Geo::drawOval(95, 283, 48, 98);
	glColor3f(Helper::hexToFloat(150), Helper::hexToFloat(94), Helper::hexToFloat(63));
	Geo::drawOval(95, 283, 37, 87);
	glColor3f(Helper::hexToFloat(91), Helper::hexToFloat(57), Helper::hexToFloat(38));
	Geo::drawOval(97, 278, 20, 40);
	glColor3f(Helper::hexToFloat(150), Helper::hexToFloat(94), Helper::hexToFloat(63));
	Geo::drawOval(97, 278, 9, 29);
}

void Obj::Bird::draw()
{
	//w:392 h:230
	glTranslatef(x, y, 0);
	glScalef(scale, scale, 0);

	glPushMatrix();
	glTranslatef(height / 2 * cos((angle + 225)*PI / 180), height / 2 * sin((angle + 225) *PI / 180), 0);
	glRotated(angle, 0, 0, 1);

#pragma region draw
	//shadow
	int shadowX = -5, shadowY = -5;
	glColor3f(Helper::hexToFloat(211), Helper::hexToFloat(72), Helper::hexToFloat(0));
	Geo::drawTriangle(0 + shadowX, 151 + shadowY, 77 + shadowX, 140 + shadowY, 18 + shadowX, 173 + shadowY);
	Geo::drawTriangle(20 + shadowX, 131 + shadowY, 77 + shadowX, 140 + shadowY, 23 + shadowX, 143 + shadowY);
	Geo::drawOval(133 + shadowX, 115 + shadowY, 137, 115);
	//Geo::drawOval(190 + shadowX, 130 + shadowY, 38, 50);
	//Geo::drawTriangle(168 + shadowX, 80 + shadowY, 177 + shadowX, 101 + shadowY, 214 + shadowX, 75 + shadowY);
	Geo::drawOval(90 + shadowX, 85 + shadowY, 70, 40);

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
#pragma endregion

	glPopMatrix();
}

void Obj::Bird::drawDevGuideLine()
{
	glPointSize(2);
	glColor3i(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x - height / 2 * pow(scale, 2), y - height / 2 * pow(scale, 2));
	glVertex2i(x - height / 2 * pow(scale, 2), y + height / 2 * pow(scale, 2));
	glVertex2i(x - height / 2 * pow(scale, 2), y + height / 2 * pow(scale, 2));
	glVertex2i(x + height / 2 * pow(scale, 2), y + height / 2 * pow(scale, 2));
	glVertex2i(x + height / 2 * pow(scale, 2), y + height / 2 * pow(scale, 2));
	glVertex2i(x + height / 2 * pow(scale, 2), y - height / 2 * pow(scale, 2));
	glVertex2i(x + height / 2 * pow(scale, 2), y - height / 2 * pow(scale, 2));
	glVertex2i(x - height / 2 * pow(scale, 2), y - height / 2 * pow(scale, 2));
	glVertex2i(x - height / 2 * pow(scale, 2), y - height / 2 * pow(scale, 2));
	glVertex2i(x, y);
	glEnd();
}

void Obj::Bird::drop()
{
	velocity -= gravity;
	y += velocity;
	if (angle > -45)
	{
		angle -= .2;
	}
}

void Obj::Bird::fly()
{
	velocity += lift;
	angle = 45;
}

float Obj::Bird::getScaledRadius()
{
	return height / 2 * pow(scale, 2);
}

void Obj::Knife::moveLeft()
{
	x -= speed;
}

float Obj::Knife::getScaledHeight()
{
	return height * scale;
}


void Obj::Chatbox::draw()
{
	glTranslatef(x, y, 0);
	glScalef(scale, scale, 0);
	//w:81 h:243
	glColor3f(Helper::hexToFloat(220), Helper::hexToFloat(255), Helper::hexToFloat(255));
	Geo::drawRectangle(20, 20, 120, 20, 120, 80, 20, 80);
	Geo::drawTriangle(0, 0, 20, 20, 20, 30);
}

void Obj::Tear::draw()
{
	glTranslatef(x, y, 0);
	glScalef(scale, scale, 0);
	//w:81 h:243
	glColor3f(Helper::hexToFloat(220), Helper::hexToFloat(255), Helper::hexToFloat(255));
	Geo::drawTriangle(0, 10, 10, 10, 5, 20);
	Geo::drawBottomHalfCircle(5, 10, 5);
}

void Obj::Cage::draw()
{
	glTranslatef(x, y, 0);
	glScalef(scale, scale, 0);
	//w:81 h:243
	glColor3f(Helper::hexToFloat(220), Helper::hexToFloat(220), Helper::hexToFloat(220));
	Geo::drawRectangle(0, 0, 130, 0, 130, 10, 0, 10);
	Geo::drawRectangle(10, 10, 30, 10, 30, 100, 10, 100);
	Geo::drawRectangle(40, 10, 60, 10, 60, 100, 40, 100);
	Geo::drawRectangle(70, 10, 90, 10, 90, 100, 70, 100);
	Geo::drawRectangle(100, 10, 120, 10, 120, 100, 100, 100);
	Geo::drawRectangle(0, 100, 130, 100, 130, 110, 0, 110);
}

void Obj::Hunter::draw()
{
	glTranslatef(x, y, 0);
	glScalef(scale, scale, 0);
	//w:81 h:243
	//foot
	glColor3f(Helper::hexToFloat(40), Helper::hexToFloat(200), Helper::hexToFloat(160));
	Geo::drawRectangle(50, 0, 70, 0, 70, 10, 50, 10);
	Geo::drawRectangle(90, 0, 110, 0, 110, 10, 90, 10);
	//leg
	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(240), Helper::hexToFloat(170));
	Geo::drawRectangle(54, 10, 66, 10, 66, 24, 54, 24);
	Geo::drawRectangle(94, 10, 106, 10, 106, 24, 94, 24);
	//pants
	glColor3f(Helper::hexToFloat(180), Helper::hexToFloat(150), Helper::hexToFloat(30));
	Geo::drawRectangle(50, 24, 70, 24, 70, 44, 50, 44);
	Geo::drawRectangle(90, 24, 110, 24, 110, 44, 90, 44);
	Geo::drawTriangle(70, 24, 90, 44, 70, 44);
	Geo::drawTriangle(90, 24, 70, 44, 90, 44);
	//shirt
	glColor3f(Helper::hexToFloat(170), Helper::hexToFloat(220), Helper::hexToFloat(20));
	Geo::drawRectangle(50, 44, 110, 44, 110, 84, 50, 84);
	Geo::drawTriangle(36, 64, 50, 64, 50, 84);
	Geo::drawTriangle(110, 64, 124, 64, 110, 84);
	//face
	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(240), Helper::hexToFloat(170));
	Geo::drawRectangle(50, 84, 110, 84, 110, 134, 50, 134);
	//hair
	glColor3f(Helper::hexToFloat(0), Helper::hexToFloat(0), Helper::hexToFloat(0));
	Geo::drawHalfCircle(80, 134, 36);
	Geo::drawTriangle(46,134, 50,130, 50,134);
	Geo::drawTriangle(110, 130,114, 134,110,134);
	//mouth
	glColor3f(Helper::hexToFloat(100), Helper::hexToFloat(20), Helper::hexToFloat(20));
	Geo::drawTriangle(80, 90, 90, 100, 70, 100);
	//eye
	glColor3f(Helper::hexToFloat(0), Helper::hexToFloat(0), Helper::hexToFloat(0));
	//left eye
	Geo::drawLine(62,114,68,124);
	Geo::drawLine(68,124,74,114);
	//right eye
	Geo::drawLine(82, 114, 88, 124);
	Geo::drawLine(88, 124, 94, 114);
	//hand
	glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(240), Helper::hexToFloat(170));
	Geo::drawRectangle(36,44,46,44,46,64,36,64);
	Geo::drawRectangle(114,44,124,44,124,64,114,64);
	Geo::drawCircle(41, 44, 6);
	Geo::drawCircle(119, 44, 6);
}