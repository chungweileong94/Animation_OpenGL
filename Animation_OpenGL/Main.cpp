#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"
#include "Object.h"
#include <string>

using namespace std;

const char* title = "Assignment 2";
const int width = 600;
const int height = 600;
const float dropSpeed = (float)0.8;
const float flySpeed = (float)150;
//const int width = 1000;
//const int height = 600;

void render();
void reshape(int newWidth, int newHeight);

void gameplayRender();
void birdDrop();
Obj::Bird bird = Obj::Bird();

void keyboardControl(unsigned char key, GLint x, GLint y) {
	switch (key) {
	case ' ': 
		bird.y += flySpeed;
		glTranslatef(bird.x, bird.y, 0);
		//bird.draw();
	break;
	}
	glutPostRedisplay();
}


void main(int argc, char** argv) {
	bird.y = height / 2;
	FreeConsole(); //hide console
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 50);
	glutCreateWindow(title);

	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardControl);

	//temp background color
	glClearColor(Helper::hexToFloat(0), Helper::hexToFloat(255), Helper::hexToFloat(255), Helper::hexToFloat(255));

	glutMainLoop();
}

void render()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	glClear(GL_COLOR_BUFFER_BIT);

	//test draw
	gameplayRender();
	birdDrop();
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
	Obj::Mountain().draw();
	glPopMatrix();

	//cloud
	glPushMatrix();
	Obj::Cloud cloud = Obj::Cloud();
	cloud.y = height / 2 + 50;
	cloud.x = width / 2;

	glTranslated(cloud.x, cloud.y, 0);
	Obj::Cloud().draw();
	glPopMatrix();

	//bird
	glPushMatrix();
	bird.scale = .5;
	//bird.y = height / 2;
	glTranslatef(bird.x, bird.y, 0);
	bird.draw();
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
	for (int i = 0; i<length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)text[i]);
	}
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}


void birdDrop() {
	if (bird.y <= -100) {
		//bird.y = height / 2;
		glColor3f(1.0f, 0.0f, 0.0f);
		string text;
		text = "GAME OVER";
		drawText(text.data(), text.size(), width/2, height/2);

	}
	else {
		bird.y -= dropSpeed;
	}
}

