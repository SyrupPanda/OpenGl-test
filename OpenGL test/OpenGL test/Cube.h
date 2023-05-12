#pragma once
#include "SceneObject.h"

class Cube : public SceneObject
{
private:
	Vector3 position;

	Material* material;

	GLfloat rotation;
public:
	Cube(Mesh* oMesh, Texture2D* oTexture, float x, float y, float z);
	~Cube();

	void Update();

	void Draw();
};

