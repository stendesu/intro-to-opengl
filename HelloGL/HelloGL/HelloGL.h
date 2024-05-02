#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include <iostream>

class SceneObject;

#include "Cube.h"
#include "Teapot.h"
#include "Pyramid.h"

#include "Structures.h"

#define REFRESHRATE 16

class HelloGL
{
private:
	float rotation;
	Camera* camera;
	SceneObject* objects[1000];
	Teapot* teapot[200];

	Vector4* _lightPosition;
	Lighting* _lightData;
public:

	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLighting();

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void Draw();

	void DrawString(const char* text, Vector3* position, Color* color);

	void DrawWire();

	void Reshape(int width, int height);
};

