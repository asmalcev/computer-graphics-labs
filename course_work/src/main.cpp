#include <GL/glut.h>

#include "config.hpp"

constexpr float LEFT = -1, RIGHT = 1, DOWN = -1, UP = 1;

float cameraScale = 1;
float cameraAngleX = 0;
float cameraAngleY = 0;

GLUquadricObj * quadricObj;

void moveCamera() {
	glRotatef(cameraAngleX, 1, 0, 0);
	glRotatef(cameraAngleY, 0, 1, 0);

	glScalef(cameraScale, cameraScale, cameraScale);
}

GLvoid resizeScene(GLsizei w, GLsizei h)
{
	if (h == 0) {
		h = 1;
	}

	glViewport(0, 0, w, h);
}

GLvoid renderScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	moveCamera();

	quadricObj = gluNewQuadric();
		gluSphere(quadricObj, 0.5, 10, 10);
	gluDeleteQuadric(quadricObj);

	glPopMatrix();

	glutSwapBuffers();
}

GLvoid processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	} else if (key == 'w') {
		cameraAngleX += 5;
	} else if (key == 'a') {
		cameraAngleY -= 5;
	} else if (key == 's') {
		cameraAngleX -= 5;
	} else if (key == 'd') {
		cameraAngleY += 5;
	} else if (key == 'i') {
		cameraScale += 0.2;
	} else if (key == 'k') {
		cameraScale -= 0.2;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Course Work");

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(LEFT, RIGHT, DOWN, UP, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



	glTranslatef(0, 0, -2);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeScene);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();

	return 0;
}