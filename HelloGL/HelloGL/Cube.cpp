#include "Cube.h"

Vertex* Cube::indexedVertices = nullptr;
Color* Cube::indexedColors = nullptr;
GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numIndices = 0;

Cube::Cube(float x, float y, float z, float rot)
{
	_rotation = rot;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}
Cube::~Cube()
{

}

void Cube::Draw()
{
	if (indexedVertices != nullptr && indexedColors != nullptr && indices != nullptr) 
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
		glColorPointer(3, GL_FLOAT, 0, indexedColors); 

		//Vertex* Cube::indexedVertices = nullptr;
		//Color* Cube::indexedColors = nullptr;
		//GLushort* Cube::indices = nullptr;

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}
void Cube::Update()
{
	_rotation += 1.0f;
	if (_rotation >= 360.0f)
	{
		_rotation = 0.0f;
	}
}

bool Cube::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		//	TODO Use inFile to populate the indexedVertices array
		inFile >> indexedVertices[i].x >> indexedVertices[i].y >> indexedVertices[i].z;
	}

	inFile >> numColors;
	indexedColors = new Color[numColors];
	for (int i = 0; i < numColors; i++)
	{
		//	TODO: Load Color information
		inFile >> indexedColors[i].r >> indexedColors[i].g >> indexedColors[i].b;
	}

	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++)
	{
		//	TODO: Load Indices information
		inFile >> indices[i];
	}

	inFile.close();

	return true;
}

Vector3 Cube::GetPosition()
{
	return _position;
}
void Cube::SetPosition(float new_x, float new_y, float new_z)
{
	_position.x = new_x;
	_position.y = new_y;
	_position.z = new_z;
}