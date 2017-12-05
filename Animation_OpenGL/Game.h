#ifndef GAME_H
#define GAME_H

#include "Object.h"
#include <GL/glut.h>
#include <string>

class Game
{
public:
	Game(int width, int height, bool devMode);
	void init();
	void update();
	void checkCollision();
	void render();
	void birdFly();
	void dropTear();

	bool isGameStart;
	bool isGameOver;
	bool isPause;

private:
	bool dev;
	int width, height;
	bool isLoading, isTearDrop;
	std::string title = "", desc = "";
	Obj::Mountain* mountain;
	Obj::Cloud* cloud_1;
	Obj::Cloud* cloud_2;
	Obj::Bird* bird;
	Obj::Tear* tear;
	Obj::Knife knifes[3];
	Obj::LoadingCover *cover;
};

#endif // !GAME_H
