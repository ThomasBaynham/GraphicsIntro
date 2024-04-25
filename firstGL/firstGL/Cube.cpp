#include "Cube.h"

Cube::Cube()
{

}

Cube::~Cube()
{

}

void Cube::Draw()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++) {

		glColor3f(Colours[i].r, Colours[i].g, Colours[i].b);
		glVertex3f(Verticies[i].x, Verticies[i].y, Verticies[i].z);
	}
	glEnd();

	glPopMatrix();
}

void Cube::Update()
{

}
