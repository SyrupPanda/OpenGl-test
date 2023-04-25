#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallBacks.h"
#include "Structure.h"
#include "Objects.h"
#include "SceneObject.h"
#include "Pyramid.h"
#include "Cube.h"
#define REFRESHRATE 16

class HelloGL
{
public:

	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void InitObjects();
	void InitGL(int argc, char* argv[]);

private:

	Camera* camera;

	SceneObject* objects[1000];

	Cube* cube[500];

	Pyramid* pyramid[500];
};

