#include "HelloGL.h"
#include <iostream>

#include "Cube.h"

Vertex HelloGL::Verticies[] = { 1, 1, 1, -1, 1, 1, -1,-1, 1, // v0-v1-v2 (front)
-1,-1, 1, 1,-1, 1, 1, 1, 1, // v2-v3-v0
1, 1, 1, 1,-1, 1, 1,-1,-1, // v0-v3-v4 (right)
1,-1,-1, 1, 1,-1, 1, 1, 1, // v4-v5-v0
1, 1, 1, 1, 1,-1, -1, 1,-1, // v0-v5-v6 (top)
-1, 1,-1, -1, 1, 1, 1, 1, 1, // v6-v1-v0
-1, 1, 1, -1, 1,-1, -1,-1,-1, // v1-v6-v7 (left)
-1,-1,-1, -1,-1, 1, -1, 1, 1, // v7-v2-v1
-1,-1,-1, 1,-1,-1, 1,-1, 1, // v7-v4-v3 (bottom)
1,-1, 1, -1,-1, 1, -1,-1,-1, // v3-v2-v7
1,-1,-1, -1,-1,-1, -1, 1,-1, // v4-v7-v6 (back)
-1, 1,-1, 1, 1,-1, 1,-1,-1 }; // v6-v5-v4

Colour HelloGL::Colours[] = { 1, 1, 1, 1, 1, 0, 1, 0, 0, // v0-v1-v2 (front)
1, 0, 0, 1, 0, 1, 1, 1, 1, // v2-v3-v0
1, 1, 1, 1, 0, 1, 0, 0, 1, // v0-v3-v4 (right)
0, 0, 1, 0, 1, 1, 1, 1, 1, // v4-v5-v0
1, 1, 1, 0, 1, 1, 0, 1, 0, // v0-v5-v6 (top)
0, 1, 0, 1, 1, 0, 1, 1, 1, // v6-v1-v0
1, 1, 0, 0, 1, 0, 0, 0, 0, // v1-v6-v7 (left)
0, 0, 0, 1, 0, 0, 1, 1, 0, // v7-v2-v1
0, 0, 0, 0, 0, 1, 1, 0, 1, // v7-v4-v3 (bottom)
1, 0, 1, 1, 0, 0, 0, 0, 0, // v3-v2-v7
0, 0, 1, 0, 0, 0, 0, 1, 0, // v4-v7-v6 (back)
0, 1, 0, 0, 1, 1, 0, 0, 1 }; // v6-v5-v4

Camera* camera;

Cube* cube[200];

HelloGL::HelloGL(int argc, char* argv[]) 
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CUBE GAMING");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glEnable(GL_DEPTH_TEST);

	glutKeyboardFunc(GLUTCallbacks::keyboard);

	camera = new Camera();
	camera->eye.x = -10.0f; camera->eye.y = 50.0f; camera->eye.z = 20.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	//cube = new Cube(1,2,0);

	
	for (int i = 0; i < 200; i++) {
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}



	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 1, 1000 ); 

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glutMainLoop();
	glutInitWindowSize(800,800);
}

void HelloGL::Display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	//cube->Draw();

	for (int i = 0; i < 200; i++) {
		cube[i]->Draw();
	}


	//drawCubeArray();
	//DrawScaline();
	//DrawIsosceles();
	//DrawEqualatral();
	//DrawRight();
	//DrawObtuse();
	//DrawShape();

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

	//cube->Update();

	for (int i = 0; i < 200; i++) {
		cube[i]->Update();
	}

	Sleep(10);

}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd') {
		spinDirection = spinDirection * -1;
	}
	else if (key == 'f') {
		camera->eye.y += 0.1;
	}
}

