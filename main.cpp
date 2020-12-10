#define _USE_MATH_DEFINES
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
using namespace std;
//Header
#include "player_control.h"
#include "bola_mechanic.h"
#include "asset.h"
#include "garis_putih_lapangan.h"


/// Global variables
bola bola1;

void ball_player_interaction()
{

}

static void display(void)
{
	//BACKGROUND
	glClearColor(10,10,10,10);
	glClear(GL_COLOR_BUFFER_BIT);

    lapangan();
    garis_putih_lapangan();

    bola1.bola_positionReset();
    bola1.movement();
    bola1.goal_logic();

    //player
    mainPlayer();
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
    //BERGERAK
	glutKeyboardFunc(player2_key);
	glutSpecialFunc(player1_Key);

	gluOrtho2D(0, width_Screen, 0, height_Screen);
	glutDisplayFunc(display);

	glutIdleFunc(idle);

	glutMainLoop();
	return EXIT_SUCCESS;
}
