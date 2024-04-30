#include "Texture2D.h"

using namespace std;

Texture2D::Texture2D()
{

}
Texture2D::~Texture2D()
{
	if (_ID != 0)
	{
		glDeleteTextures(1, (GLuint*)_ID);
	}
}

bool Texture2D::Load(const char* path, int width, int height)
{
	char* tempTextureData;
	int fileSize;
	ifstream inFile;

	_width = width;
	_height = height;

	inFile.open(path, ios::binary);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}
	
	inFile.seekg(0, ios::end);
	fileSize = (int)inFile.tellg();
	tempTextureData = new char[fileSize];
	inFile.seekg(0, ios::beg);
	inFile.read(tempTextureData, fileSize);
	inFile.close();

	cout << path << " loaded" << endl;

	glGenTextures(1, &_ID);
	glBindTexture(GL_TEXTURE_2D, _ID);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, _width, _height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	delete[] tempTextureData;

	return true;
}