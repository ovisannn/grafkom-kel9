#ifndef GARIS_PUTIH_LAPANGAN_H_INCLUDED
#define GARIS_PUTIH_LAPANGAN_H_INCLUDED

void garis_lapangan(){
    //garis tepi lapangan
    glBegin(GL_LINE_STRIP);
    //glColor3ub(125, 130, 126);
	glVertex2f(70,70);
	glVertex2f(570,70);
	glVertex2f(570,370);
	glVertex2f(70,370);
	glVertex2f(70,70);
	glEnd();

	glBegin(GL_LINE_STRIP);
	//glColor3ub(125, 130, 126);
	glVertex2f(320,70);
	glVertex2f(320,370);
	glEnd();

}

void gari_gawang(){
    glLineWidth(6);
    // garis luar gawang kiri
	glBegin(GL_LINE_STRIP);
    //glColor3ub(125, 130, 126);
	glVertex2f(70,120);
	glVertex2f(190,120);
	glVertex2f(190,320);
	glVertex2f(70,320);

	glEnd();
    // garis gawang kiri
	glBegin(GL_LINE_STRIP);
    //glColor3ub(125, 130, 126);
	glVertex2f(70,145);
	glVertex2f(140,145);
	glVertex2f(140,295);
	glVertex2f(70,295);
	glEnd();

	// garis luar gawang kanan
	glBegin(GL_LINE_STRIP);
    //glColor3ub(125, 130, 126);
	glVertex2f(570,120);
	glVertex2f(450,120);
	glVertex2f(450,320);
	glVertex2f(570,320);
	glEnd();
    // garis gawang kanan
    glBegin(GL_LINE_STRIP);
    //glColor3ub(125, 130, 126);
    glVertex2f(570,145);
	glVertex2f(500,145);
	glVertex2f(500,295);
	glVertex2f(570,295);
	glEnd();

}
const double PI=3.141592653589793;
int i;

void garis_lingkaran(int jari2, int jumlah_titik, int x_tengah, int y_tengah){
 glBegin(GL_LINE_STRIP);
 for (i=0;i<=360;i++){
 float sudut=i*(2*PI/jumlah_titik);
 float x=x_tengah+jari2*cos(sudut);
 float y=y_tengah+jari2*sin(sudut);
 glVertex2f(x,y);
 }
 glEnd();
 }

 void garis_putih_lapangan(){
    glColor3ub(230, 230, 230);
    garis_lapangan();
    gari_gawang();
    garis_lingkaran(63,63,320,220);

}


#endif // GARIS_PUTIH_LAPANGAN_H_INCLUDED
