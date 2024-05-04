#include "HelloGL.h"
#include "Structures.h"
#include "MeshLoader.h"
#include "SceneObject.h"
#include "Texture2D.h"

void HelloGL::InitObjects()
{
	rotation = 0.0f;
	camera = new Camera();
	camera->eye.x = 2.0f; camera->eye.y = 2.0f; camera->eye.z = 0.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	Mesh* skyMesh = MeshLoader::Load((char*)"data/sky.txt");

	Texture2D* skyTexture = new Texture2D();
	skyTexture->Load((char*)"data/stars.raw", 512, 512);

	sky = new Sky(skyMesh, skyTexture, 0, 0, 0);

}
void HelloGL::InitGL(int argc, char* argv[])
{
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
	gluPerspective(45, 1, 1, 2000);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);


}

void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0f;
	_lightPosition->y = 0.0f;
	_lightPosition->z = 1.0f;
	_lightPosition->w = 0.0f;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;

	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;

	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}

HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);

	InitObjects();

	InitLighting();

	looking_left = false;
	looking_right = false;
	looking_up = false;
	looking_down = false;
	//glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	glutMainLoop();
}

void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();

	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	glPopMatrix();

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(
		camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z
	);

	Vector3 v = { -1.4f, 0.7f, -1.0f };
	Color c = { 0.0f, 1.0f, 0.0f };
	DrawString("[OPENGL PROJECT]", &v, &c);

	//for (int i = 0; i < 200; i++)
	//{
	//	objects[i]->Draw();
	//}
	
	sky->Draw();

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

	//CheckCamConditions();

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	//for (int i = 0; i < 200; i++)
	//{
	//	objects[i]->Update();

	//	objects[i]->SetPosition(objects[i]->GetPosition().x, objects[i]->GetPosition().y, objects[i]->GetPosition().z + 0.1f);
	//	if (objects[i]->GetPosition().z > camera->eye.z)
	//	{
	//		objects[i]->SetPosition(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	//	}
	//}

	sky->Update();

	glutPostRedisplay();
}

void HelloGL::YawCam(float angle)
{
	float cosTheta = cos(angle);
	float sinTheta = sin(angle);
	float newX = (camera->eye.x - camera->center.x) * cosTheta - (camera->eye.z - camera->center.z) * sinTheta + camera->center.x;
	float newZ = (camera->eye.x - camera->center.x) * sinTheta + (camera->eye.z - camera->center.z) * cosTheta + camera->center.z;

	camera->eye.x = newX;
	camera->eye.z = newZ;
}
void HelloGL::PitchCam(float angle)
{
	float cosTheta = cos(angle);
	float sinTheta = sin(angle);
	float newY = (camera->eye.y - camera->center.y) * cosTheta - (camera->eye.z - camera->center.z) * sinTheta + camera->center.y;
	float newZ = (camera->eye.y - camera->center.y) * sinTheta + (camera->eye.z - camera->center.z) * cosTheta + camera->center.z;

	camera->eye.y = newY;
	camera->eye.z = newZ;
}

void HelloGL::CheckCamConditions()
{
	float sensitivity = 0.05f;
	if (looking_up)
	{
		PitchCam(-sensitivity);
	}
	if (looking_down)
	{
		PitchCam(sensitivity);
	}
	if (looking_right)
	{
		YawCam(sensitivity);
	}
	if (looking_left)
	{
		YawCam(-sensitivity);
	}
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	float sensitivity = 0.1f;

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

////////////////////////////////////////////////////////////////
	case 'w':
		//looking_up = true;
		PitchCam(-sensitivity);

		std::cout << "move camera up" << std::endl;
		break;
	case 'a':
		//looking_left = true;
		YawCam(-sensitivity);

		std::cout << "move camera left" << std::endl;
		break;
	case 's':
		//looking_down = true;
		PitchCam(sensitivity);

		std::cout << "move camera down" << std::endl;
		break;
	case 'd':
		//looking_right = true;
		YawCam(sensitivity);

		std::cout << "move camera right" << std::endl;
		break;
////////////////////////////////////////////////////////////////
	case '1':
		camera->eye.z += -0.5f;
		break;

	case '2':
		camera->eye.z += 0.5f;
		break;

	case GLUT_ACTIVE_SHIFT:
		// code
		break;
	//default:
	//	looking_left = false;
	//	looking_right = false;
	//	looking_up = false;
	//	looking_down = false;
		break;

	}
}

HelloGL::~HelloGL(void)
{
	delete camera;
	camera = nullptr;
}

