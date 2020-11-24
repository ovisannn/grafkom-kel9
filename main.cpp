#define _USE_MATH_DEFINES
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

//Header
#include "player_control.h"
#include "bola_mechanic.h"
#include "asset.h"
#include "garis_putih_lapangan.h"


/// Global variables


static void display(void)
{
	//BACKGROUND
	glClearColor(10,10,10,10);
	glClear(GL_COLOR_BUFFER_BIT);

    lapangan();
    garis_putih_lapangan();

    bola bola1;
    bola1.graphic();
    bola1.movement();

	glFlush();
	glutSwapBuffers();
}

static void idle(void)
{
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    int width_Screen = 640;
    int height_Screen = 480;

	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize((width_Screen*1.5), (height_Screen*1.5));
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("sepak bola");

	gluOrtho2D(0, width_Screen, 0, height_Screen);
	glutDisplayFunc(display);

	//BERGERAK
	glutKeyboardFunc(key);
	glutSpecialFunc(specialKey);
	glutIdleFunc(idle);

	glutMainLoop();

	return EXIT_SUCCESS;
}
