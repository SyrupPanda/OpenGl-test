#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include"GL\freeglut.h"
#include "Structure.h"
#include "SceneObject.h"

class Objects : public SceneObject
{
private:
	GLfloat rotation;

	Vector3 position;

	Mesh* mesh;

public:
	Objects(Mesh* oMesh,float x, float y, float z);
	~Objects();

	void Draw();
	void Update();
};

