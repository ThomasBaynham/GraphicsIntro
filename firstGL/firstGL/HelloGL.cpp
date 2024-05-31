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

//Cube* cube;
Cube* cube[200];

HelloGL::HelloGL(int argc, char* argv[]) 
{
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();

}

HelloGL::~HelloGL(void)
{

}

void HelloGL::InitGL(int argc, char* argv[])
{
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

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glutInitWindowSize(800, 800);
}

void HelloGL::InitObjects()
{
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 10.0f; camera->eye.z = 20.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	rotation = 0.0f;

	//Cube::Load((char*)"Objects/cube.txt");

	Mesh* cubeMesh = MeshLoader::Load((char*)"Objects/cube.txt");

	//cube = new Cube(0,0,0);

	for (int i = 0; i < 200; i++) {
		cube[i] = new Cube(cubeMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
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
	else if (key == 'r') {
		direction = direction * -1;
	}
	else if (key == 'q') {
		camera->eye.x += 5 * direction;
	}
	else if (key == 'w') {
		camera->eye.y += 5 * direction;
	}
	else if (key == 'e') {
		camera->eye.z += 5 * direction;
	}
	else if (key == 'a') {
		camera->center.x += 5 * direction;
	}
	else if (key == 's') {
		camera->center.y += 5 * direction;
	}
	else if (key == 'd') {
		camera->center.z += 5 * direction;
	}
	else if (key == 'z') {
		camera->up.x += 5 * direction;
	}
	else if (key == 'x') {
		camera->up.y += 5 * direction;
	}
	else if (key == 'c') {
		camera->up.z += 5 * direction;
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

