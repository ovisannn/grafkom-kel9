#ifndef PLAYER_CONTROL_H_INCLUDED
#define PLAYER_CONTROL_H_INCLUDED
//player 1 movement control
//player 2 movement control
float player_speed = 30;
float playerx_speed = player_speed;
float playery_speed = player_speed;

//variable konfirmasi
bool move1_kanan;
bool move1_kiri;
bool move1_atas;
bool move1_bawah;

bool move2_kanan;
bool move2_kiri;
bool move2_atas;
bool move2_bawah;

//player collider
//1 untuk player 1 dan 2 untuk player 2
float Ax_1 = 450, Ax_2 = 180;
float Ay_1 = 240, Ay_2 = 240;
float Bx_1 = 460, Bx_2 = 190;
float By_1 = 240, By_2 = 240;
float Cx_1 = 460, Cx_2 = 190;
float Cy_1 = 200, Cy_2 = 200;
float Dx_1 = 450, Dx_2 = 180;
float Dy_1 = 200, Dy_2 = 200;


//mini ball collider
float Aplayer1_ballx = 455, Aplayer2_ballx = 185;
float Bplayer1_ballx = 455, Bplayer2_ballx = 185;

float Aplayer1_bally = 200, Aplayer2_bally = 200;
float Bplayer1_bally = 240, Bplayer2_bally = 240;

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

static void gerak1_horizontal(float a){
        Ax_1 +=playerx_speed*a;
        Bx_1 +=playerx_speed*a;
        Cx_1 +=playerx_speed*a;
        Dx_1 +=playerx_speed*a;
        Aplayer1_ballx +=playerx_speed*a;
        Bplayer1_ballx +=playerx_speed*a;

}

static void gerak1_vertical(float a){
        Ay_1 +=playery_speed*a;
        By_1 +=playery_speed*a;
        Cy_1 +=playery_speed*a;
        Dy_1 +=playery_speed*a;
        Aplayer1_bally +=playery_speed*a;
        Bplayer1_bally +=playery_speed*a;
}

static void gerak2_horizontal(float a){
        Ax_2 +=playerx_speed*a;
        Bx_2 +=playerx_speed*a;
        Cx_2 +=playerx_speed*a;
        Dx_2 +=playerx_speed*a;
        Aplayer2_ballx +=playerx_speed*a;
        Bplayer2_ballx +=playerx_speed*a;

}

static void gerak2_vertical(float a){
        Ay_2 +=playery_speed*a;
        By_2 +=playery_speed*a;
        Cy_2 +=playery_speed*a;
        Dy_2 +=playery_speed*a;
        Aplayer2_bally +=playery_speed*a;
        Bplayer2_bally +=playery_speed*a;
}

static void player1_wall_collide(){
    if (Ax_1 <= 70){move1_kiri = FALSE;}else{move1_kiri = TRUE;}
    if (Bx_1 >= 570){move1_kanan = FALSE;}else{move1_kanan = TRUE;}
    if (Ay_1 >= 370){move1_atas = FALSE;}else{move1_atas = TRUE;}
    if (Cy_1 <= 70){move1_bawah = FALSE;}else{move1_bawah = TRUE;}
}

static void player2_wall_collide(){
    if (Ax_2 <= 70){move2_kiri = FALSE;}else{move2_kiri = TRUE;}
    if (Bx_2 >=570){move2_kanan = FALSE;}else{move2_kanan = TRUE;}
    if (Ay_2 >=370){move2_atas = FALSE;}else{move2_atas = TRUE;}
    if (Cy_2 <=70){move2_bawah = FALSE;}else{move2_bawah = TRUE;}
}


static void player2_key(unsigned char key, int x, int y)
    {
        switch (key) {
        case 'w':
            if(move2_atas == TRUE){gerak2_vertical(1);}
            break;
        case 'a':
            if(move2_kiri == TRUE){gerak2_horizontal(-1);}
            break;
        case 's':
            if(move2_bawah == TRUE){gerak2_vertical(-1);}
            break;
        case 'd':
            if(move2_kanan == TRUE){gerak2_horizontal(1);}
            break;
        }
    }

static void player1_Key(int key, int x, int y)
    {
        switch (key) {
        case GLUT_KEY_UP:
            if(move1_atas == TRUE){gerak1_vertical(1);}
            break;
        case GLUT_KEY_LEFT:
            if(move1_kiri == TRUE){gerak1_horizontal(-1);}
            break;
        case GLUT_KEY_DOWN:
            if(move1_bawah == TRUE){gerak1_vertical(-1);}
            break;
        case GLUT_KEY_RIGHT:
            if(move1_kanan == TRUE){gerak1_horizontal(1);}
            break;
        }
    }

void players(){
        glPushMatrix();
            glColor3ub(255, 0, 0);
            //glTranslatef(sx, sy, 0);
            grapichPlayer(
                Ax_1, Ay_1,
                Bx_1, By_1,
                Cx_1, Cy_1,
                Dx_1, Dy_1);
            radius(5,10,Aplayer1_ballx,Aplayer1_bally);
            radius(5,10,Bplayer1_ballx,Bplayer1_bally);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0, 0, 255);
            //glTranslatef(kx, ky, 0);
            grapichPlayer(
                Ax_2, Ay_2,
                Bx_2, By_2,
                Cx_2, Cy_2,
                Dx_2, Dy_2);
            radius(5,10,Aplayer2_ballx,Aplayer2_bally);
            radius(5,10,Bplayer2_ballx,Bplayer2_bally);
        glPopMatrix();
    }

void mainPlayer(){
    players();
    player1_wall_collide();
    player2_wall_collide();
}


#endif // PLAYER_CONTROL_H_INCLUDED
