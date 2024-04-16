#include "HelloGL.h"
#include <iostream>

Camera* camera;

HelloGL::HelloGL(int argc, char* argv[]) 
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OPENPL WOOOOOOOOOOOOOO");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glutKeyboardFunc(GLUTCallbacks::keyboard);

	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 100 );
	glutMainLoop();
	glutInitWindowSize(800,800);
}

void HelloGL::Display() 
{
	glClear(GL_COLOR_BUFFER_BIT);

	/*DrawScaline();
	DrawIsosceles();
	DrawEqualatral();
	DrawRight();
	DrawObtuse();*/
	DrawShape();

	glFlush();
	glutSwapBuffers();

}

HelloGL::~HelloGL(void)
{

}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
	rotation += spinDirection;
	if (rotation > 360.0f) {
		rotation = 0.0f;
	}
	else if (rotation < 0) {
		rotation = 360.0f;
	}
	//camera->eye.z++;

	Sleep(10);

}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd') {
		spinDirection = spinDirection * -1;
	}

}

void HelloGL::DrawShape() {
	glPushMatrix();

	glRotatef(rotation, 0.3f, 0.1f, 0.2f);
	glutWireCube(1);

	glPopMatrix();
}

//void HelloGL::DrawScaline() {
//
//	glPushMatrix();
//	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
//
//	glBegin(GL_POLYGON); 
//	{
//		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
//		glVertex2f(-1, 0.8);
//		glVertex2f(0.8, 0.9);
//		glVertex2f(0.2, -0.9);
//		glEnd();
//	}
//
//	glPopMatrix();
//
//}
//
//void HelloGL::DrawIsosceles()
//{
//	glPushMatrix();
//	glRotatef(rotation, 30.0f, 0.0f, 2.0f);
//
//	glBegin(GL_POLYGON);
//	{
//		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
//		glVertex2f(0, 0.5);
//		glVertex2f(-0.4, -0.7);
//		glVertex2f(0.4, -0.7);
//		glEnd();
//	}
//
//	glPopMatrix();
//}
//
//void HelloGL::DrawEqualatral()
//{
//	glPushMatrix();
//	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
//
//	glBegin(GL_POLYGON);
//	{
//		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
//		glVertex2f(0, -0.17);
//		glVertex2f(-0.5, 0.7);
//		glVertex2f(0.5, 0.7);
//		glEnd();
//	}
//	glPopMatrix();
//}
//
//void HelloGL::DrawRight()
//{
//	glPushMatrix();
//	glRotatef(rotation, 2.0f, 0.0f, 1.0f);
//
//	glBegin(GL_POLYGON);
//	{
//		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
//		glVertex2f(0.5, 0);
//		glVertex2f(0.5, 0.5);
//		glVertex2f(0, 0.5);
//		glEnd();
//	}
//	glPopMatrix();
//}
//
//void HelloGL::DrawObtuse()
//{
//	glPushMatrix();
//	glRotatef(rotation, 2.0f, 3.0f, 1.0f);
//
//	glBegin(GL_POLYGON);
//	{
//		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
//		glVertex2f(-0.9, -0.5);
//		glVertex2f(-0.8, -0.9);
//		glVertex2f(0.3, -0.9);
//		glEnd();
//	}
//	glPopMatrix();
//}




