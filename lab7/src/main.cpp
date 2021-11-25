#include <GL/glut.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../../stb_image.h"

#include "config.hpp"

bool keys[256];
GLuint texture;
float Zangle = 0;
GLenum filter = GL_LINEAR;

GLuint LoadTexture(const char * filename)
{
	int width, height, cnt;
	unsigned char * data = stbi_load(filename, &width, &height, &cnt, 0);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
		                            0, cnt == 4? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);
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
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

	glPushMatrix();

	glRotatef(Zangle, 0, 0, 1);

	glBegin(GL_POLYGON);
		glTexCoord2f(1, 1);
		glVertex2f(0.75, 0);

		glTexCoord2f(0, 1);
		glVertex2f(0, -0.5);

		glTexCoord2f(0, 0);
		glVertex2f(-0.75, 0);

		glTexCoord2f(1, 0);
		glVertex2f(0, 0.5);
	glEnd();

	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);

	glutSwapBuffers();
}

GLvoid processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	} else if (key == 'a') {
		Zangle += 5;
	} else if (key == 'd') {
		Zangle -= 5;
	} else if (key == '1') {
		filter = GL_LINEAR;
	} else if (key == '2') {
		filter = GL_NEAREST;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("work - 7");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	LoadTexture("textures/unnamed.bmp");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeScene);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();

	return 0;
}