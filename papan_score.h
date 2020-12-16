#ifndef PAPAN_SCORE_H_INCLUDED
#define PAPAN_SCORE_H_INCLUDED
void segi4(float titikA1, float titikB1, float titikA2, float titikB2, float titikA3, float titikB3, float titikA4, float titikB4) {
	glBegin(GL_QUADS);
	glVertex2f(titikA1, titikB1);
	glVertex2f(titikA2, titikB2);
	glVertex2f(titikA3, titikB3);
	glVertex2f(titikA4, titikB4);
	glEnd();
}

void segi3(float titikA1, float titikB1, float titikA2, float titikB2, float titikA3, float titikB3) {
	glBegin(GL_LINE_LOOP);
	glVertex2f(titikA1, titikB1);
	glVertex2f(titikA2, titikB2);
	glVertex2f(titikA3, titikB3);
    glEnd();
}

void segi6(float titikA1, float titikB1, float titikA2, float titikB2, float titikA3, float titikB3, float titikA4, float titikB4, float titikA5, float titikB5, float titikA6, float titikB6) {
	glBegin(GL_LINE_LOOP);
	glVertex2f(titikA1, titikB1);
	glVertex2f(titikA2, titikB2);
	glVertex2f(titikA3, titikB3);
	glVertex2f(titikA4, titikB4);
    glVertex2f(titikA5, titikB5);
    glVertex2f(titikA6, titikB6);
	glEnd();
}

void hitungMundur(){
    glColor3ub(155, 0, 0);
    segi4(310, 460, 370, 460, 370, 410, 310, 410);
    glColor3ub(105, 0, 0);
    segi3(300, 460, 340, 475,  380, 460);
}

void skorKanan(){
    glColor3ub(0, 105, 0);
    segi6(370, 450, 480, 450, 480, 435, 510, 410, 370, 410, 370, 440);
    segi6(510, 460, 540, 450, 540, 435, 510, 410, 480, 435, 480, 450);
    segi3(510, 410, 540, 435, 570, 395);
}

void skorKiri(){
    glColor3ub(0, 105, 0);
    segi6(310, 450, 200, 450, 200, 435, 170, 410, 310, 410, 310, 420);
    segi6(170, 460, 200, 450, 200, 435, 170, 410, 140, 435, 140, 450);
    segi3(110, 395, 140, 435, 170, 410);
}

void gameMenu(){
    glColor3ub(0, 0, 0);
    segi4(0, 0, 640, 0, 640, 480, 0, 480);
    glColor3ub(225, 225, 225);
    segi6(190, 210, 190, 240, 210, 250, 310, 250, 310, 220, 300, 210);
}

void papan_score(){
    glPushMatrix();
        glTranslatef(-20, 0, 0);
        hitungMundur();
        skorKanan();
        skorKiri();
	glPopMatrix();
	//gameMenu();
}

#endif // PAPAN_SCORE_H_INCLUDED
