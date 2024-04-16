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



class HelloGL
{
public:
	
	HelloGL(int argc, char* argv[]);

	void Display();

	~HelloGL(void);

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void DrawShape();

	void DrawScaline();/*

	void DrawIsosceles();

	void DrawEqualatral();

	void DrawRight();

	void DrawObtuse();*/


private:
	
	float rotation;

	float spinDirection = 1;

};

