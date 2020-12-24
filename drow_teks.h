#ifndef DROW_TEKS_H_INCLUDED
#define DROW_TEKS_H_INCLUDED


#include <fstream>
#include <winuser.h>
#include <string>
#include <sstream>
#include "bola_mechanic.h"

//import semua dependency atau library yang dibutuhkan

using namespace std;

// Deklarasi variabel beserta tipe data yang dimilikinya

void *font = GLUT_BITMAP_HELVETICA_12; //inisialisasi font teks yang digunakan
void *font2 = GLUT_BITMAP_TIMES_ROMAN_24;

//function menampilkan teks pada window openGL
void drawTextt(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(font2, string[i]);
	}
}

void drawText(std::string text, void *font, int x, int y, double R, double G, double B)
{
    // https://stackoverflow.com/questions/14318/using-glut-bitmap-fonts
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

    tes = 10;
    drawText("tes", GLUT_BITMAP_HELVETICA_18, 0, 93, 0, 0, 0);
}



#endif // DROW_TEKS_H_INCLUDED
