#ifndef DROW_TEKS_H_INCLUDED
#define DROW_TEKS_H_INCLUDED


#include <fstream>
#include <winuser.h>
#include <string>
#include <sstream>
#include "bola_mechanic.h"


using namespace std;

void *font = GLUT_BITMAP_HELVETICA_12;
void *font2 = GLUT_BITMAP_TIMES_ROMAN_24;

void drawTextt(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(font2, string[i]);
	}
}

void drawText(std::string text, void *font, int x, int y, double R, double G, double B)
{
    glPushMatrix();
    glColor3ub(R, G, B);
    glRasterPos2i(x, y);
    for (std::string::iterator i = text.begin(); i != text.end(); ++i)
    {
        char c = *i;
        glutBitmapCharacter(font, c);
    }
    glPopMatrix();
}


void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0); //membersihkan windows
	glColor3f(0.0, 0.0, 0.0); //spesifikasi warna
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void teks(){
    //char text_score[20];
    //int tes;
    //tes = 20;
    char tes;
    int player1;
    int player2;
    int waktuuuu;

    //waktuuuu = realTime;

    player1 = player1_score;
    player2 = player2_score;
    stringstream ss;
    stringstream kk;
    ss<<player1;
    kk<<player2;
    string pemain1;
    string pemain2;
    ss>>pemain1;
    kk>>pemain2;



    drawText("Player 1", GLUT_BITMAP_TIMES_ROMAN_24, 200, 425, 255, 0, 0);
    drawText("Player 2", GLUT_BITMAP_TIMES_ROMAN_24, 370, 425, 0, 0, 255);

    drawText(pemain1, GLUT_BITMAP_TIMES_ROMAN_24, 145, 430, 255, 0, 0);
    drawText(pemain2, GLUT_BITMAP_TIMES_ROMAN_24, 485, 430, 0, 0, 255);


    //drawText(waktu, GLUT_BITMAP_TIMES_ROMAN_24, 285, 430, 0, 0, 255);
}

void teksMenu(){
    //drawText("Press F1", GLUT_BITMAP_TIMES_ROMAN_24, 50, 50, 255, 0, 0);
}

#endif // DROW_TEKS_H_INCLUDED
