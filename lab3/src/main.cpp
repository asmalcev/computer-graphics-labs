#include <GL/glut.h>

#include "config.hpp"

constexpr GLint N = 3;

bool keys[256];
// GLfloat aVertex[N][2] = {{-0.25, 0.25}, {0.25, 0.25},{ 0.25, -0.25}, {-0.25, -0.25}};
GLfloat aVertex[N][2] = {{-0.12, 0.16}, {0.12, 0.16}, { 0, 0.64}};

constexpr GLfloat kx = 2.5, ky = 0.5;
constexpr GLfloat px = 2, py = 5;
constexpr GLfloat alpha = -30, beta = 35;
constexpr GLfloat x = 13, y = 7;


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
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glColor3f(1, 1, 1);

	// glDrawArrays(GL_POLYGON, 0, 4);   // 1.a
	// glDrawArrays(GL_QUADS, 0, 4);     // 1.b
	// glDrawArrays(GL_TRIANGLES, 0, 4); // 1.c
	// glDrawArrays(GL_LINES, 0, 4);     // 1.d

	// 2
	// glPushMatrix();
	// 	glScalef(kx, ky, 1);
	// 	glTranslatef(px, py, 1);
	// 	glDrawArrays(GL_TRIANGLES, 0, 3);
	// glPopMatrix();

	// glPushMatrix();
	// 	glRotatef(alpha, 0, 0, 1);
	// 	glDrawArrays(GL_LINES, 0, 2);
	// glPopMatrix();

	// glPushMatrix();
	// 	glRotatef(beta, x, y, 1);
	// 	glDrawArrays(GL_QUADS, 0, 4);
	// glPopMatrix();

	// 3
	glPushMatrix();
		glBegin(GL_LINES);
			glArrayElement(0);
			glArrayElement(1);
			glArrayElement(1);
			glArrayElement(2);
			glArrayElement(2);
			glArrayElement(0);
		glEnd();
		glRotatef(72, 0, 0, 1);
		glBegin(GL_LINES);
			glArrayElement(0);
			glArrayElement(1);
			glArrayElement(1);
			glArrayElement(2);
			glArrayElement(2);
			glArrayElement(0);
		glEnd();
		glRotatef(72, 0, 0, 1);
		glBegin(GL_LINES);
			glArrayElement(0);
			glArrayElement(1);
			glArrayElement(1);
			glArrayElement(2);
			glArrayElement(2);
			glArrayElement(0);
		glEnd();
		glRotatef(72, 0, 0, 1);
		glBegin(GL_LINES);
			glArrayElement(0);
			glArrayElement(1);
			glArrayElement(1);
			glArrayElement(2);
			glArrayElement(2);
			glArrayElement(0);
		glEnd();
		glRotatef(72, 0, 0, 1);
		glBegin(GL_LINES);
			glArrayElement(0);
			glArrayElement(1);
			glArrayElement(1);
			glArrayElement(2);
			glArrayElement(2);
			glArrayElement(0);
		glEnd();
	glPopMatrix();

	glFlush();
}

GLvoid processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("work - 3");

	glEnableClientState(GL_VERTEX_ARRAY);
	glMatrixMode(GL_MODELVIEW);
	glVertexPointer(2, GL_FLOAT, 0, aVertex);


	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeScene);

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();

	return 0;
}