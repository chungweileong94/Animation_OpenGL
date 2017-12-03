#include <Windows.h>
#include <GL/glut.h>
#include <string>
#include "Intro.h"
#include "Game.h"

const char* title = "Assignment 2";
const int width = 600;
const int height = 600;

void render();
void update(int value);
void reshape(int newWidth, int newHeight);
void keyboardControl(unsigned char key, int x, int y);
void mouseControl(int button, int state, int x, int y);

Intro *intro;
Game *game;
bool isDevMode = false;
bool isIntroDelete = false;

void main(int argc, char** argv) {
	for (int c = 1; c < argc; c++)
	{
		std::string arg = argv[c];
		if (arg == "d")
		{
			isDevMode = true;
		}
		if (arg == "s")
		{
			isIntroDelete = true;
		}
	}

	FreeConsole(); //hide console
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 50);
	glutCreateWindow(title);

	glutDisplayFunc(render);
	glutTimerFunc(5, update, 0);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardControl);
	glutMouseFunc(mouseControl);

	intro = new Intro(width, height);
	game = new Game(width, height, isDevMode);
	intro->init();
	game->init();

	glutMainLoop();
}

void render()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	glClear(GL_COLOR_BUFFER_BIT);

	if (!isIntroDelete)
	{
		intro->render();
	}
	else
	{
		game->render();
		game->update();
		game->checkCollision();
	}

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void update(int value)
{
	if (!isIntroDelete)
	{
		if (!intro->isIntroOver)
		{
			intro->update();
			glutTimerFunc(6, update, 0);
		}
		else
		{
			delete intro;
			isIntroDelete = true;
		}
	}
}

void reshape(int newWidth, int newHeight)
{
	if (newWidth != width || newHeight != height)
	{
		glutReshapeWindow(width, height);
	}
}

void keyboardControl(unsigned char key, int x, int y) {
	switch (key)
	{
	case 13:
		if (game->isGameOver)
		{
			game->init();
		}
		break;

	case ' ':
		if (isIntroDelete) game->birdFly();
		break;
	}
}

void mouseControl(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (isIntroDelete) game->birdFly();
	}
}

