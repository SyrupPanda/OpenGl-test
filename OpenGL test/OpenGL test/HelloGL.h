#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallBacks.h"
#include "Structure.h"
#include "SceneObject.h"
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

	void InitLight();

private:

	Camera* camera;

	SceneObject* objects[1000];

	Cube* cube[1000];

	Texture2D* texture;

	Vector4* lightPosition;
	Lighting* lightData;
};

