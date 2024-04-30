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

	//void LoadColours(ifstream& inFile, Mesh& mesh)
	//{
	//	inFile >> mesh.ColorCount;

	//	if (mesh.ColorCount > 0)
	//	{
	//		mesh.Colors = new Color[mesh.ColorCount];

	//		for (int i = 0; i < mesh.ColorCount; i++)
	//		{
	//			inFile >> mesh.Colors[i].r >> mesh.Colors[i].g >> mesh.Colors[i].b;	
	//		}
	//	}
	//}

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.NormalCount;

		if (mesh.NormalCount > 0)
		{
			mesh.NormalCount = new Normal[mesh.NormalCount];

			for (int i = 0; i < mesh.NormalCount; i++)
			{
				inFile >> mesh.Normals[i].x >> mesh.Normals[i].y >> mesh.Normals[i].z;
			}
		}
	}

	void LoadTexCoords(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.TexCoordCount;

		if (mesh.TexCoordCount > 0)
		{
			mesh.TexCoords = new TexCoord[mesh.TexCoordCount];

			for (int i = 0; i < mesh.TexCoordCount; i++)
			{
				inFile >> mesh.TexCoords[i].u >> mesh.TexCoords[i].v;
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
		//LoadColours(inFile, *mesh);

		LoadTexCoords(inFile, *mesh);

		LoadIndices(inFile, *mesh);

		inFile.close();

		return mesh;
	}
}