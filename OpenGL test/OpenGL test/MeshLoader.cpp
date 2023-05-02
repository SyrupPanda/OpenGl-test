#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadNormal(ifstream& inFile, Mesh& mesh);
	void LoadUV(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadUV(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.TexCoordCount;
		mesh.TexCoords = new TexCoord[mesh.TexCoordCount];
		for (int i = 0; i < mesh.TexCoordCount; i++)
		{
			inFile >> mesh.TexCoords[i].u;
			inFile >> mesh.TexCoords[i].v;
		}
	}

	void LoadNormal(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.NormalCount;

		mesh.Normal = new Vector3[mesh.NormalCount];

		for (int i = 0; i < mesh.NormalCount; i++)
		{
			inFile >> mesh.Normal[i].x;
			inFile >> mesh.Normal[i].y;
			inFile >> mesh.Normal[i].z;
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.IndexCount;
		mesh.Indices = new GLushort[mesh.IndexCount];
		for (int i = 0; i < mesh.IndexCount; i++)
		{
			inFile >> mesh.Indices[i];
		}
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		LoadUV(inFile, *mesh);
		LoadNormal(inFile, *mesh);		
		LoadIndices(inFile, *mesh);

		inFile.close();
		return mesh;
	}
}