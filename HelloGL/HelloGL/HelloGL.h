#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3 eye, center, up;
};

class HelloGL
{
private:
	float rotation;
	Camera* camera;
public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

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

