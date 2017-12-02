#include <Windows.h>
#include <GL/glut.h>
#include "Intro.h"
#include "Game.h"

const char* title = "Assignment 2";
const int width = 600;
const int height = 600;

void render();
void reshape(int newWidth, int newHeight);
void keyboardControl(unsigned char key, int x, int y);
void mouseControl(int button, int state, int x, int y);

Intro *intro = new Intro(width, height);
Game *game = new Game(width, height, false);
bool isIntroDelete = false;

void main(int argc, char** argv) {
	FreeConsole(); //hide console
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 50);
	glutCreateWindow(title);

	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardControl);
	glutMouseFunc(mouseControl);

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
		if (!intro->isIntroOver)
		{
			intro->render();
			intro->update();
		}
		else
		{
			delete intro;
			isIntroDelete = true;
		}
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

