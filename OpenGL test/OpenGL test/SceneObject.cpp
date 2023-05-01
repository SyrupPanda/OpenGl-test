#include "SceneObject.h"


SceneObject::SceneObject(Mesh* sMesh, Texture2D* sTexture)
{
	mesh = sMesh;
	texture = sTexture;
}

SceneObject::~SceneObject()
{
}

void SceneObject::Update()
{
}

void SceneObject::Draw()
{
}