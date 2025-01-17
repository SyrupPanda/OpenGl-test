#include "Texture2D.h"
#include <iostream>
#include <fstream>


Texture2D::Texture2D()
{
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &ID);
}

bool Texture2D::Load(char* path, int LWidth, int LHeight)
{
	char* tempTextureData; int fileSize; std::ifstream inFile;
	width = LWidth; height = LHeight;
	inFile.open(path, std::ios::binary);

	if (!inFile.good())
	{
		std::cerr << "Can't open texture file" << path << std::endl;
		return false;
	}

	inFile.seekg(0, std::ios::end);
	fileSize = (int)inFile.tellg();
	tempTextureData = new char[fileSize];
	inFile.seekg(0, std::ios::beg);
	inFile.read(tempTextureData, fileSize);
	inFile.close();

	std::cout << path << " loaded." << std::endl;

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	delete[] tempTextureData;
	return true;
}