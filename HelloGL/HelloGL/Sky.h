#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

#include <iostream>
#include <fstream>
#include <cerrno>

#include "SceneObject.h"

class Sky : public SceneObject
{
private:
	Material* _material;

	static int numVertices, numNormals, numColors, numIndices;
public:
	Sky(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Sky();

	void Draw();
	void Update();

	void InitMaterial();
};