//void HelloGL::drawCubeArray()
//{
//	glPushMatrix();
//
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i < 36; i++) {
//
//		glColor3f(Colours[i].r, Colours[i].g, Colours[i].b);
//		glVertex3f(Verticies[i].x, Verticies[i].y, Verticies[i].z);
//	}
//	glEnd();
//
//	glPopMatrix();
//}
//
//void HelloGL::drawCube()
//{
//	
//	glBegin(GL_TRIANGLES);
//	{
//		// face v0-v1-v2
//		glColor3f(1, 1, 1);
//		glVertex3f(1, 1, 1);
//		glColor3f(1, 1, 0);
//		glVertex3f(-1, 1, 1);
//		glColor3f(1, 0, 0);
//		glVertex3f(-1, -1, 1);
//
//		// face v2-v3-v0
//		glColor3f(1, 0, 0);
//		glVertex3f(-1, -1, 1);
//		glColor3f(1, 0, 1);
//		glVertex3f(1, -1, 1);
//		glColor3f(1, 1, 1);
//		glVertex3f(1, 1, 1);
//
//		// face v0-v3-v4
//		glColor3f(1, 1, 1);
//		glVertex3f(1, 1, 1);
//		glColor3f(1, 0, 1);
//		glVertex3f(1, -1, 1);
//		glColor3f(0, 0, 1);
//		glVertex3f(1, -1, -1);
//
//		// face v4-v5-v0
//		glColor3f(0, 0, 1);
//		glVertex3f(1, -1, -1);
//		glColor3f(0, 1, 1);
//		glVertex3f(1, 1, -1);
//		glColor3f(1, 1, 1);
//		glVertex3f(1, 1, 1);
//
//		// face v0-v5-v6
//		glColor3f(1, 1, 1);
//		glVertex3f(1, 1, 1);
//		glColor3f(0, 1, 1);
//		glVertex3f(1, 1, -1);
//		glColor3f(0, 1, 0);
//		glVertex3f(-1, 1, -1);
//
//		// face v6-v1-v0
//		glColor3f(0, 1, 0);
//		glVertex3f(-1, 1, -1);
//		glColor3f(1, 1, 0);
//		glVertex3f(-1, 1, 1);
//		glColor3f(1, 1, 1);
//		glVertex3f(1, 1, 1);
//
//		// face v1-v6-v7
//		glColor3f(1, 1, 0);
//		glVertex3f(-1, 1, 1);
//		glColor3f(0, 1, 0);
//		glVertex3f(-1, 1, -1);
//		glColor3f(0, 0, 0);
//		glVertex3f(-1, -1, -1);
//
//		// face v7-v2-v1
//		glColor3f(0, 0, 0);
//		glVertex3f(-1, -1, -1);
//		glColor3f(1, 0, 0);
//		glVertex3f(-1, -1, 1);
//		glColor3f(1, 1, 0);
//		glVertex3f(-1, 1, 1);
//
//		// face v7-v4-v3
//		glColor3f(0, 0, 0);
//		glVertex3f(-1, -1, -1);
//		glColor3f(0, 0, 1);
//		glVertex3f(1, -1, -1);
//		glColor3f(1, 0, 1);
//		glVertex3f(1, -1, 1);
//
//		// face v3-v2-v7
//		glColor3f(1, 0, 1);
//		glVertex3f(1, -1, 1);
//		glColor3f(1, 0, 0);
//		glVertex3f(-1, -1, 1);
//		glColor3f(0, 0, 0);
//		glVertex3f(-1, -1, -1);
//
//		// face v4-v7-v6
//		glColor3f(0, 0, 1);
//		glVertex3f(1, -1, -1);
//		glColor3f(0, 0, 0);
//		glVertex3f(-1, -1, -1);
//		glColor3f(0, 1, 0);
//		glVertex3f(-1, 1, -1);
//
//		// face v6-v5-v4
//		glColor3f(0, 1, 0);
//		glVertex3f(-1, 1, -1);
//		glColor3f(0, 1, 1);
//		glVertex3f(1, 1, -1);
//		glColor3f(0, 0, 1);
//		glVertex3f(1, -1, -1);
//
//		glEnd();
//	}
//
//}

//void HelloGL::DrawShape() {
//	glPushMatrix();
//
//	glRotatef(rotation, 0.3f, 0.1f, 0.2f);
//	glutWireCube(1);
//
//	glPopMatrix();
//}

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




