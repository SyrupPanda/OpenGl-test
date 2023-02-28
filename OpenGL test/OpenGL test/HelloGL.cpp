#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	HelloGL::DrawPolygon();
	HelloGL::DrawTriangle();
	glutSwapBuffers();
	glFlush();
}

void HelloGL::Update()
{
	glLoadIdentity();
	glutPostRedisplay();
	if (rotation > 360.0f)
		rotation = 0.0f;
	if (rotation < 0.0f)
		rotation = 360.0f;
	Sleep(10);
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, -1.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.5, 0.5);
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.5, 0.5);
		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.5, -0.5);
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(-0.5, -0.5);
		glEnd();
	}
	glPopMatrix();
	glFlush();
}

void HelloGL::DrawTriangle()
{
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	{
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(-0.5f, 0.0f);
		glEnd();
	}
	glPopMatrix();
	glFlush();
}

HelloGL::~HelloGL(void)
{

}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 0.5f;
	if (key == 'a')
		rotation -= 0.5f;
}