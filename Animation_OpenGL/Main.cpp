#include <Windows.h>
#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"
#include "Object.h"
#include <string>
#include <queue>

using namespace std;

bool dev = false; //dev mode

const char* title = "Assignment 2";
const int width = 600;
const int height = 600;
bool isGameStart;
bool isGameOver;

void render();
void reshape(int newWidth, int newHeight);

void init();
void gameplayRender();
void update();

Obj::Mountain* mountain = new Obj::Mountain();
Obj::Cloud* cloud_1 = new  Obj::Cloud();
Obj::Cloud* cloud_2 = new Obj::Cloud();
Obj::Bird* bird = new Obj::Bird();
Obj::Wood woods[5];

void keyboardControl(unsigned char key, int x, int y) {
	switch (key)
	{
	case 13:
		if (isGameOver)
		{
			isGameOver = false;
			init();
		}
		break;

	case ' ':
		if (isGameStart)
			bird->fly();
		else
			isGameStart = true;
		break;
	}
}

void mouseControl(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (isGameStart)
			bird->fly();
		else
			isGameStart = true;
	}
}

void main(int argc, char** argv) {
	if (!dev) FreeConsole(); //hide console
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 50);
	glutCreateWindow(title);

	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardControl);
	glutMouseFunc(mouseControl);

	init();

	glutMainLoop();
}

void render()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	glClear(GL_COLOR_BUFFER_BIT);

	gameplayRender();
	update();

	//dev stat
	if (dev)
	{
		printf("Velocity %f\n", bird->velocity);
		printf("Is Game Start %d\n", isGameStart);
		printf("Is Game Over %d\n", isGameOver);
		printf("=============================\n");
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

void init() {
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
	bird->x = 50;
	bird->y = height / 2;
	bird->velocity = 0;

	for each (Obj::Wood wood in woods)
	{
		wood.scale = .5;
	}

	glClearColor(Helper::hexToFloat(0), Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255));
}

void gameplayRender()
{
	//mountain
	glPushMatrix();
	glTranslated(mountain->x, mountain->y, 0);
	mountain->draw();
	glPopMatrix();

	//cloud 1
	glPushMatrix();
	glTranslated(cloud_1->x, cloud_1->y, 0);
	cloud_1->draw();
	glPopMatrix();

	//cloud 2
	glPushMatrix();
	glTranslated(cloud_2->x, cloud_2->y, 0);
	cloud_2->draw();
	glPopMatrix();

	//bird
	glPushMatrix();
	glTranslatef(bird->x, bird->y, 0);
	bird->draw();
	glPopMatrix();
}

void drawText(const char *text, GLint length, GLfloat x, GLfloat y) {
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

void update() {
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
		string title = "Tap 'Spacebar' or 'Left-click' to start";
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
		}
	}
	else
	{
		glColor3f(Helper::hexToFloat(255), Helper::hexToFloat(50), Helper::hexToFloat(0));
		string title = "GAME OVER";
		drawText(title.data(), title.length(), width / 2, height / 2);
		string desc = "Press 'Enter' to retry again";
		drawText(desc.data(), desc.length(), width / 2, height / 2 - 28);
	}
}

