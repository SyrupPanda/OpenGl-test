#include "Cube.h"

Cube::Cube(Mesh* cMesh, float x, float y, float z) : SceneObject(mesh)
{
	position.x = x;
	position.y = y;
	position.z = z;
	mesh = cMesh;
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (mesh->Vertices != nullptr && mesh->Colors != nullptr && mesh->Indices != nullptr)
	{
		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, mesh->Colors);

		glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, mesh->Indices);
		glPopMatrix();
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void Cube::Update()
{
}
