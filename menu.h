#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED





void seg4(float titikA1, float titikB1, float titikA2, float titikB2, float titikA3, float titikB3, float titikA4, float titikB4) {
	glLineWidth(3);
	glBegin(GL_QUADS);
	glVertex2f(titikA1, titikB1);
	glVertex2f(titikA2, titikB2);
	glVertex2f(titikA3, titikB3);
	glVertex2f(titikA4, titikB4);
	glEnd();
}


void button(){
    glBegin(GL_QUADS);
        glColor3ub(0, 158, 18);
        glVertex2f(225, 185);
        glVertex2f(375, 185);
        glColor3ub(115, 255, 131);
        glVertex2f(375, 215);
        glVertex2f(225, 215);
    glEnd();
    //seg4(225, 215, 225, 185, 375, 185, 375, 215);
    glColor3b(0, 0, 0);
    seg4(220, 210, 225, 210, 225, 190, 220, 190);
    seg4(225, 185, 230, 185, 230, 190, 225, 190);
    seg4(225, 210, 230, 210, 230, 215, 225, 215);

    seg4(230, 185, 230, 180, 370, 180, 370, 185);
    seg4(230, 220, 230, 215, 370, 215, 370, 220);

    seg4(370, 185, 375, 185, 375, 190, 370, 190);
    seg4(375, 190, 380, 190, 380, 210, 375, 210);
    seg4(370, 210, 375, 210, 375, 215, 370, 215);
}

void play(){
    seg4(265, 207, 265, 211, 252, 211, 252, 207);
    seg4(252, 207, 252, 190, 256, 190, 256, 207);
    seg4(256, 194, 265, 194, 265, 198, 256, 198);
    seg4(265, 198, 269, 198, 269, 207, 265, 207);

    seg4(282, 212, 278, 212, 278, 190, 282, 190);
    seg4(294, 190, 294, 194, 282, 194, 282, 190);

    seg4(308, 207, 304, 207, 304, 190, 308, 190);
    seg4(308, 198, 317, 198, 317, 202, 308, 202);
    seg4(308, 207, 317, 207, 317, 211, 308, 211);
    seg4(317, 190, 321, 190, 321, 207, 317, 207);

    seg4(334, 211, 330, 211, 330, 198, 334, 198);
    seg4(334, 198, 344, 198, 344, 202, 334, 202);
    seg4(344, 198, 348, 198, 348, 211, 344, 211);
    seg4(337, 190, 341, 190, 341, 198, 337, 198);
}


void gameMenu(){

    glClearColor(10,10,10,10);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glColor3ub(0, 0, 0);
        glTranslatef(20, 15, 0);
        button();
        play();
	glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

#endif // MENU_H_INCLUDED
