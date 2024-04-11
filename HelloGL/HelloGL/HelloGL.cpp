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
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	cube = new Cube();

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

	cube->Draw();

	gluLookAt(
		camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z
	);

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

void HelloGL::Update()
{
	glLoadIdentity();

	cube->Update();

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

HelloGL::~HelloGL(void)
{
	delete camera;
	camera = nullptr;
}

