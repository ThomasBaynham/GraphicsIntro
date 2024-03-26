#pragma once
#include "Windows.h"
#include "gl/GL.h"
#include "gl/GLU.h"
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16


class HelloGL
{
public:
	
	HelloGL(int argc, char* argv[]);

	void Display();

	~HelloGL(void);

	void Update();

	void DrawScaline();

	void DrawIsosceles();

	void DrawEqualatral();

	void DrawRight();

	void DrawObtuse();

private:
	float rotation;

};

