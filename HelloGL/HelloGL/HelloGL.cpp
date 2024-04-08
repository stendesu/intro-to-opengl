#include "HelloGL.h"
Vertex HelloGL::vertices[] = { 1, 1, 1, -1, 1, 1, -1,-1, 1, // v0-v1-v2 (front)

-1,-1, 1, 1,-1, 1, 1, 1, 1, // v2-v3-v0

1, 1, 1, 1,-1, 1, 1,-1,-1, // v0-v3-v4 (right)

1,-1,-1, 1, 1,-1, 1, 1, 1, // v4-v5-v0

1, 1, 1, 1, 1,-1, -1, 1,-1, // v0-v5-v6 (top)

-1, 1,-1, -1, 1, 1, 1, 1, 1, // v6-v1-v0

-1, 1, 1, -1, 1,-1, -1,-1,-1, // v1-v6-v7 (left)

-1,-1,-1, -1,-1, 1, -1, 1, 1, // v7-v2-v1

-1,-1,-1, 1,-1,-1, 1,-1, 1, // v7-v4-v3 (bottom)

1,-1, 1, -1,-1, 1, -1,-1,-1, // v3-v2-v7

1,-1,-1, -1,-1,-1, -1, 1,-1, // v4-v7-v6 (back)

-1, 1,-1, 1, 1,-1, 1,-1,-1 }; // v6-v5-v4

Color HelloGL::colors[] = { 1, 1, 1, 1, 1, 0, 1, 0, 0, // v0-v1-v2 (front)

1, 0, 0, 1, 0, 1, 1, 1, 1, // v2-v3-v0

1, 1, 1, 1, 0, 1, 0, 0, 1, // v0-v3-v4 (right)

0, 0, 1, 0, 1, 1, 1, 1, 1, // v4-v5-v0

1, 1, 1, 0, 1, 1, 0, 1, 0, // v0-v5-v6 (top)

0, 1, 0, 1, 1, 0, 1, 1, 1, // v6-v1-v0

1, 1, 0, 0, 1, 0, 0, 0, 0, // v1-v6-v7 (left)

0, 0, 0, 1, 0, 0, 1, 1, 0, // v7-v2-v1

0, 0, 0, 0, 0, 1, 1, 0, 1, // v7-v4-v3 (bottom)

1, 0, 1, 1, 0, 0, 0, 0, 0, // v3-v2-v7

0, 0, 1, 0, 0, 0, 0, 1, 0, // v4-v7-v6 (back)

0, 1, 0, 0, 1, 1, 0, 0, 1 }; // v6-v5-v4

Vertex HelloGL::indexedVertices[] = { 1, 1, 1, -1, 1, 1, // v0,v1,

-1,-1, 1, 1,-1, 1, // v2,v3

1,-1,-1, 1, 1,-1, // v4,v5

-1, 1,-1, -1,-1,-1 }; // v6,v7

Color HelloGL::indexedColors[] = { 1, 1, 1, 1, 1, 0, // v0,v1,

1, 0, 0, 1, 0, 1, // v2,v3

0, 0, 1, 0, 1, 1, // v4,v5

0, 1, 0, 0, 0, 0 }; //v6,v7

GLushort HelloGL::indices[] = { 0, 1, 2, 2, 3, 0, // front

0, 3, 4, 4, 5, 0, // right

0, 5, 6, 6, 1, 0, // top

1, 6, 7, 7, 2, 1, // left

7, 4, 3, 3, 2, 7, // bottom

4, 7, 6, 6, 5, 4 }; // back

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;

	camera = new Camera();
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

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

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop();

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	gluLookAt(
		camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z
	);


	//DrawWire();

	//DrawCube();

	DrawCubeArray();

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

void HelloGL::DrawWire()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, -1.0f, 0.0f);

	glutWireTeapot(0.1);

	glEnd();

	glPopMatrix();
}

void HelloGL::DrawCubeArray()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{

		glColor3f(colors[i / 1].r, colors[i / 2].g, colors[i / 3].b);
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);

	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawCube()
{
	glBegin(GL_TRIANGLES);

	// face v0-v1-v2

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	// face v2-v3-v0

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	// face v0-v3-v4

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	// face v4-v5-v0

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glColor3f(0, 1, 1);

	glVertex3f(1, 1, -1);

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	// face v0-v5-v6

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	glColor3f(0, 1, 1);

	glVertex3f(1, 1, -1);

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	// face v6-v1-v0

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	// face v1-v6-v7

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	// face v7-v2-v1

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	// face v7-v4-v3

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	// face v3-v2-v7

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	// face v4-v7-v6

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	// face v6-v5-v4

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	glColor3f(0, 1, 1);

	glVertex3f(1, 1, -1);

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glEnd();
}

void HelloGL::Update()
{
	glLoadIdentity();


	glutPostRedisplay();

	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		rotation += 2.0f;
		std::cout << "rotating clockwise" << std::endl;
		break;
	case 'e':
		rotation += -2.0f;
		std::cout << "rotating anti clockwise" << std::endl;
		break;
	case 'w':
		camera->eye.y += 0.5f;
		std::cout << "move camera up" << std::endl;
		break;
	case 'a':
		camera->eye.x += 0.5f;
		std::cout << "move camera left" << std::endl;
		break;
	case 's':
		camera->eye.y += -0.5f;
		std::cout << "move camera down" << std::endl;
		break;
	case 'd':
		camera->eye.x += -0.5f;
		std::cout << "move camera right" << std::endl;
		break;

	case GLUT_ACTIVE_SHIFT:
		// code
		break;

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
	delete camera;
	camera = nullptr;
}

