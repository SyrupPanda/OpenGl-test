#pragma once
#include "SceneObject.h"

class Pyramid : public SceneObject
{
private:
	Mesh* mesh;

	Vector3 position;

public:
	Pyramid(Mesh* oMesh, float x, float y, float z);
	~Pyramid();


	void Update();

	void Draw();
};

