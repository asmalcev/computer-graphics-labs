#include <GL/glut.h>
#include <iostream>

#include "config.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../../stb_image.h"



/*
 *
 *
 * DEFINITIONS BLOCK
 *
 *
 */



constexpr float clearColorR = 5 / 255.0f;
constexpr float clearColorG = 5 / 255.0f;
constexpr float clearColorB = 5 / 255.0f;

constexpr float BORDER = 3.0f;
constexpr float LEFT = -BORDER, RIGHT = BORDER, DOWN = -BORDER, UP = BORDER;

constexpr float scaleSpeed = 0.01;
constexpr float angleSpeed = 5;

float cameraScale = 1;
float cameraAngleX = 155;
float cameraAngleY = 0;
float cameraAngleZ = 40;

float timeSpeed = 0.001;
float timeCounter = 0;

GLuint earthTexture;
GLuint moonTexture;



GLuint loadTexture(const char * filename);

void moveCamera();

GLvoid resizeScene(GLsizei w, GLsizei h);
GLvoid renderScene(GLvoid);
GLvoid processNormalKeys(unsigned char key, int x, int y);



/*
 *
 *
 * IMPLEMENTATIONS BLOCK
 *
 *
 */

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Course Work - Our Home");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(LEFT, RIGHT, DOWN, UP, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	earthTexture = loadTexture("textures/earth.jpg");
	moonTexture = loadTexture("textures/moon.jpg");



	glTranslatef(0, 0, -5);

	glClearColor(clearColorR, clearColorG, clearColorB, 1);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeScene);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();

	return 0;
}


GLuint loadTexture(const char * filename)
{
	GLuint texture;
	int width, height, cnt;
	unsigned char * data = stbi_load(filename, &width, &height, &cnt, 0);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
																0, cnt == 4? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);

	return texture;
}

void moveCamera()
{
	glRotatef(cameraAngleX, 1, 0, 0);
	glRotatef(cameraAngleY, 0, 1, 0);
	glRotatef(cameraAngleZ, 0, 0, 1);

	glScalef(cameraScale, cameraScale, cameraScale);
}

GLvoid resizeScene(GLsizei w, GLsizei h)
{
	if (h == 0) {
		h = 1;
	}

	glViewport(0, 0, w, h);
}

GLvoid processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27) {
		exit(0);
	} else if (key == 'w') {
		cameraAngleX += angleSpeed;
	} else if (key == 'a') {
		cameraAngleY -= angleSpeed;
	} else if (key == 's') {
		cameraAngleX -= angleSpeed;
	} else if (key == 'd') {
		cameraAngleY += angleSpeed;
	} else if (key == 'q') {
		cameraAngleZ -= angleSpeed;
	} else if (key == 'e') {
		cameraAngleZ += angleSpeed;
	} else if (key == 'i') {
		if (cameraScale + scaleSpeed <= 1) {
			cameraScale += scaleSpeed;
		}
	} else if (key == 'k') {
		if (cameraScale - scaleSpeed >= 0.2) {
			cameraScale -= scaleSpeed;
		}
	}
}

GLvoid renderScene(GLvoid)
{
	GLUquadricObj * quadricObj;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glPushMatrix();


	moveCamera();



	quadricObj = gluNewQuadric();
		glBindTexture(GL_TEXTURE_2D, earthTexture);

		gluQuadricTexture(quadricObj, GL_TRUE);
		gluQuadricDrawStyle(quadricObj, GLU_FILL);

		gluSphere(quadricObj, 4, 50, 50);

		glBindTexture(GL_TEXTURE_2D, 0);
	gluDeleteQuadric(quadricObj);

	glPopMatrix();

	glutSwapBuffers();
}