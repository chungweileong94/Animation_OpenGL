#include "Intro.h"
#include <GL/glut.h>
#include <string>
#include "Helper.h"
#include "Game.h"

Intro::Intro(int width, int height)
{
	this->width = width;
	this->height = height;
	cloud_1 = new Obj::Cloud();
	cloud_2 = new Obj::Cloud();
	bird = new Obj::Bird();
	bird_mom = new Obj::Bird();
	knife = new Obj::Knife();
	birdchatbox = new Obj::Chatbox();
	bird_momchatbox = new Obj::Chatbox();
	hunterchatbox = new Obj::Chatbox();
	hunter = new Obj::Hunter();
	cage = new Obj::Cage();
	mountain = new Obj::Mountain();
	tear = new Obj::Tear();
	init();
}

Intro::~Intro()
{
	delete cloud_1;
	delete cloud_2;
	delete bird;
	delete bird_mom;
	delete knife;
	delete birdchatbox;
	delete bird_momchatbox;
	delete hunterchatbox;
	delete hunter;
	delete cage;
	delete mountain;
	delete tear;
}

void Intro::init()
{
	isIntroOver = false;
	isKnifeFly = false;
	isMomBeenCut = false;
	isMomFall = false;

	cloud_1->x = 300;
	cloud_1->y = height / 3;
	cloud_2->y = height / 2 + 50;
	cloud_2->color[0] = 255;
	cloud_2->color[1] = 127;
	cloud_2->color[2] = 39;
	cloud_2->speed += .01;
	knife->scale = 0.4;
	knife->rotation = 90;
	knife->x = width + 100;
	knife->y = height / 2 + 40;
	birdchatbox->scale = .8;
	birdchatbox->x = width;
	birdchatbox->y = height / 3;
	bird_momchatbox->scale = .8;
	bird_momchatbox->x = width;
	bird_momchatbox->y = height / 3 - 80;
	hunterchatbox->scale = 1;
	hunterchatbox->x = width;
	hunterchatbox->y = height / 3 - 10;
	hunter->x = width;
	hunter->y = 10;
	hunter->scale = 1.0;
	cage->scale = 1;
	cage->x = width;
	cage->y = 10;
	mountain->x = width;
	mountain->y = 0;
	mountain->scale = 1.1;
	bird->scale = .7;
	bird->x = 400;
	bird->y = height / 3;
	bird->angle = 0;
	bird_mom->scale = 1.2;
	bird_mom->x = 200;
	bird_mom->y = height / 2 + 100;
	bird_mom->angle = 0;
	tear->x = width;
	tear->y = 126;
	tear->scale = 0.3;
	glClearColor(Helper::hexToFloat(0), Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255));
}

