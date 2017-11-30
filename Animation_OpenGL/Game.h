#ifndef GAME_H
#define GAME_H

#include "Object.h"
#include <GL/glut.h>

class Game
{
public:
	Game(int width, int height);
	void init();
	void update();
	void render();
	void birdFly();

	bool isGameStart;
	bool isGameOver;

private:
	void drawText(const char *text, GLint length, GLfloat x, GLfloat y);

	int width, height;
	Obj::Mountain* mountain;
	Obj::Cloud* cloud_1;
	Obj::Cloud* cloud_2;
	Obj::Bird* bird;
	Obj::Wood woods[5];
};

#endif // !GAME_H
