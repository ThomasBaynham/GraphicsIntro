#include "HelloGL.h"
#include <iostream>


HelloGL::HelloGL(int argc, char* argv[]) 
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutCreateWindow("OPENPL WOOOOOOOOOOOOOO");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop();
	glutInitWindowSize(800,800);
}

void HelloGL::Display() 
{
	glClear(GL_COLOR_BUFFER_BIT);

	DrawScaline();
	DrawIsosceles();
	DrawEqualatral();
	DrawRight();
	DrawObtuse();

	glFlush();


}

HelloGL::~HelloGL(void)
{

}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void HelloGL::Update()
{
	glutPostRedisplay();
	rotation += 0.5f;
	if (rotation >= 360.0f) {
		rotation = 0.0f;
	}

}


void HelloGL::DrawScaline() {

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);

	glBegin(GL_POLYGON); 
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-1, 0.8);
		glVertex2f(0.8, 0.9);
		glVertex2f(0.2, -0.9);
		glEnd();
	}

	glPopMatrix();

}

void HelloGL::DrawIsosceles()
{
	glPushMatrix();
	glRotatef(rotation, 30.0f, 0.0f, 2.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0, 0.5);
		glVertex2f(-0.4, -0.7);
		glVertex2f(0.4, -0.7);
		glEnd();
	}

	glPopMatrix();
}

void HelloGL::DrawEqualatral()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0, -0.17);
		glVertex2f(-0.5, 0.7);
		glVertex2f(0.5, 0.7);
		glEnd();
	}
	glPopMatrix();
}

void HelloGL::DrawRight()
{
	glPushMatrix();
	glRotatef(rotation, 2.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(0.5, 0);
		glVertex2f(0.5, 0.5);
		glVertex2f(0, 0.5);
		glEnd();
	}
	glPopMatrix();
}

void HelloGL::DrawObtuse()
{
	glPushMatrix();
	glRotatef(rotation, 2.0f, 3.0f, 1.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.9, -0.5);
		glVertex2f(-0.8, -0.9);
		glVertex2f(0.3, -0.9);
		glEnd();
	}
	glPopMatrix();
}




