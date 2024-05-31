#include "Cube.h"
#include <iostream>
#include <fstream>

//Vertex Cube::indexedVerticies[] = { 1, 1, 1, -1, 1, 1, // v0,v1,
//-1,-1, 1, 1,-1, 1, // v2,v3
//1,-1,-1, 1, 1,-1, // v4,v5
//-1, 1,-1, -1,-1,-1 }; // v6,v7
//
//Colour Cube::indexedColours[] = { 1, 1, 1, 1, 1, 0, // v0,v1,
//1, 0, 0, 1, 0, 1, // v2,v3
//0, 0, 1, 0, 1, 1, // v4,v5
//0, 1, 0, 0, 0, 0 }; //v6,v7
//
//GLushort Cube::indicies[] = { 0, 1, 2, 2, 3, 0, // front
//0, 3, 4, 4, 5, 0, // right
//0, 5, 6, 6, 1, 0, // top
//1, 6, 7, 7, 2, 1, // left
//7, 4, 3, 3, 2, 7, // bottom
//4, 7, 6, 6, 5, 4 }; // back






Cube::Cube(Mesh* mesh, float x, float y, float z)
{

	_mesh = mesh;
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0;

	rotations.x = ((float)rand() / RAND_MAX) * 2 - 1;
	rotations.y = ((float)rand() / RAND_MAX) * 2 - 1;
	rotations.z = ((float)rand() / RAND_MAX) * 2 - 1;

	//std::cout << rotations.x << " " << rotations.y << " " << rotations.z << "\n";
}

Cube::~Cube()
{

}


void Cube::Draw()
{
	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glRotatef(_rotation, 0.0f, 1.0f, 0.5f);
	if (_mesh->Vertices != nullptr) { glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices); }
	if (_mesh->Colours != nullptr) { glColorPointer(3, GL_FLOAT, 0, _mesh->Colours); }
	if (_mesh->Indecies != nullptr) { glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indecies); }

	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Cube::Update()
{
	if (_rotation > 360) {
		_rotation = 0;
	}
	else {

		_rotation += 10.0f;
	}

	//std::cout << _rotation << "\n";
	
}


