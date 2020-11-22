#ifndef ASSET_H_INCLUDED
#define ASSET_H_INCLUDED

//TARUH KODE DI SINI

#endif // ASSET_H_INCLUDED


void segiEmpat(float titikA1, float titikB1, float titikA2, float titikB2, float titikA3, float titikB3, float titikA4, float titikB4) {
	glBegin(GL_QUADS);

	glVertex2f(titikA1, titikB1);
	glVertex2f(titikA2, titikB2);
	glVertex2f(titikA3, titikB3);
	glVertex2f(titikA4, titikB4);
	glEnd();
}

void lapangan1() {
	segiEmpat(70, 70, 120, 70, 120, 120, 70, 120);
	segiEmpat(170, 70, 220, 70, 220, 120, 170, 120);
	segiEmpat(270, 70, 320, 70, 320, 120, 270, 120);
	segiEmpat(370, 70, 420, 70, 420, 120, 370, 120);
	segiEmpat(470, 70, 520, 70, 520, 120, 470, 120);
}

void rangkai() {

	glPushMatrix();
		glColor3f(0.65, 0.75, 0.44);
		lapangan1();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.65, 0.75, 0.44);
		glTranslatef(0, 100, 0);
		lapangan1();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.65, 0.75, 0.44);
		glTranslatef(0, 200, 0);
		lapangan1();
	glPopMatrix();

	//ganti warna
	glPushMatrix();
		glColor3f(0.73, 0.86, 0.58);
		glTranslatef(50, 0, 0);
		lapangan1();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.73, 0.86, 0.58);
		glTranslatef(50, 100, 0);
		lapangan1();
	glPopMatrix();


	//gantu warna

	glPushMatrix();
		glColor3f(0.73, 0.86, 0.58);
		glTranslatef(50, 200, 0);
		lapangan1();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.55, 0.68, 0.37);
		glTranslatef(0, 50, 0);
		lapangan1();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.55, 0.68, 0.37);
		glTranslatef(0, 150, 0);
		lapangan1();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.55, 0.68, 0.37);
		glTranslatef(0, 250, 0);
		lapangan1();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.66, 0.78, 0.51);
		glTranslatef(50, 50, 0);
		lapangan1();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.66, 0.78, 0.51);
		glTranslatef(50, 150, 0);
		lapangan1();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.66, 0.78, 0.51);
		glTranslatef(50, 250, 0);
		lapangan1();
	glPopMatrix();
}

void lapangann() {
	glColor3f(0.8, 0.8, 0.8);
	segiEmpat(70, 70, 570, 70, 570, 370, 70, 370);
	//glEnd();

}

void lapangan(){
    lapangann();
	rangkai();

}
