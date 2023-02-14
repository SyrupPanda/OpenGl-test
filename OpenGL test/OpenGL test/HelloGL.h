#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallBacks.h"

class HelloGL
{
public:

	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();

	void DrawPolygon();
	void DrawTriangle();
};

