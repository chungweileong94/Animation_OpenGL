#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"
#include "Object.h"
#include <string>

using namespace std;

const char* title = "Assignment 2";
const int width = 600;
const int height = 600;

void render();
void reshape(int newWidth, int newHeight);

void gameplayRender();
void update();

Obj::Mountain* mountain = new Obj::Mountain();
Obj::Cloud* cloud = new  Obj::Cloud();
Obj::Bird* bird = new Obj::Bird();

void keyboardControl(unsigned char key, GLint x, GLint y) {
	switch (key) {
	case ' ':
		bird->fly();
		break;
	}
}

void mouseControl(GLint button, GLint state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		bird->fly();
	}
}

void init() {
	cloud->y = height / 2 + 50;
	bird->scale = .5;
	bird->x = 50;
	bird->heightLimit = height - 200;

	glClearColor(Helper::hexToFloat(0), Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255));
}

void main(int argc, char** argv) {
	bird->y = height / 2;
	cloud->x = width / 2;
	//FreeConsole(); //hide console
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
	printf("%f\n", bird->velocity);

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

void gameplayRender()
{
	//mountain
	glPushMatrix();
	glTranslated(mountain->x, mountain->y, 0);
	mountain->draw();
	glPopMatrix();

	//cloud
	glPushMatrix();
	glTranslated(cloud->x, cloud->y, 0);
	cloud->draw();
	glPopMatrix();

	//bird
	glPushMatrix();
	glTranslatef(bird->x, bird->y, 0);
	bird->draw();
	glPopMatrix();
}

void drawText(const char *text, GLint length, GLint x, GLint y) {
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)text[i]);
	}
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void update() {
	//background
	if (cloud->x <= -200) {
		cloud->x = width + 10;
	}
	if (mountain->x <= -860) {
		mountain->x = width;
	}
	cloud->x -= cloud->speed;
	mountain->x -= mountain->speed;

	//bird
	if (bird->y <= -100) {
		glColor3f(1.0f, 0.0f, 0.0f);
		string text;
		text = "GAME OVER";
		drawText(text.data(), text.size(), width / 2, height / 2);
	}
	else {
		bird->drop();
	}
}

