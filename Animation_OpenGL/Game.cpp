#include "Game.h"
#include <GL/glut.h>
#include <string>
#include <math.h>
#include "Helper.h"
#include "Geometry.h"

Game::Game(int width, int height, bool devMode)
{
	this->dev = devMode;
	this->width = width;
	this->height = height;
	cloud_1 = new Obj::Cloud();
	cloud_2 = new Obj::Cloud();
	mountain = new Obj::Mountain();
	bird = new Obj::Bird();
	init();
}

void Game::init()
{
	isGameStart = false;
	isGameOver = false;

	cloud_1->x = width / 2;
	cloud_1->y = height / 2 + 50;
	cloud_2->y = height / 2 + 150;
	cloud_2->color[0] = 255;
	cloud_2->color[1] = 127;
	cloud_2->color[2] = 39;
	cloud_2->speed += .01;
	bird->scale = .4;
	bird->x = 100;
	bird->y = height / 2;
	bird->velocity = 0;
	bird->angle = 0;

	for (int i = 0; i < sizeof(knifes) / sizeof(knifes[0]); i++) {
		knifes[i].scale = .3;
		knifes[i].rotation = 90;
		knifes[i].reset(width + 100, height);
	}

	glClearColor(Helper::hexToFloat(0), Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255));
}

void Game::update()
{
	//background
	if (cloud_1->x <= -200) {
		cloud_1->x = width + 10;
	}
	if (cloud_2->x <= -200) {
		cloud_2->x = width + 10;
	}
	if (mountain->x <= -860) {
		mountain->x = width;
	}
	cloud_1->x -= cloud_1->speed;
	cloud_2->x -= cloud_2->speed;
	mountain->x -= mountain->speed;

	//check game status
	if (!isGameStart && !isGameOver)
	{
		glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(50), Helper::hexToFloat(0));
		std::string title = "Tap 'Spacebar' or 'Left-click' to start";
		drawText(title.data(), title.length(), width / 2, height / 2);
		return;
	}
	else if (isGameStart && !isGameOver)
	{
		if (bird->y <= -100 || bird->y >= height) {
			isGameOver = true;
			isGameStart = false;
		}
		else {
			bird->drop();

			float birdRadius = bird->getScaledRadius();
			float knifeWidth = knifes[0].getScaledHeight();
			float knifeRadius = knifeWidth / 2;

			for (int i = 0; i < sizeof(knifes) / sizeof(knifes[0]); i++) {
				if (knifes[i].x >= -100) {
					knifes[i].moveLeft();

#pragma region Dev Guideline
					if (dev)
					{
						glColor3f(1, 0, 0);
						Geo::drawCircle(knifes[i].x, knifes[i].y, 10);
						Geo::drawCircle(knifes[i].x - knifeRadius, knifes[i].y, 10);
						Geo::drawCircle(knifes[i].x - knifeWidth, knifes[i].y, 10);

						glColor3f(0, 0, 1);
						Geo::drawCircle(bird->x + birdRadius, bird->y + birdRadius - 20, 10);
						Geo::drawCircle(bird->x - birdRadius, bird->y - birdRadius, 10);
					}
#pragma endregion

					if (((knifes[i].x - knifeWidth < bird->x + birdRadius && knifes[i].x - knifeWidth > bird->x - birdRadius) ||
						(knifes[i].x - knifeRadius < bird->x + birdRadius && knifes[i].x - knifeRadius > bird->x - birdRadius) ||
						(knifes[i].x < bird->x + birdRadius && knifes[i].x > bird->x - birdRadius)) &&
						knifes[i].y < bird->y + birdRadius - 20 && knifes[i].y>bird->y - birdRadius)
					{
						isGameOver = true;
						isGameStart = false;
					}
				}
				else {
					knifes[i].reset(width + 100, height);
				}
			}
		}
	}
	else
	{
		glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(50), Helper::hexToFloat(0));
		std::string title = "GAME OVER";
		drawText(title.data(), title.length(), width / 2, height / 2);
		std::string desc = "Press 'Enter' to retry again";
		drawText(desc.data(), desc.length(), width / 2, height / 2 - 28);
	}
}

void Game::render()
{
	//mountain
	glPushMatrix();
	mountain->draw();
	glPopMatrix();

	//cloud 1
	glPushMatrix();
	cloud_1->draw();
	glPopMatrix();

	//cloud 2
	glPushMatrix();
	cloud_2->draw();
	glPopMatrix();

	//bird
	glPushMatrix();
	bird->draw();
	glPopMatrix();

#pragma region Dev guideline (bird)
	if (dev)
	{
		bird->drawDevGuideLine();
	}
#pragma endregion

	//knife
	for each (Obj::Knife knife in knifes)
	{
		glPushMatrix();
		knife.draw();
		glPopMatrix();
	}
}

void Game::birdFly()
{
	if (isGameStart)
		bird->fly();
	else
		isGameStart = true;
}

void Game::drawText(const char * text, GLint length, GLfloat x, GLfloat y)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();

	//width of the string
	unsigned int string_width = 0;
	for (const char *c = text; *c != NULL; c++)
		string_width += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, *c);

	glRasterPos2f(x - string_width / 2, y);
	for (const char *c = text; *c != NULL; c++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}