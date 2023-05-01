#include "Cube.h"

Cube::Cube(Mesh* cMesh, Texture2D* cTexture, float x, float y, float z) : SceneObject(cMesh, cTexture)
{
	position.x = x;
	position.y = y;
	position.z = z;

	mesh = cMesh;
	texture = cTexture;
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (mesh->Vertices != nullptr && mesh->Colors != nullptr && mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, texture->GetID());

		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, mesh->Colors);
		glTexCoordPointer(2, GL_FLOAT, 0, mesh->TexCoords);

		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
	
		glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, mesh->Indices);
		glPopMatrix();
		glPopMatrix();

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		
	}
}

void Cube::Update()
{
}
