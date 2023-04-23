#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	GLUTCallbacks::Init(this);
	for (int i = 0; i < 200; i++)
	{
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	Cube::Load((char*)"Objects/cube.txt");
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");

	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Draw();
	}
	glutSwapBuffers();	glFlush();
}

void HelloGL::Update()
{
	glLoadIdentity();	
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Update();
	}
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