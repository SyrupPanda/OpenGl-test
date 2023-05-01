#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"

class Texture2D
{
private:
	GLuint ID;
	int width, height;

public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return ID; }
	int GetWidth() const { return width; }
	int GetHeight() const { return height; }
};