void Intro::update()
{
	//background
	if (cloud_1->x <= -200) {
		cloud_1->x = width + 10;
	}
	if (cloud_2->x <= -200) {
		cloud_2->x = width + 10;
	}
	cloud_1->x -= cloud_1->speed;
	cloud_2->x -= cloud_2->speed;

	//check intro status

	if (!isIntroOver && !isKnifeFly && !isMomBeenCut && !isMomFall)
	{
		glColor3f(Helper::hexToFloat(0), Helper::hexToFloat(0), Helper::hexToFloat(0));
		std::string title;
		title = "One day... Little bird is flying togather with its mom...";
		if (cloud_1->x - 200 <= 0) {
			isKnifeFly = true;
		}
		drawText(title.data(), title.length(), width / 2, height - 50);
	}
	else if (!isIntroOver && isKnifeFly && !isMomBeenCut && !isMomFall)
	{
		glColor3f(Helper::hexToFloat(0), Helper::hexToFloat(0), Helper::hexToFloat(0));
		std::string title;
		title = "Suddenly...";
		if (knife->x >= width / 2 + 60) {
			knife->x -= 1.5;
		}
		else {
			isMomBeenCut = true;
		}
		drawText(title.data(), title.length(), width / 2, height - 50);
	}
	else if (!isIntroOver && isKnifeFly && isMomBeenCut && !isMomFall)
	{
		birdchatbox->x = 450;
		glColor3f(Helper::hexToFloat(0), Helper::hexToFloat(0), Helper::hexToFloat(0));
		std::string title;
		title = "Mom!";
		drawText(title.data(), title.length(), 506, height / 3 + 36);
		if (bird_mom->y >= -100) {
			bird_mom->angle += 0.6;
			knife->rotation += 1.4;
			bird_mom->y -= 1.2;
			knife->y -= 1.2;
		}
		else {
			isMomFall = true;
			glFlush();
			changeScene();
		}
	}
	else if (!isIntroOver && isKnifeFly && isMomBeenCut && isMomFall) {
		glColor3f(Helper::hexToFloat(0), Helper::hexToFloat(0), Helper::hexToFloat(0));
		std::string bird_mom_title;
		bird_mom_title = "HELP!";
		std::string hunter_title1, hunter_title2;
		hunter_title1 = "Dinner";
		hunter_title2 = "Settle~";

		if (bird->x <= 100) {
			bird->x += 1.0;
		}
		else {
			birdchatbox->x = 130;
			std::string bird_title1, bird_title2;
			bird_title1 = "Let Her";
			bird_title2 = "Go!";
			hunter_title1 = "No";
			hunter_title2 = "Way";
			tear->x = 126;
			if (tear->scale <= 1) {
				tear->y -= 0.06;
				tear->scale += 0.003;
				drawText(bird_title1.data(), bird_title1.length(), 184, height / 3 + 15);
				drawText(bird_title2.data(), bird_title2.length(), 184, height / 3 - 5);
			}
			else {
				hunter_title1 = "";
				hunter_title2 = "";
				bird_mom_title = "";
				bird_title1 = "";
				bird_title2 = "";
				tear->x = width;
				birdchatbox->x = width;
				hunterchatbox->x = width;
				bird_momchatbox->x = width;
				hunter->x += 2.0;
				cage->x += 2.0;
				bird_mom->x += 2.0;
				bird->x += 2.0;
				isIntroOver = true;
			}
		}
		drawText(bird_mom_title.data(), bird_mom_title.length(), width - 42, height / 3 - 46);
		drawText(hunter_title1.data(), hunter_title1.length(), width / 2 + 170, height / 3 + 50);
		drawText(hunter_title2.data(), hunter_title2.length(), width / 2 + 170, height / 3 + 20);
	}
}

void Intro::render()
{
	//cloud 1
	glPushMatrix();
	cloud_1->draw();
	glPopMatrix();

	//cloud 2
	glPushMatrix();
	cloud_2->draw();
	glPopMatrix();

	//mountain
	glPushMatrix();
	mountain->draw();
	glPopMatrix();

	//knife
	glPushMatrix();
	knife->draw();
	glPopMatrix();

	//chatbox
	glPushMatrix();
	birdchatbox->draw();
	glPopMatrix();

	//bird mom chatbox
	glPushMatrix();
	bird_momchatbox->draw();
	glPopMatrix();

	//hunter chatbox
	glPushMatrix();
	hunterchatbox->draw();
	glPopMatrix();

	//bird
	glPushMatrix();
	bird->draw();
	glPopMatrix();

	//bird mom
	glPushMatrix();
	bird_mom->draw();
	glPopMatrix();

	//hunter
	glPushMatrix();
	hunter->draw();
	glPopMatrix();

	//cage
	glPushMatrix();
	cage->draw();
	glPopMatrix();

	//tear
	glPushMatrix();
	tear->draw();
	glPopMatrix();
}

void Intro::changeScene() {
	birdchatbox->x = width;
	birdchatbox->y = 170;
	bird_momchatbox->x = width - 100;
	hunterchatbox->x = width / 2 + 100;
	bird->scale = 0.5;
	bird->x = -100;
	bird->y = 150;
	bird_mom->scale = 0.5;
	bird_mom->angle = 0;
	bird_mom->x = width - 66;
	bird_mom->y = 60;
	hunter->x = width / 2;
	cloud_1->scale = 0.6;
	cloud_2->scale = 0.5;
	cloud_1->y = height - 170;
	cloud_2->y = height - 130;
	cage->x = width - 150;
	mountain->x = -100;
}

void Intro::drawText(const char * text, GLint length, GLfloat x, GLfloat y)
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