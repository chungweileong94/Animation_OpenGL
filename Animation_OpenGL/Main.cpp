#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"
#include "Object.h"
#include <string>
#include <queue>

using namespace std;

const char* title = "Assignment 2";
const int width = 600;
const int height = 600;

void render();
void reshape(int newWidth, int newHeight);

void gameplayRender();
void update();

Obj::Mountain* mountain = new Obj::Mountain();
Obj::Cloud* cloud_1 = new  Obj::Cloud();
Obj::Cloud* cloud_2 = new Obj::Cloud();
Obj::Bird* bird = new Obj::Bird();
Obj::Wood woods[5];

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
	cloud_1->y = height / 2 + 50;
	cloud_2->y = height / 2 + 150;
	cloud_2->color[0] = 255;
	cloud_2->color[1] = 127;
	cloud_2->color[2] = 39;
	cloud_2->speed += .01;
	bird->scale = .4;
	bird->x = 50;

	for each (Obj::Wood wood in woods)
	{
		wood.scale = .5;
	}

	glClearColor(Helper::hexToFloat(0), Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255));

}

void main(int argc, char** argv) {
	bird->y = height / 2;
	cloud_1->x = width / 2;
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

