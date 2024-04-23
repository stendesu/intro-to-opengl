#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

int numVertices = 0;
int numColors = 0;
int numIndices = 0;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
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

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		inFile >> numColors;
		indexedColors = new Color[numColors];
		for (int i = 0; i < numColors; i++)
		{
			inFile >> indexedColors[i].r >> indexedColors[i].g >> indexedColors[i].b;
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> numIndices;
		indices = new GLushort[numIndices];
		for (int i = 0; i < numIndices; i++)
		{
			inFile >> indices[i];
		}

	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		std::ifstream inFile;
		inFile.open(path);
		if (!inFile.good())
		{
			std::cerr << "Can't open text file " << path << std::endl;
		}

		inFile.close();

		//LOAD DATA USING METHODS ABOVE

		return mesh;
	}
}