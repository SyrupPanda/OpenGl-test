#pragma once
#include "SceneObject.h"

class Cube : public SceneObject
{
private:
	Mesh* mesh;

	Vector3 position;

public:
	Cube(Mesh* oMesh, float x, float y, float z);
	~Cube();


	void Update();

	void Draw();
};

