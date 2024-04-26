#include "Texture2D.h"

using namespace std;

Texture2D::Texture2D()
{

}
Texture2D::~Texture2D()
{
	glDeleteTextures(1, (GLuint*)_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}
	
	inFile.close();

	glGenTextures(1, (GLuint*)_ID);

	return true;
}