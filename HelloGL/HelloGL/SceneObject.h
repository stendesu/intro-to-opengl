#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

#include <iostream>
#include <fstream>
#include <cerrno>

class Texture2D;

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;

	GLfloat _rotation;
	Vector3 _position;

public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();

	Vector3 GetPosition();
	void SetPosition(float new_x, float new_y, float new_z);

	virtual void SetZ(float newZ) { _position.z += newZ; };
	virtual void SetX(float newX) { _position.x += newX; };
	virtual void SetY(float newY) { _position.y += newY; };
};

