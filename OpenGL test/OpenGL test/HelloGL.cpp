#include "HelloGL.h"

Vertex HelloGL::vertices[] = { 
1,1,1,  -1,1,1,  -1,-1,1, 
-1,-1,1,  1,-1,1,  1,1,1, 

1,1,1,  1,-1,1,  1,-1,-1, 
1,-1,-1,  1,1,-1,  1,1,1, 

1,1,1,  1,1,-1,  -1,1,-1,
-1,1,-1,  -1,1,1,  1,1,1, 

-1,1,1,  -1,1,-1,  -1,-1,-1, 
-1,-1,-1,  -1,-1,1,  -1,1,1, 

-1,-1,-1,  1,-1,-1,  1,-1,1, 
1,-1,1,  -1,-1,1,  -1,-1,-1, 

1,-1,-1,  -1,-1,-1,  -1,1,-1, 
-1,1,-1,  1,1,-1,  1,-1,-1, };

Color HelloGL::colors[] = {
1, 1, 1,  1, 1, 0,  1, 0, 0,
1, 0, 0,  1, 0, 1,  1, 1, 1,

1, 1, 1,  1, 0, 1,  0, 0, 1,
0, 0, 1,  0, 1, 1,  1, 1, 1,

1, 1, 1,  0, 1, 1,  0, 1, 0,
0, 1, 0,  1, 1, 0,  1, 1, 1,

1, 1, 0,  0, 1, 0,  0, 0, 0,
0, 0, 0,  1, 0, 0,  1, 1, 0,

0, 0, 0,  0, 0, 1,  1, 0, 1,
1, 0, 1,  1, 0, 0,  0, 0, 0,

0, 0, 1,  0, 0, 0,  0, 1, 0,
0, 1, 0,  0, 1, 1,  0, 0, 1};

Vertex HelloGL::indexedVertices[] =
{ 1, 1, 1,  -1, 1, 1,
-1, -1, 1,  1, -1, 1,
1, -1, -1,  1, 1, -1,
-1, 1, -1,  -1, -1, -1};

Color HelloGL::indexedColors[] = {
1, 1, 1,  1, 1, 0,
1, 0, 0,  1, 0, 1,
0, 0, 1,  0, 1, 1,
0, 1, 0,  0, 0, 0
};

GLushort HelloGL::indices[] = {
0, 1, 2,  2, 3, 0,
0, 3, 4,  4, 5, 0,
0, 5, 6,  6, 1, 0,
1, 6, 7,  7, 2, 1,
7, 4, 3,  3, 2, 7,
4, 7, 6,  6, 5, 4};

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	camera = new Camera();
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glutInitDisplayMode(GLUT_DOUBLE);
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
	glutSwapBuffers();
	DrawIndexedCube();
	glFlush();
}

void HelloGL::Update()
{
	glLoadIdentity();	
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);
	if (rotation > 360.0f)
		rotation = 0.0f;
	if (rotation < 0.0f)
		rotation = 360.0f;
	glutPostRedisplay();
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.5f);
	glRotatef(rotation, 1.0f, 0.0f, -1.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0



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
	glTranslatef(0.0f, 0.0f, -5.5f);
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

void HelloGL::DrawWire()
{
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, -0.5f);
	glTranslatef(0.0f, 0.0f, -0.5f);

	glutWireCube(0.1f);

	glPopMatrix();
	glFlush();
}

void HelloGL::DrawCube()
{
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, -0.5f);

	glBegin(GL_TRIANGLES);
	//1
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	//2
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//3
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	//4
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//5
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//6
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//8
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	//9
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	//10
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//11
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//12
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();

	glPopMatrix();
	glFlush();
}

void HelloGL::DrawCubeArray()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		/*glColor3f(colors[i].r, colors[i].g, colors[i].b);
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);*/
		glColor3fv(&colors[i].r);
		glVertex3fv(&vertices[i].x);
	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawIndexedCube()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&indexedColors[indices[i]].r);
		glVertex3fv(&indexedVertices[indices[i]].x);
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

HelloGL::~HelloGL(void)
{
	delete camera;
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'x')
		rotation += 0.5f;
	if (key == 'z')
		rotation -= 0.5f;

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