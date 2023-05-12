#include "Cube.h"
#include <iostream>

Cube::Cube(Mesh* cMesh, Texture2D* cTexture, float x, float y, float z) : SceneObject(cMesh, cTexture)
{
	position.x = x;
	position.y = y;
	position.z = z;

	mesh = cMesh;
	texture = cTexture;

	rotation = 10;
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (mesh->Vertices != nullptr && mesh->Normal != nullptr && mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, texture->GetID());

		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);

		glTexCoordPointer(2, GL_FLOAT, 0, mesh->TexCoords);
		glVertexPointer(3, GL_FLOAT, 0, mesh->Vertices);
		glNormalPointer( GL_FLOAT, 0, mesh->Normal);

		material = new Material();
		material->Ambient.x = 0.8f;
		material->Ambient.y = 0.05f;
		material->Ambient.z = 0.05f;
		material->Ambient.w = 1.0f;

		material->Diffuse.x = 0.8f;
		material->Diffuse.y = 0.05f;
		material->Diffuse.z = 0.05f;
		material->Diffuse.w = 1.0f;

		material->Specular.x = 1.0f;
		material->Specular.y = 1.0f;
		material->Specular.z = 1.0f;
		material->Specular.w = 1.0f;

		material->Shininess = 100.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->Diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->Specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, material->Shininess);

		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	
		//glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, mesh->Indices);
		//glPopMatrix();
		glPopMatrix();

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		
	}
}

void Cube::Update()
{
	rotation += 0.5;
	if (rotation > 360)
		rotation = 0.0f;
	std::cout << rotation << std::endl;
}
