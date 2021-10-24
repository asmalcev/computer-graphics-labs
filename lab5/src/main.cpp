#include <GL/glut.h>
#include <stdio.h>

#include "config.hpp"

bool keys[256];

float scale_coefficient = 1,
      rotateX_angle     = 0,
      rotateY_angle     = -90;

float camera_x = 0,
      camera_y = 0;

GLUquadricObj * quadricObj;

GLvoid resizeScene(GLsizei w, GLsizei h)
{
	if (h == 0) {
		h = 1;
	}

	glViewport(0, 0, w, h);
}

GLvoid moveCamera() {
	glTranslatef(camera_x, camera_y, 0);
}

GLvoid renderScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	moveCamera();

	glPushMatrix();
	glScalef(1 * scale_coefficient, 1 * scale_coefficient, 1 * scale_coefficient);
	glRotatef(rotateX_angle, 0, 1, 0);
	glRotatef(rotateY_angle, 1, 0, 0);

	quadricObj = gluNewQuadric();
		gluSphere(quadricObj, 0.2, 10, 10);
		gluCylinder(quadricObj, 0.4, 0.1, 0.3, 10, 10);

		glTranslatef(0, 0, -0.39);
		gluCylinder(quadricObj, 0.05, 0.05, 0.2, 10, 1);
		gluCylinder(quadricObj, 0.2, 0.05, 0.025, 10, 1);

		glTranslatef(0, 0, -0.025);
		gluCylinder(quadricObj, 0.2, 0.2, 0.025, 10, 1);
	gluDeleteQuadric(quadricObj);

	glPopMatrix();

	glutSwapBuffers();
}

GLvoid processNormalKeys(unsigned char key, int x, int y) {
	// printf("%d %c\n", key, key);
	if (key == 27) {
		exit(0);
	} else if (key == 43 || key == 61) {
		// upscale
		scale_coefficient += scale_step;
	} else if (key == 95 || key == 45) {
		// downscale
		scale_coefficient -= scale_step;
	} else if (key == 119) {
		// w
		rotateY_angle += angle_step;
	} else if (key == 115) {
		// s
		rotateY_angle -= angle_step;
	} else if (key == 97) {
		// a
		rotateX_angle += angle_step;
	} else if (key == 100) {
		// d
		rotateX_angle -= angle_step;
	} else if (key == 105) {
		// i
		camera_y += camera_step;
	} else if (key == 106) {
		// j
		camera_x -= camera_step;
	} else if (key == 107) {
		// k
		camera_y -= camera_step;
	} else if (key == 108) {
		// l
		camera_x += camera_step;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("work - 5");

	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glFrustum(-1, 1, -1, 1, 3, 8);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeScene);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();

	return 0;
}