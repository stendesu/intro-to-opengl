#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

class HelloGL
{
private:
	float rotation;
public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

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

#pragma endregion
};

