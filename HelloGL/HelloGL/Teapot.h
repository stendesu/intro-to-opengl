#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

#include <iostream>
#include <fstream>
#include <cerrno>

class Teapot
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;

	GLfloat _rotation;
	Vector3 _position;

	static int numVertices, numColors, numIndices;
public:
	Teapot(float x, float y, float z, float rot);
	~Teapot();

	void Draw();
	void Update();

	Vector3 GetPosition();
	void SetPosition(float new_x, float new_y, float new_z);

	static bool Load(char* path);
};

