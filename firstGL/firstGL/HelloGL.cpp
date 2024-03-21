#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) 
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutCreateWindow("OPENPL WOOOOOOOOOOOOOO");
	glutDisplayFunc(GLUTCallbacks::Display);
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


void HelloGL::DrawScaline() {

	glBegin(GL_POLYGON); 
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-1, 0.8);
		glVertex2f(0.8, 0.9);
		glVertex2f(0.2, -0.9);
		glEnd();
	}

}

void HelloGL::DrawIsosceles()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0, 0.5);
		glVertex2f(-0.4, -0.7);
		glVertex2f(0.4, -0.7);
		glEnd();
	}
}

void HelloGL::DrawEqualatral()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0, -0.17);
		glVertex2f(-0.5, 0.7);
		glVertex2f(0.5, 0.7);
		glEnd();
	}
}

void HelloGL::DrawRight()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(0.5, 0);
		glVertex2f(0.5, 0.5);
		glVertex2f(0, 0.5);
		glEnd();
	}
}

void HelloGL::DrawObtuse()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.9, -0.5);
		glVertex2f(-0.8, -0.9);
		glVertex2f(0.3, -0.9);
		glEnd();
	}
}




