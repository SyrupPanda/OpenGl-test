#pragma once
#include "Structure.h"
#include "Texture2D.h"

class SceneObject
{
protected:
	Mesh* mesh;
	Texture2D* texture;

public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
};

