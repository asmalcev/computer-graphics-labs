#include <GL/glut.h>
#include <stdio.h>

#include "config.hpp"

constexpr GLint S = 3;

bool keys[256];

constexpr GLfloat triangle1[3][S] = {{1, 1, 1}, {-1, 0, -1}, {1, -1, 1}};
constexpr GLfloat triangle2[3][S] = {{-0.7, -0.7, 0}, {-0.7, 0.7, 0}, {0.7, 0, 0}};
constexpr GLfloat triangle3[3][S] = {{0, 0, -0.9}, {-1, -0.8, 0.5}, {1, 1, 1}};

constexpr GLfloat cube[8][S] = {
	{0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5}, {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5},
	{0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}, {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5},
};

GLvoid resizeScene(GLsizei w, GLsizei h)
{
	if (h == 0) {
		h = 1;
	}

	glViewport(0, 0, w, h);
}

float coefficient = 1;

GLvoid renderScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 1
	// glVertexPointer(S, GL_FLOAT, 0, triangle1);
	// glColor3f(1, 0, 0);

	// glBegin(GL_LINES);
	// 	glArrayElement(0);
	// 	glArrayElement(1);
	// 	glArrayElement(1);
	// 	glArrayElement(2);
	// 	glArrayElement(2);
	// 	glArrayElement(0);
	// glEnd();

	// glVertexPointer(S, GL_FLOAT, 0, triangle2);
	// glColor3f(0, 1, 0);

	// glBegin(GL_LINES);
	// 	glArrayElement(0);
	// 	glArrayElement(1);
	// 	glArrayElement(1);
	// 	glArrayElement(2);
	// 	glArrayElement(2);
	// 	glArrayElement(0);
	// glEnd();

	// glVertexPointer(S, GL_FLOAT, 0, triangle3);
	// glColor3f(0, 0, 1);

	// glBegin(GL_LINES);
	// 	glArrayElement(0);
	// 	glArrayElement(1);
	// 	glArrayElement(1);
	// 	glArrayElement(2);
	// 	glArrayElement(2);
	// 	glArrayElement(0);
	// glEnd();

	// 2
	glVertexPointer(S, GL_FLOAT, 0, cube);

	glPushMatrix();

	glRotatef(-15, 1, 0, 0);
	glRotatef(65, 0, 1, 0);
	glScalef(1 * coefficient, 1 * coefficient, 1 * coefficient);

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
		glArrayElement(0);
		glArrayElement(1);
		glArrayElement(2);
		glArrayElement(3);

	glColor3f(0, 1, 0);
		glArrayElement(4);
		glArrayElement(5);
		glArrayElement(6);
		glArrayElement(7);

	glColor3f(0, 0, 1);
		glArrayElement(0);
		glArrayElement(1);
		glArrayElement(5);
		glArrayElement(4);

	glColor3f(0, 1, 1);
		glArrayElement(2);
		glArrayElement(3);
		glArrayElement(7);
		glArrayElement(6);

	glColor3f(1, 1, 0);
		glArrayElement(0);
		glArrayElement(3);
		glArrayElement(7);
		glArrayElement(4);

	glColor3f(1, 0, 1);
		glArrayElement(1);
		glArrayElement(2);
		glArrayElement(6);
		glArrayElement(5);
	glEnd();

	glPopMatrix();

	glutSwapBuffers();
}

GLvoid processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	} else if (key == 43) {
		// upscale
		coefficient += 0.1;
	} else if (key == 95) {
		// downscale
		coefficient -= 0.1;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("work - 4");

	glEnableClientState(GL_VERTEX_ARRAY);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(5);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// glOrtho(-0.8, 0.8, -0.9, 0.9, 0.4, 10);
	// glFrustum(-0.8, 0.8, -0.9, 0.9, 0.4, 10);
	glFrustum(-0.8, 0.8, -0.9, 0.9, 0, 10);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeScene);

	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();

	return 0;
}