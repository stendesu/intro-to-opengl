#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(-1, 1);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);

	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 0.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 0.0f; camera->up.z = 0.0f;

	glutMainLoop();

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glutWireCube(1);
	glPopMatrix();


#pragma region draw triangles

	//RotateRectangle();
	//RotateTriangle();
	//RotateSquare();

	//DrawPolygon();

	//DrawTriangle();

	//DrawScalene();

	//DrawIsosceles();

	//DrawEquilateral();

	//DrawAcute();

	//DrawRight();

	//DrawObtuse();

#pragma endregion

	glFlush();
	glutSwapBuffers();
}



void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(
	camera->eye.x = 0.0f, camera->eye.y = 0.0f, camera->eye.z = 0.0f,
	camera->center.x = 0.0f, camera->center.y = 0.0f, camera->center.z = 0.0f,
	camera->up.x = 0.0f, camera->up.y = 0.0f, camera->up.z = 0.0f
	);

	glutPostRedisplay();

	//rotation += 1.0f;

	//if (rotation >= 360.0f)
	//{
	//	rotation = 0.0f;
	//}
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		rotation += 1.0f;
	}
	else if (key == 'a')
	{
		rotation += -1.0f;
	}
}


#pragma region Draw triangle functions

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
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);

		glVertex2f(-0.7, 0.3);	//	TOP left
		glVertex2f(0.6, -0.6);	//	BOTTOM right
		glVertex2f(-0.4, -0.6);	// BOTTOM left
		glEnd();
	}
}
#pragma endregion

#pragma region rotate polygons

void HelloGL::RotateRectangle()
{
	glPushMatrix();
	glRotatef(rotation, 5.0f, 6.0f, 0.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);

		glVertex2f(-0.4, 0.3);	//	TOP left
		glVertex2f(0.4, 0.3);	//	TOP RIGHT
		glVertex2f(0.4, -0.3);	//	BOTTOM right
		glVertex2f(-0.4, -0.3);	// BOTTOM left

		//glTranslatef(0, 1, 0);
		glEnd();
	}



	glPopMatrix();


}

void HelloGL::RotateSquare()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -5.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);

		glVertex2f(-0.9, 0.3);	//	TOP left
		glVertex2f(-0.6, 0.3);	//	TOP RIGHT
		glVertex2f(-0.6, -0.3);	//	BOTTOM right
		glVertex2f(-0.9, -0.3);	// BOTTOM left
		glEnd();
	}
	glPopMatrix();


}

void HelloGL::RotateTriangle()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, 5.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);

		glVertex2f(0.6, 0.4);	//	TOP left
		glVertex2f(0.8, -0.3);	//	BOTTOM right
		glVertex2f(0.4, -0.3);	// BOTTOM left
		glEnd();
	}

	glPopMatrix();


}

#pragma endregion




HelloGL::~HelloGL(void)
{
	
}

