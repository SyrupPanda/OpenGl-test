#include "HelloGL.h"
#include "MeshLoader.h"
#include "Texture2D.h"
#include <string>
#include <stdio.h>

void HelloGL::InitGL(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");

	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	//glEnable(GL_NORMAL_ARRAY);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void HelloGL::InitObjects()
{
	camera = new Camera();
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	GLUTCallbacks::Init(this);
	Mesh* cubeMesh = MeshLoader::Load((char*)"Objects/cube.txt");

	texture = new Texture2D();
	texture->Load((char*)"Texture/Penguins.raw", 512, 512);

	for (int i = 0; i < 1000; i++)
	{
		objects[i] = new Cube(cubeMesh, texture,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	time = 0.0f;
}

void HelloGL::InitLight()
{
	lightPosition = new Vector4();

	lightPosition->x = 0.0f;
	lightPosition->y = 0.0f;
	lightPosition->z = 1.0f;
	lightPosition->w = 0.0f;

	lightData = new Lighting();

	lightData->Ambient.x = 0.2f;
	lightData->Ambient.y = 0.2f;
	lightData->Ambient.z = 0.2f;
	lightData->Ambient.w = 1.0f;

	lightData->Diffuse.x = 0.8f;
	lightData->Diffuse.y = 0.8f;
	lightData->Diffuse.z = 0.8f;
	lightData->Diffuse.w = 1.0f;

	lightData->Specular.x = 0.2f;
	lightData->Specular.y = 0.2f;
	lightData->Specular.z = 0.2f;
	lightData->Specular.w = 1.0f ;
}



HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();
	InitLight();

	glutMainLoop();
}

void HelloGL::Display()
{
	Vector3 v = { -1.4f, 0.7f, -1.0f };
	Color c = { 0.0f, 1.0f, 0.0f };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Draw();
	}
	char cTime[20];
	sprintf_s(cTime, "%f", time);
	DrawString(cTime, &v, &c);
	glutSwapBuffers();	
	glFlush();
}

void HelloGL::Update()
{
	glLoadIdentity();	
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Update();
	}
	time += glutGet(GLUT_ELAPSED_TIME);
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(lightPosition->x));
	glutPostRedisplay();
	
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'j')
		camera->eye.x -= 0.5f;
	if (key == 'l')
		camera->eye.x += 0.5f;
	if (key == 'k')
		camera->eye.y -= 0.5f;
	if (key == 'i')
		camera->eye.y += 0.5f;
	if (key == 'u')
		camera->eye.z -= 0.5f;
	if (key == 'o')
		camera->eye.z += 0.5f;

	if (key == 'f')
		camera->center.x -= 0.5f;
	if (key == 'h')
		camera->center.x += 0.5f;
	if (key == 'g')
		camera->center.y -= 0.5f;
	if (key == 't')
		camera->center.y += 0.5f;
	if (key == 'r')
		camera->center.z -= 0.5f;
	if (key == 'y')
		camera->center.z += 0.5f;

	if (key == 'a')
		camera->up.x -= 0.5f;
	if (key == 'd')
		camera->up.x += 0.5f;
	if (key == 's')
		camera->up.y -= 0.5f;
	if (key == 'w')
		camera->up.y += 0.5f;
	if (key == 'q')
		camera->up.z -= 0.5f;
	if (key == 'e')
		camera->up.z += 0.5f;
}

void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{
	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
}
