#ifndef BOLA_MECHANIC_H_INCLUDED
#define BOLA_MECHANIC_H_INCLUDED
//graphic position variable
float theta;
int ball_radius = 10;
float x_position = 320;
float y_position = 220;

//collider variable
float x_currentPosRight = x_position+ball_radius;
float x_currentPosLeft = x_position-ball_radius;
float y_currentPosUp = y_position+ball_radius;
float y_currentPosDown = y_position-ball_radius;

//movement speed variable
float general_speed = 0.5;
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

};

#endif // BOLA_MECHANIC_H_INCLUDED
