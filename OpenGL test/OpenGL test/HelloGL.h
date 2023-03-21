#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallBacks.h"
#define REFRESHRATE 16

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

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
	void DrawWire();
	void DrawCube();
	void DrawCubeArray();
	void DrawIndexedCube();
	void DrawCubeArrayAlt();
	void DrawIndexedCubeAlt();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

private:
	float rotation;

	Camera* camera;

	static Vertex vertices[];
	static Color colors[];

	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
};

