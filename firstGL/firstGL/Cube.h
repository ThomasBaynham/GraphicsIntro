#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "structures.h"

class Cube
{
private:
	static Vertex indexedVerticies[];
	static Colour indexedColours[];
	static GLushort indicies[];

	Vector3 _position;
	GLfloat _rotation;

	Vector3 rotations;

public:
	Cube(float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

