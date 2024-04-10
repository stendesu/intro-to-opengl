#include "HelloGL.h"
#include "Structures.h"





HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;

	camera = new Camera();
	camera->eye.x = 5.0f; camera->eye.y = 0.0f; camera->eye.z = 0.0f;
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

	//DrawCubeArray();

	//DrawIndexedCube();

	//DrawCubeArrayAlt();

	//DrawIndexedCubeAlt();

	//DrawIndexedPyramid();

	//DrawIndexedPyramidAlt();

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

	glutWireTeapot(1);

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

void HelloGL::DrawIndexedCube()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i += 3)
	{
		Vertex v0 = indexedVertices[indices[i]];
		Vertex v1 = indexedVertices[indices[i + 1]];
		Vertex v2 = indexedVertices[indices[i + 2]];

		Color c0 = indexedColors[indices[i]];
		Color c1 = indexedColors[indices[i + 1]];
		Color c2 = indexedColors[indices[i + 2]];

		glColor3f(c0.r, c0.g, c0.b);
		glVertex3f(v0.x, v0.y, v0.z);

		glColor3f(c1.r, c1.g, c1.b);
		glVertex3f(v1.x, v1.y, v1.z);

		glColor3f(c2.r, c2.g, c2.b);
		glVertex3f(v2.x, v2.y, v2.z);
	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawCubeArrayAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glPushMatrix();
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedCubeAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);	

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedPyramid()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 18; i += 3)
	{
		Vertex v0 = pyramidVertices[pyramidIndices[i]];
		Vertex v1 = pyramidVertices[pyramidIndices[i + 1]];
		Vertex v2 = pyramidVertices[pyramidIndices[i + 2]];

		Color c0 = pyramidColors[pyramidIndices[i]];
		Color c1 = pyramidColors[pyramidIndices[i + 1]];
		Color c2 = pyramidColors[pyramidIndices[i + 2]];

		glColor3f(c0.r, c0.g, c0.b);
		glVertex3f(v0.x, v0.y, v0.z);

		glColor3f(c1.r, c1.g, c1.b);
		glVertex3f(v1.x, v1.y, v1.z);

		glColor3f(c2.r, c2.g, c2.b);
		glVertex3f(v2.x, v2.y, v2.z);
	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawIndexedPyramidAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), pyramidVertices);
	glColorPointer(3, GL_FLOAT, sizeof(Color), pyramidColors);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, pyramidIndices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
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

	case '1':
		camera->eye.z += -0.5f;
		break;

	case '2':
		camera->eye.z += 0.5f;
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

