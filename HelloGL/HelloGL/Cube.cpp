#include "Cube.h"

//Vertex* Cube::indexedVertices = nullptr;
//Color* Cube::indexedColors = nullptr;
//GLushort* Cube::indices = nullptr;

//int Cube::numVertices = 0;
//int Cube::numColors = 0;
//int Cube::numIndices = 0;

Cube::Cube(Mesh* mesh, float x, float y, float z, float rot) : SceneObject(mesh)
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
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr) 
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, 1, GL_UNSIGNED_SHORT, _mesh->Indices);
		std::cout << "not null" << std::endl;
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	else
	{
		std::cout << "null" << std::endl;
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

	//inFile >> numVertices;
	//indexedVertices = new Vertex[numVertices];
	//for (int i = 0; i < numVertices; i++)
	//{
	//	inFile >> indexedVertices[i].x >> indexedVertices[i].y >> indexedVertices[i].z;
	//}

	//inFile >> numColors;
	//indexedColors = new Color[numColors];
	//for (int i = 0; i < numColors; i++)
	//{
	//	inFile >> indexedColors[i].r >> indexedColors[i].g >> indexedColors[i].b;
	//}

	//inFile >> numIndices;
	//indices = new GLushort[numIndices];
	//for (int i = 0; i < numIndices; i++)
	//{
	//	inFile >> indices[i];
	//}

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