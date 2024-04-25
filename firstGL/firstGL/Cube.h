#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "structures.h"

class Cube
{
private:
	static Vertex Verticies[];
	static Colour Colours[];
	static GLushort indicies[];

public:
	Cube();
	~Cube();

	void Draw();
	void Update();
};

