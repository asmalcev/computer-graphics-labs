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
	glBegin(GL_POLYGON);

	glVertex3f(0.5, 0.0, 0.5);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.0, 0.0, 0.5);

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
	glutCreateWindow("work - 1");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeScene);
	// glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);
	// glutSpecialFunc(processSpecialKeys);

	glutMainLoop();

	return 0;
}