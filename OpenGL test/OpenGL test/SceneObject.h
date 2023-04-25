#pragma once
#include "Structure.h"

class SceneObject
{
protected:
	Mesh* mesh;

public:
	SceneObject(Mesh* mesh);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
};

