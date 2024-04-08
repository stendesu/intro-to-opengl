#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include <iostream>

#define REFRESHRATE 16

struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3 eye, center, up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

class HelloGL
{
private:
	float rotation;
	Camera* camera;
	static Vertex vertices[];
	static Color colors[];

	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void DrawCube();

	void DrawCubeArray();

#pragma region draw triangles

	void DrawPolygon();

	void DrawTriangle();

	void DrawScalene();

	void DrawIsosceles();

	void DrawEquilateral();

	void DrawAcute();

	void DrawRight();

	void DrawObtuse();

	void RotateRectangle();

	void RotateSquare();
	
	void RotateTriangle();

	void DrawWire();

#pragma endregion


};

