#ifndef INTRO_H
#define INTRO_H

#include "Object.h"
#include <GL/glut.h>
#include <string>
#include "Game.h"

class Intro
{
public:
	Intro(int width, int height);
	~Intro();
	void init();
	void update();
	void render();
	void changeScene();

	bool isIntroOver;
	bool isKnifeFly;
	bool isMomBeenCut;
	bool isMomFall;

private:
	int width, height;
	int waitingCountDown[2];
	std::string story_telling_text;
	std::string bird_chat_text;
	std::string bird_mom_chat_text;
	std::string hunter_chat_text;
	Obj::Cloud* cloud_1;
	Obj::Cloud* cloud_2;
	Obj::Bird* bird;
	Obj::Bird* bird_mom;
	Obj::Knife* knife;
	Obj::Chatbox* bird_chat_box;
	Obj::Chatbox* bird_mom_chat_box;
	Obj::Chatbox* hunter_chat_box;
	Obj::Tear* tear;
	Obj::Cage* cage;
	Obj::Hunter* hunter;
	Obj::Mountain* mountain;
};

#endif // !INTRO_H
