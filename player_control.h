#ifndef PLAYER_CONTROL_H_INCLUDED
#define PLAYER_CONTROL_H_INCLUDED

int kx = 0, ky = 0; /// kotak
int sx = 0, sy = 0; /// segitia
int speed = 30;

void grapichPlayer(float titikA1, float titikB1, float titikA2, float titikB2, float titikA3, float titikB3, float titikA4, float titikB4) {
	glBegin(GL_QUADS);

	glVertex2f(titikA1, titikB1);
	glVertex2f(titikA2, titikB2);
	glVertex2f(titikA3, titikB3);
	glVertex2f(titikA4, titikB4);
	glEnd();
}

void radius(int jari2, int jumlah_titik, int x_tengah, int y_tengah){
     const double PI=3.141592653589793;
     int i;

     glBegin(GL_POLYGON);
     for (i=0;i<=360;i++){
         float sudut=i*(2*PI/jumlah_titik);
         float x=x_tengah+jari2*cos(sudut);
         float y=y_tengah+jari2*sin(sudut);
         glVertex2f(x,y);
     }
     glEnd();
 }
//class Player{
//public:

static void key(unsigned char key, int x, int y)
    {
        switch (key) {
        case 'w':
            ky += speed;
            break;
        case 'a':
            kx -= speed;
            break;
        case 's':
            ky -= speed;
            break;
        case 'd':
            kx += speed;
            break;
        }
    }

static void specialKey(int key, int x, int y)
    {
        switch (key) {
        case GLUT_KEY_UP:
            sy += speed;
            break;
        case GLUT_KEY_LEFT:
            sx -= speed;
            break;
        case GLUT_KEY_DOWN:
            sy -= speed;
            break;
        case GLUT_KEY_RIGHT:
            sx += speed;
            break;
        }
    }

    void players(){
        glPushMatrix();
            glColor3ub(255, 0, 0);
            glTranslatef(0, -25, 0);
            glTranslatef(sx, sy, 0);
            grapichPlayer(450, 265, 460, 265, 460, 225, 450, 225);
            radius(5,10,455,225);
            radius(5,10,455,265);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0, 0, 255);
            glTranslatef(-270, -25, 0);
            glTranslatef(kx, ky, 0);
            grapichPlayer(450, 265, 460, 265, 460, 225, 450, 225);
            radius(5,10,455,225);
            radius(5,10,455,265);
        glPopMatrix();
    }

//};

void mainPlayer(){
    players();
}


#endif // PLAYER_CONTROL_H_INCLUDED
