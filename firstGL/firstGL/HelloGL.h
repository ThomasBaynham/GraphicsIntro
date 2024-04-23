#pragma once
#include "Windows.h"
#include "gl/GL.h"
#include "gl/GLU.h"
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

struct Vector3 {
	float x, y, z;
};

struct Camera {
	Vector3 eye, center, up;
};

struct Colour {
	GLfloat r, g, b;
};

struct Vertex {
	GLfloat x, y, z;
};

class HelloGL
{
public:
	
	HelloGL(int argc, char* argv[]);

	void Display();

	~HelloGL(void);

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void drawCubeArray();

	void drawCube();

	//void DrawShape();

	//void DrawScaline();

	//void DrawIsosceles();

	//void DrawEqualatral();

	//void DrawRight();

	//void DrawObtuse();


private:
	
	float rotation;

	float spinDirection = 1;
	
	static Vertex Verticies[];

	static Colour Colours[];
fff
};

