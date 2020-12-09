#ifndef BOLA_MECHANIC_H_INCLUDED
#define BOLA_MECHANIC_H_INCLUDED
#include "player_control.h"

//main variable
int player1_score = 0;
int player2_score = 0;

//graphic position variable
float theta;
int ball_radius = 15;
float x_position = 320;
float y_position = 220;

//collider variable
float x_currentPosRight = x_position+ball_radius;
float x_currentPosLeft = x_position-ball_radius;
float y_currentPosUp = y_position+ball_radius;
float y_currentPosDown = y_position-ball_radius;

//movement speed variable
float general_speed = 0.25;
float xSpeed = general_speed;
float ySpeed = general_speed;

class bola {
public:

//grafik bola
    void graphic(){
        //gambar
        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        for (int i= 0; i<360; i++){
            theta = i*3.142/180;
            float x_ball = ball_radius*cos(theta);
            float y_ball = ball_radius*sin(theta);
            glVertex2f((x_position+x_ball),(y_position+y_ball));
        };
        glEnd();
    };



//pergerakan bola
    void movement(){
            graphic();
            x_position +=xSpeed;
            y_position +=ySpeed;

            x_currentPosRight +=xSpeed ;
            x_currentPosLeft +=xSpeed;
            y_currentPosUp +=ySpeed ;
            y_currentPosDown +=ySpeed;

            if (x_currentPosRight >= 570 || x_currentPosLeft<=70){
                xSpeed = xSpeed*-1;
                }
            if(y_currentPosDown<=70 || y_currentPosUp>=370){
                ySpeed = ySpeed*-1;
                }

            if(((x_currentPosRight>=Ax_1 && x_currentPosRight<=Bx_1)&&(y_position >= Dy_1 && y_position <= Ay_1))||((x_currentPosLeft>=Ax_2 && x_currentPosLeft<=Bx_2)&&(y_position >= Dy_2 && y_position <= Ay_2))){
                xSpeed = xSpeed*-1;
            }

            if(((x_currentPosLeft>=Ax_1 && x_currentPosLeft<=Bx_1)&&(y_position >= Dy_1 && y_position <= Ay_1))||((x_currentPosRight>=Ax_2 && x_currentPosRight<=Bx_2)&&(y_position >= Dy_2 && y_position <= Ay_2))){
                xSpeed = xSpeed*-1;
            }
            if(((y_currentPosUp>=Ay_2 && y_currentPosUp<=Dy_2)&&(x_position >= Dx_2 && x_position <= Cx_2))||((y_currentPosUp>=Ay_1 && y_currentPosUp<=Dy_1)&&(x_position >= Dx_1 && x_position <= Cx_1))){
                ySpeed = ySpeed*-1;
            }

            if(((y_currentPosDown>=Ay_1 && y_currentPosDown<=Dy_1)&&(x_position >= Dx_1 && x_position <= Cy_1))||((y_currentPosDown>=Ay_2 && y_currentPosDown<=Dy_2)&&(x_position >= Dx_2 && x_position <= Cy_2))){
                ySpeed = ySpeed*-1;
            }
    };


    void bola_positionReset(){
        if ( ( (x_currentPosLeft <= 70) || (x_currentPosRight >= 570) )&& ( (y_currentPosUp <= 270 && y_currentPosUp >= 170) || (y_currentPosDown <= 270 && y_currentPosDown >= 170) ) ){
            x_position = 320;
            y_position = 220;
            x_currentPosRight = x_position+ball_radius;
            x_currentPosLeft = x_position-ball_radius;
            y_currentPosUp = y_position+ball_radius;
            y_currentPosDown = y_position-ball_radius;
        }

    };

    void goal_logic(){
    if (x_currentPosLeft <= 70 && (y_currentPosUp <= 270 && y_currentPosUp >= 170)){player1_score += 1;}
    if (x_currentPosLeft >= 750 && (y_currentPosUp <= 270 && y_currentPosUp >= 170)){player2_score += 1;}
    }

};

#endif // BOLA_MECHANIC_H_INCLUDED
