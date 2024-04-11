#include "HelloGL.h"
#include "Structures.h"

Vertex pyramidVertices[] =
{

	{ 1, 0, 1 },
	{ -1, 0, 1 },
	{ -1, 0, -1 },
	{ 1, 0, -1 },

	{ 0, 1, 0 }
};
Color pyramidColors[] =
{

	{ 1, 0, 0},
	{ 0, 1, 0},
	{ 0, 0, 1},
	{ 1, 1, 0},

	{ 1, 1, 1}
};
GLushort pyramidIndices[] =
{
	3, 2, 1,
	3, 1, 0,

	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	camera = new Camera();
	camera->eye.x = 2.0f; camera->eye.y = 2.0f; camera->eye.z = 5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	for (int i = 0; i < 200; i++) 
	{
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, (rand() % 1000) / 10.0f, (rand() % 500));
	}

    GLUTCallbacks::Init(this);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(-1, 1);
    glutCreateWindow("Simple OpenGL Program");
    glutDisplayFunc(GLUTCallbacks::Display);
	glutReshapeFunc(GLUTCallbacks::Reshape);
    glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
    glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 1, 1000);;
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST); 
	glCullFace(GL_BACK);

	glutMainLoop();

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(
		camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z
	);


	for (int i = 0; i < 200; i++)
	{
		cube[i]->Draw();
	}


	glFlush();
	glutSwapBuffers();
}

void HelloGL::Reshape(int width, int height)
{
	if (height == 0) height = 1; // Prevent division by zero

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 1000.0f); // Adjust aspect ratio
	glMatrixMode(GL_MODELVIEW);
}

void HelloGL::DrawWire()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, -1.0f, 0.0f);

	glutWireTeapot(1);

	glEnd();

	glPopMatrix();
}

void HelloGL::Update()
{
	glLoadIdentity();

	for (int i = 0; i < 200; i++)
	{
		cube[i]->Update();

		// Move the cube towards the camera
		cube[i]->SetPosition(cube[i]->GetPosition().x, cube[i]->GetPosition().y, cube[i]->GetPosition().z + 0.1f);

		// Reset the cube to the rear of the frustum if it moves behind the camera
		if (cube[i]->GetPosition().z > camera->eye.z)
		{
			cube[i]->SetPosition(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
		}
	}
	glutPostRedisplay();
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

HelloGL::~HelloGL(void)
{
	delete camera;
	camera = nullptr;
}

