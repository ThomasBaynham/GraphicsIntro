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

//Vertex* Cube::indexedVerticies = nullptr;
//Colour* Cube::indexedColours = nullptr;
//GLushort* Cube::indicies = nullptr;

int Cube::numVertices = 0;
int Cube::numColours = 0;
int Cube::numIndecies = 0;




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

	glRotatef(_rotation, rotations.x, rotations.y, rotations.z);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++) {

		glColor3f(_mesh->Colours[i].r, _mesh->Colours[i].g, _mesh->Colours[i].b);
		glVertex3f(_mesh->Vertices[i].x, _mesh->Vertices[i].y, _mesh->Vertices[i].z);
	
		//glColor3f(indexedColours[indicies[i]].r, indexedColours[indicies[i]].g, indexedColours[indicies[i]].b);
		//glVertex3f(indexedVerticies[indicies[i]].x, indexedVerticies[indicies[i]].y, indexedVerticies[indicies[i]].z);

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

		_rotation += 10.0f;
	}

	
}

//bool Cube::Load(char* path)
//{
//	std::ifstream inFile;
//	inFile.open(path);
//	if (!inFile.good()) {
//		std::cerr << "Cant open text file" << path << "\n";
//		return false;
//	}
//
//	inFile >> numVertices;
//	indexedVerticies = new Vertex[numVertices];
//	for (int i = 0; i < numVertices; i++) {
//
//		inFile >> indexedVerticies[i].x;
//		inFile >> indexedVerticies[i].y;
//		inFile >> indexedVerticies[i].z;
//		
//	}
//	inFile >> numColours;
//	indexedColours = new Colour[numColours];
//	for (int i = 0; i < numColours; i++) {
//
//		inFile >> indexedColours[i].r;
//		inFile >> indexedColours[i].g;
//		inFile >> indexedColours[i].b;
//
//	}
//	inFile >> numIndecies;
//	indicies = new GLushort[numIndecies];
//	for (int i = 0; i < numIndecies; i++) {
//		inFile >> indicies[i];
//	}
//
//	inFile.close();
//
//	return true;
//}
