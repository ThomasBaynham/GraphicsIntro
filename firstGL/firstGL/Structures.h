#pragma once
#include "Windows.h"
#include "gl/GL.h"

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