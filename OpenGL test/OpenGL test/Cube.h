#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include"GL\freeglut.h"
#include "Structure.h"

class Cube
{
private:
	static Vertex indexedVertices[];
	static Color indexedXolors[];
	static GLushort indices[];

public:
	Cube();
	~Cube();

	void Draw();
	void Update();
};

