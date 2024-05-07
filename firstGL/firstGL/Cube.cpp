#include "Cube.h"

#include <iostream>

Vertex Cube::indexedVerticies[] = { 1, 1, 1, -1, 1, 1, // v0,v1,
-1,-1, 1, 1,-1, 1, // v2,v3
1,-1,-1, 1, 1,-1, // v4,v5
-1, 1,-1, -1,-1,-1 }; // v6,v7

Colour Cube::indexedColours[] = { 1, 1, 1, 1, 1, 0, // v0,v1,
1, 0, 0, 1, 0, 1, // v2,v3
0, 0, 1, 0, 1, 1, // v4,v5
0, 1, 0, 0, 0, 0 }; //v6,v7

GLushort Cube::indicies[] = { 0, 1, 2, 2, 3, 0, // front
0, 3, 4, 4, 5, 0, // right
0, 5, 6, 6, 1, 0, // top
1, 6, 7, 7, 2, 1, // left
7, 4, 3, 3, 2, 7, // bottom
4, 7, 6, 6, 5, 4 }; // back

Cube::Cube(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0;
}

Cube::~Cube()
{

}

void Cube::Draw()
{
	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);

	glRotatef(_rotation, 0.5f, 1.0f, 0.2f);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++) {

		glColor3f(indexedColours[indicies[i]].r, indexedColours[indicies[i]].g, indexedColours[indicies[i]].b);
		glVertex3f(indexedVerticies[indicies[i]].x, indexedVerticies[indicies[i]].y, indexedVerticies[indicies[i]].z);


	}
	glEnd();

	glPopMatrix();
}

void Cube::Update()
{
	if (_rotation > 360) {
		_rotation = 0;
	}
	else {

		_rotation += 4.0f;
	}

	//std::cout << _rotation << "\n";
}
