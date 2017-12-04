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

	bool isIntroOver;

private:
	void scene_2_init();
	void scene_1_update();
	void scene_2_update();

	int width, height;
	int waitingCountDown;
	bool isLoading;
	bool scene_1_parts[3] = { false, false, false };
	bool scene_2_parts[3] = { false, false, false };
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
	Obj::LoadingCover* cover;
};

#endif // !INTRO_H
