#pragma once
#include "Windows.h"
#include "gl/GL.h"
#include "gl/GLU.h"
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"


class HelloGL
{
public:
	
	HelloGL(int argc, char* argv[]);

	void Display();

	~HelloGL(void);

	void DrawScaline();

	void DrawIsosceles();

	void DrawEqualatral();

	void DrawAcute();

	void DrawRight();

	void DrawObtuse();


};

