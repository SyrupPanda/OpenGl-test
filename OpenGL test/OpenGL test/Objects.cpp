#include "Objects.h"
#include <iostream>
#include <fstream>

Objects::Objects(Mesh* cMesh, float x, float y, float z)
{
	rotation = 0.0f;
	position.x = x;
	position.y = y;
	position.z = z;
	mesh = cMesh;
}

Objects::~Objects()
{

}

void Objects::Draw()
{
	if (mesh->Vertices != nullptr && mesh->Colors != nullptr && mesh->Indices != nullptr)
	{
		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef(rotation, 1.0f, 0.0f, 0.0f);
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

void Objects::Update()
{
	rotation += 0.1f;
}