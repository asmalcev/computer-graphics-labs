#include <GL/glut.h>

#include "config.hpp"

bool keys[256];

GLvoid resizeScene(GLsizei w, GLsizei h)
{
	if (h == 0) {
		h = 1;
	}

	glViewport(0, 0, w, h);
}

GLvoid renderScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//
	// 1st task
	//
	// glEnable(GL_POINT_SMOOTH);
	// glPointSize(250); // max ~ 250-260

	// glBegin(GL_POINTS);

	// glColor3f(1,0,0);
	// glVertex2f(0.25, 0.25);
	// glColor3f(0,1,0);
	// glVertex2f(0.25, -0.25);
	// glColor3f(0,0,1);
	// glVertex2f(-0.25, -0.25);
	// glColor3f(1,0,1);
	// glVertex2f(-0.25, 0.25);
	// glEnd();


	//
	// 2nd task
	//
	// glLineWidth(5);
	// glLineStipple(1, 0xF0F0);
	// glEnable(GL_LINE_STIPPLE);

	// glBegin(GL_LINES);

	// glColor3f(1,0,0);
	// glVertex2f(0.25, 0.25);
	// glColor3f(0,1,0);
	// glVertex2f(0.25, -0.25);
	// glVertex2f(0.25, -0.25);
	// glColor3f(0,0,1);
	// glVertex2f(-0.25, -0.25);
	// glVertex2f(-0.25, -0.25);
	// glColor3f(1,0,1);
	// glVertex2f(-0.25, 0.25);
	// glVertex2f(-0.25, 0.25);
	// glVertex2f(0.25, 0.25);
	// glEnd();


	//
	// 3rd task
	//
	// glBegin(GL_LINE_STRIP);
	// glVertex2f(-0.5, 0.5);
	// glVertex2f(0.5, 0.5);
	// glVertex2f(0, 0.25);
	// glVertex2f(0.7, 0);
	// glVertex2f(-0.5, 0);
	// glVertex2f(0, -0.25);
	// glVertex2f(-0.5, -0.6);
	// glEnd();


	//
	// 4th task
	//
	// glBegin(GL_LINE_LOOP);
	// glVertex2f(-0.4, 0.5);
	// glVertex2f(0.4, 0.5);
	// glVertex2f(0.5, 0.3);
	// glVertex2f(0.5, -0.3);
	// glVertex2f(0.25, -0.5);
	// glVertex2f(0, 0);
	// glVertex2f(-0.4, -0.5);
	// glVertex2f(-0.3, 0.3);
	// glVertex2f(-0.5, 0.4);
	// glEnd();


	//
	// 5.1th task
	//
	// glBegin(GL_TRIANGLES);
	// glVertex2f(-0.4, 0.5);
	// glVertex2f(0.4, 0.5);
	// glVertex2f(0.5, 0.3);

	// glVertex2f(-0.4, 0.5);
	// glVertex2f(-0.5, 0.4);
	// glVertex2f(-0.3, 0.3);

	// glVertex2f(0, 0);
	// glVertex2f(0.5, 0.3);
	// glVertex2f(0.5, -0.3);

	// glVertex2f(0, 0);
	// glVertex2f(0.4, 0.5);
	// glVertex2f(0.5, 0.3);

	// glVertex2f(0, 0);
	// glVertex2f(0.5, -0.3);
	// glVertex2f(0.25, -0.5);

	// glVertex2f(0, 0);
	// glVertex2f(-0.4, -0.5);
	// glVertex2f(-0.3, 0.3);

	// glVertex2f(0, 0);
	// glVertex2f(-0.3, 0.3);
	// glVertex2f(0.5, 0.3);

	// glVertex2f(-0.4, 0.5);
	// glVertex2f(-0.3, 0.3);
	// glVertex2f(0.5, 0.3);
	// glEnd();


	//
	// 5.2th task
	//
	// glBegin(GL_TRIANGLE_STRIP);
	// glVertex2f(-0.4, 0.5);
	// glVertex2f(0.4, 0.5);
	// glVertex2f(0.5, 0.3);

	// glVertex2f(0.5, -0.3);
	// glVertex2f(0.25, -0.5);
	// glVertex2f(0, 0);

	// glVertex2f(0.5, 0.3);
	// glVertex2f(0.4, 0.5);
	// glVertex2f(-0.3, 0.3);

	// glVertex2f(-0.4, -0.5);
	// glVertex2f(-0.3, 0.3);
	// glEnd();

	// glBegin(GL_TRIANGLE_STRIP);
	// glVertex2f(-0.5, 0.4);
	// glVertex2f(-0.3, 0.3);
	// glVertex2f(-0.4, 0.5);

	// glVertex2f(0.5, 0.3);
	// glEnd();


	//
	// 5.3th task
	//
	// glBegin(GL_TRIANGLE_FAN);
	// glVertex2f(-0.4, 0.5);
	// glVertex2f(-0.5, 0.4);
	// glVertex2f(-0.3, 0.3);

	// glVertex2f(-0.3, 0.3);
	// glVertex2f(0.4, 0.5);

	// glVertex2f(0.4, 0.5);
	// glVertex2f(0.5, 0.3);

	// glVertex2f(0.4, 0.5);
	// glVertex2f(0, 0);

	// glVertex2f(0.5, 0.3);
	// glVertex2f(0, 0);
	// glEnd();

	// glBegin(GL_TRIANGLE_FAN);
	// glVertex2f(0, 0);
	// glVertex2f(0.25, -0.5);
	// glVertex2f(0.5, -0.3);

	// glVertex2f(0.5, -0.3);
	// glVertex2f(0.5, 0.3);

	// glVertex2f(-0.4, -0.5);
	// glVertex2f(-0.3, 0.3);

	// glVertex2f(-0.5, 0.4);
	// glVertex2f(0.4, 0.5);
	// glEnd();

	//
	// 6th task
	//
	// glBegin(GL_POLYGON);
	// glColor3f(1,0,0);
	// glVertex2f(0.25, 0.25);
	// glColor3f(0,1,0);
	// glVertex2f(0.25, -0.25);
	// glColor3f(0,0,1);
	// glVertex2f(-0.25, -0.25);
	// glColor3f(1,0,1);
	// glVertex2f(-0.25, 0.25);
	// glEnd();

	//
	// 7th, 8.1, 8.2, 8.3 task
	//
	// glPolygonMode(GL_FRONT, GL_POINT); // 8.1

	// glPolygonMode(GL_FRONT, GL_FILL); // 8.2
	// glPolygonMode(GL_BACK, GL_LINE);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // 8.3

	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0.2);
	glVertex2f(-0.6, 0.55);
	glVertex2f(0.5, 0.48);
	glVertex2f(0.5, 0.2);
	glEnd();

	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.5, 0.2);
	glVertex2f(0.5, -0.4);
	glVertex2f(0.1, -0.5);
	glEnd();

	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex2f(0.1, -0.3);
	glVertex2f(0.1, -0.5);
	glVertex2f(-0.6, -0.5);
	glVertex2f(-0.5, -0.3);
	glEnd();

	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.3);
	glVertex2f(-0.1, -0.3);
	glVertex2f(-0.33, 0);
	glEnd();

	glFlush();
}

GLvoid processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
}

// GLvoid processSpecialKeys(int key, int x, int y) {
// 	switch(key) {
// 		default:
// 			break;
// 	}
// }

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("work - 2");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeScene);
	// glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);
	// glutSpecialFunc(processSpecialKeys);

	glutMainLoop();

	return 0;
}