#include "Intro.h"
#include <GL/glut.h>
#include <string>
#include "Helper.h"
#include "Game.h"

Intro::Intro(int width, int height)
{
	this->width = width;
	this->height = height;
	story_telling_text = "";
	cloud_1 = new Obj::Cloud();
	cloud_2 = new Obj::Cloud();
	bird = new Obj::Bird();
	bird_mom = new Obj::Bird();
	knife = new Obj::Knife();
	bird_chat_box = new Obj::Chatbox();
	bird_mom_chat_box = new Obj::Chatbox();
	hunter_chat_box = new Obj::Chatbox();
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
	delete bird_chat_box;
	delete bird_mom_chat_box;
	delete hunter_chat_box;
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
	knife->angle = 90;
	knife->speed = 1.5;
	knife->x = width + 100;
	knife->y = height / 2 + 40;
	bird_chat_box->scale = .8;
	bird_chat_box->x = width;
	bird_chat_box->y = height / 3;
	bird_mom_chat_box->scale = .8;
	bird_mom_chat_box->x = width;
	bird_mom_chat_box->y = height / 3 - 80;
	hunter_chat_box->scale = 1;
	hunter_chat_box->x = width;
	hunter_chat_box->y = height / 3 - 10;
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
	bird->speed = 1.2;
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
	cloud_1->moveleft();
	cloud_2->moveleft();

	//check animation state
	if (!isIntroOver && !isKnifeFly && !isMomBeenCut && !isMomFall)
	{
		story_telling_text = "One day... Little bird is flying togather with its mom...";
		if (cloud_1->x - 200 <= 0) {
			isKnifeFly = true;
		}
	}
	else if (!isIntroOver && isKnifeFly && !isMomBeenCut && !isMomFall)
	{
		story_telling_text = "Suddenly...";
		if (knife->x >= bird_mom->x + bird_mom->getScaledRadius() / 2) {
			knife->moveLeft((knife->x >= bird_mom->x + bird_mom->getScaledRadius() / 2 + 60) ? 1.5 : 0.2);
		}
		else {
			isMomBeenCut = true;
		}
	}
	else if (!isIntroOver && isKnifeFly && isMomBeenCut && !isMomFall)
	{
		story_telling_text = "";
		bird_chat_box->x = 450;
		bird_chat_text = "Mom!";
		if (bird_mom->y >= -100) {
			bird_mom->fall();
			knife->fall();
		}
		else {
			isMomFall = true;
			glFlush();
			changeScene();
			waitingCountDown[0] = 100;
		}
	}
	else if (!isIntroOver && isKnifeFly && isMomBeenCut && isMomFall) {
		bird_mom_chat_text = "HELP!";
		hunter_chat_text = "Dinner\\SETTLE~";

		if (bird->x <= 100 && waitingCountDown[0] > 0) {
			bird->moveRight((bird->x < 40) ? 2 : .8);
		}
		else if (waitingCountDown[0] > 0)
		{
			waitingCountDown[0] -= 1;
		}
		else
		{
			bird_chat_box->x = 130;
			bird_chat_text = "Let her\\  GO!";
			hunter_chat_text = "  NO\\WAY!!";
			tear->x = 126;

			if (tear->scale <= 1) {
				tear->y -= 0.06;
				tear->scale += 0.003;
			}
			else
			{
				if (tear->y > 0)
				{
					tear->drop(.8);
					waitingCountDown[1] = 240;
				}
				else
				{
					tear->x = width;
					bird_chat_box->x = width;
					hunter_chat_box->x = width;
					bird_mom_chat_box->x = width;

					if (bird->x <= width + 80 && waitingCountDown[1] > 0)
					{
						hunter->moveRight(1.6);
						cage->moveRight(1.8);
						bird_mom->moveRight(1.8);
						bird->moveRight((hunter->x >= width - 50) ? bird->speed : 0);
						bird->speed += .01;
					}
					else if (waitingCountDown[1] > 0)
					{
						waitingCountDown[1] -= 1;
					}
					else
					{
						isIntroOver = true;
					}
				}
			}
		}
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
	bird_chat_box->draw();
	glPopMatrix();

	//bird mom chatbox
	glPushMatrix();
	bird_mom_chat_box->draw();
	glPopMatrix();

	//hunter chatbox
	glPushMatrix();
	hunter_chat_box->draw();
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

	//draw texts
	glColor3f(Helper::hexToFloat(0), Helper::hexToFloat(0), Helper::hexToFloat(0));
	Helper::drawText(story_telling_text.data(), story_telling_text.length(), width / 2, height - 50, width, height);
	Helper::drawText(bird_chat_text.data(), bird_chat_text.length(), bird_chat_box->x + 56, bird_chat_box->y + 40, width, height);
	Helper::drawText(bird_mom_chat_text.data(), bird_mom_chat_text.length(), bird_mom_chat_box->x + 56, bird_mom_chat_box->y + 40, width, height);
	Helper::drawText(hunter_chat_text.data(), hunter_chat_text.length(), hunter_chat_box->x + 70, hunter_chat_box->y + 50, width, height);
}

void Intro::changeScene() {
	bird_chat_box->x = width;
	bird_chat_box->y = 170;
	bird_mom_chat_box->x = width - 100;
	hunter_chat_box->x = width / 2 + 100;
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