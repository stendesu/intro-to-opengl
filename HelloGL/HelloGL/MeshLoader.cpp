#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

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
				inFile >> mesh.Vertices[i].x >> mesh.Vertices[i].y >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.ColorCount;

		if (mesh.ColorCount > 0)
		{
			mesh.Colors = new Color[mesh.ColorCount];

			for (int i = 0; i < mesh.ColorCount; i++)
			{
				inFile >> mesh.Colors[i].r >> mesh.Colors[i].g >> mesh.Colors[i].b;
			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.IndexCount;

		if (mesh.IndexCount > 0)
		{
			mesh.Indices = new GLushort[mesh.IndexCount];

			for (int i = 0; i < mesh.IndexCount; i++)
			{
				inFile >> mesh.Indices[i];
			}
		}
	}

	void LoadTexCoords(ifstream& inFile, Mesh& mesh)
	{
		vector<TexCoord> texCoords;
		string line;
		while (getline(inFile, line)) {
			istringstream iss(line);
			string type;
			iss >> type;
			if (type == "vt") {
				TexCoord texCoord;
				iss >> texCoord.u >> texCoord.v;
				texCoords.push_back(texCoord);
			}
		}

		mesh.TexCoords = new TexCoord[texCoords.size()];
		mesh.TexCoordCount = texCoords.size();
		copy(texCoords.begin(), texCoords.end(), mesh.TexCoords);
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;
		inFile.open(path);
		if (!inFile.good())
		{
			cerr << "Can't open text file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		LoadColours(inFile, *mesh);

		LoadTexCoords(inFile, *mesh);

		LoadIndices(inFile, *mesh);

		inFile.close();

		return mesh;
	}
}