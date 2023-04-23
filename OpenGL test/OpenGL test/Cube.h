#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include"GL\freeglut.h"
#include "Structure.h"

class Cube
{
private:
	GLfloat rotation;

	Vector3 position;

public:
	Cube(Mesh* mesh,float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

