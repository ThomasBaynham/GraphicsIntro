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


	DrawIsosceles();
	glFlush();



}

HelloGL::~HelloGL(void)
{

}


void HelloGL::DrawScaline() {

	glBegin(GL_POLYGON); 
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.75, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.6, -0.3);
		glEnd();
	}

}

void HelloGL::DrawIsosceles()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(0, 0.5);
		glVertex2f(-0.4, -0.5);
		glVertex2f(0.4, -0.5);
		glEnd();
	}
}

void HelloGL::DrawEqualatral()
{

}

void HelloGL::DrawAcute()
{

}

void HelloGL::DrawRight()
{

}

void HelloGL::DrawObtuse()
{

}




