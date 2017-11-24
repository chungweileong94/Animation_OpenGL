#include <GL/glut.h>
#include "Geometry.h"
#include "Helper.h"
#include "Object.h"

const char* title = "Assignment 2";
const int width = 600;
const int height = 600;
//const int width = 1000;
//const int height = 600;

void render();
void reshape(int newWidth, int newHeight);

void gameplayRender();

void main(int argc, char** argv) {
	FreeConsole(); //hide console
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 50);
	glutCreateWindow(title);

	glutDisplayFunc(render);
	glutReshapeFunc(reshape);

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

	glFlush();
	glutSwapBuffers();
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
	Obj::Bird bird = Obj::Bird();
	bird.scale = .5;
	bird.y = height / 2;

	glTranslatef(bird.x, bird.y, 0);
	bird.draw();
	glPopMatrix();
}
