#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include"GL\freeglut.h"
#include "Structure.h"

class Cube
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;

	static int numVertices, numColors, numIndices;

	GLfloat rotation;

	Vector3 position;

public:
	Cube(float x, float y, float z);
	~Cube();

	void Draw();
	void Update();

	static bool Load(char* path);
};

