#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "structures.h"
#include "Cube.h"

#define REFRESHRATE 16



class HelloGL
{
public:
	
	HelloGL(int argc, char* argv[]);

	void Display();

	~HelloGL(void);

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	//void drawCubeArray();




private:
	
	float rotation;

	float spinDirection = 1;
	
	static Vertex Verticies[];

	static Colour Colours[];

};

