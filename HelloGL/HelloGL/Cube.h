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

class Cube : public SceneObject
{
private:
	GLfloat _rotation;
	Vector3 _position;

	static int numVertices, numColors, numIndices;
public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z, float rot);
	~Cube();

	void Draw();
	void Update();

	Vector3 GetPosition();
	void SetPosition(float new_x, float new_y, float new_z);
};

