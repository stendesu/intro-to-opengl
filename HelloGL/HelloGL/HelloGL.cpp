#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
	glutInitWindowSize(800, 800);
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	DrawPolygon();

	DrawTriangle();

	DrawScalene();

	DrawIsosceles();

	DrawEquilateral();

	DrawAcute();

	DrawRight();

	DrawObtuse();

	glFlush();
}

void HelloGL::DrawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);

		glVertex2f(-0.75, 0.5);
		glVertex2f(0.75, 0.5);
		glVertex2f(0.75, -0.5);
		glVertex2f(-0.75, -0.5);
		glEnd();
	}
}

void HelloGL::DrawTriangle()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.5f, 0.0f);

		glVertex2f(0, 0.6);	//	TOP left
		glVertex2f(0, 0.6);	//	TOP right
		glVertex2f(0.5, -0.6);	//	BOTTOM right
		glVertex2f(-0.5, -0.6);	// BOTTOM left
		glEnd();
	}
}

void HelloGL::DrawScalene()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.5f, 0.5f, 0.0f);

		glVertex2f(-0.5, 0.3);	//	TOP left
		glVertex2f(0.5, -0.6);	//	BOTTOM right
		glVertex2f(-0.7, -0.6);	// BOTTOM left
		glEnd();
	}
}

void HelloGL::DrawIsosceles()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(0.5f, 1.0f, 0.5f, 0.0f);

		glVertex2f(0, 0.7);	//	TOP left
		glVertex2f(0.5, -0.6);	//	BOTTOM right
		glVertex2f(-0.5, -0.6);	// BOTTOM left
		glEnd();
	}
}

void HelloGL::DrawEquilateral()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.5f, 0.5f, 0.0f);

		glVertex2f(0.0, 0.3);	//	TOP left
		glVertex2f(0.5, -0.5);	//	BOTTOM right
		glVertex2f(-0.5, -0.5);	// BOTTOM left
		glEnd();
	}
}

void HelloGL::DrawAcute()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.5f, 0.5f, 0.0f);

		glVertex2f(-0.5, 0.3);	//	TOP left
		glVertex2f(0.5, -0.6);	//	BOTTOM right
		glVertex2f(-0.7, -0.6);	// BOTTOM left
		glEnd();
	}
}

void HelloGL::DrawRight()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.5f, 0.5f, 0.0f);

		glVertex2f(-0.5, 0.3);	//	TOP left
		glVertex2f(0.5, -0.6);	//	BOTTOM right
		glVertex2f(-0.5, -0.6);	// BOTTOM left
		glEnd();
	}
}

void HelloGL::DrawObtuse()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(0.5f, 0.5f, 1.0f, 0.0f);

		glVertex2f(-0.7, 0.3);	//	TOP left
		glVertex2f(0.6, -0.6);	//	BOTTOM right
		glVertex2f(-0.4, -0.6);	// BOTTOM left
		glEnd();
	}
}

HelloGL::~HelloGL(void)
{
	
}

