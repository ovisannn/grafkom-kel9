#define _USE_MATH_DEFINES
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;
//Header
#include "player_control.h"
#include "bola_mechanic.h"
#include "asset.h"
#include "garis_putih_lapangan.h"
#include "papan_score.h"
#include "menu.h"
#include "drow_teks.h"
#include "gameover.h"

/// Global variables
bola bola1;

int timer;
int realTime;


//bool menuKey;
//menuKey = FALSE;

void waktuuuuu(){
    stringstream jj;
    jj<<realTime;
    string waktu;
    jj>>waktu;
    drawText(waktu, GLUT_BITMAP_TIMES_ROMAN_24, 315, 425, 0, 0, 255);
}

void ball_player_interaction()
{

}

static void display(void)
{
    //menuKey = FALSE;


    if (menuKey && realTime < 30) {
        //BACKGROUND
        glClearColor(10,10,10,10);
        glClear(GL_COLOR_BUFFER_BIT);

        teks();
        //drawText(realTime, GLUT_BITMAP_TIMES_ROMAN_24, 385, 430, 0, 0, 255);
        waktuuuuu();
        lapangan();
        garis_putih_lapangan();

        bola1.bola_positionReset();
        bola1.movement();
        bola1.goal_logic();
        papan_score();
        //hurufp1();
        hurufp2();
        //player
        mainPlayer();


        glFlush();
        glutSwapBuffers();

    } else{
        gameMenu();
    }

    timer+=1;
    if(timer%3000 == 0 && menuKey){
        realTime+=1;
    cout << "waktu  : " << realTime<<endl;
    }


    if(realTime > 30){
        if (player1_score > player2_score){
            //player 1 menang
        } if(player1_score < player2_score){
            //player 2 menamg
        }else{
            //drow
        }
    }

}

void Timer(int value)
{
    glutTimerFunc(200000, Timer, value);
    glutPostRedisplay();
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
	//glutSpecialFunc(menu);

	gluOrtho2D(0, width_Screen, 0, height_Screen);
	glutDisplayFunc(display);

	Timer(0);

	glutIdleFunc(idle);
    myinit();
	glutMainLoop();
	return EXIT_SUCCESS;
}
