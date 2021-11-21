#include <GL/glut.h>

#include "config.hpp"

bool keys[256];

constexpr float LEFT = -1, RIGHT = 1, DOWN = -1, UP = 1;
constexpr float ambient[] = {0.3, 0.6, 0.2, 1};
float coords[] = {0, 0, 0};

constexpr float light_pos1[] = {0, 0, -1, 0}, light_pos2[] = {1, 0, 0, 1};

constexpr float color[4] = {0, 1, 0, 1};
constexpr float shine[1] = {39};

GLUquadricObj * quadricObj;

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

	glTranslatef(coords[0], coords[1], coords[2]);

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos1);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos2);

	quadricObj = gluNewQuadric();
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
		gluSphere(quadricObj, 1, 20, 20);

		glTranslatef(-15, 9, 2.2);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shine);
		gluSphere(quadricObj, 6, 10, 10);
	gluDeleteQuadric(quadricObj);

	glPopMatrix();

	glutSwapBuffers();
}

GLvoid processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	} else if (key == 'w') {
		coords[2] += 1;
	} else if (key == 'a') {
		coords[0] += 1;
	} else if (key == 's') {
		coords[2] -= 1;
	} else if (key == 'd') {
		coords[0] -= 1;
	}
	// std::cout << (int) key << " " << key << std::endl;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("work - 6");

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(LEFT, RIGHT, DOWN, UP, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

	glTranslatef(0, 0, -20);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeScene);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();

	return 0;
}