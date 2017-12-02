#ifndef INTRO_H
#define INTRO_H

#include "Object.h"
#include <GL/glut.h>
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
	void drawText(const char *text, GLint length, GLfloat x, GLfloat y);

	int width, height;
	Obj::Cloud* cloud_1;
	Obj::Cloud* cloud_2;
	Obj::Bird* bird;
	Obj::Bird* bird_mom;
	Obj::Knife* knife;
	Obj::Chatbox* birdchatbox;
	Obj::Chatbox* bird_momchatbox;
	Obj::Chatbox* hunterchatbox;
	Obj::Tear* tear;
	Obj::Cage* cage;
	Obj::Hunter* hunter;
	Obj::Mountain* mountain;
};

#endif // !INTRO_H
