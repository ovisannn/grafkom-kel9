#ifndef BOLA_MECHANIC_H_INCLUDED
#define BOLA_MECHANIC_H_INCLUDED
//graphic position variable
float theta;
int ball_radius = 18;
int x_position = 100;
int y_position = 100;

//collider variable
float x_currentPosRight = x_position+ball_radius;
float x_currentPosLeft = x_position-ball_radius;
float y_currentPosUp = y_position+ball_radius;
float y_currentPosDown = y_position-ball_radius;

//movement speed variable
float general_speed = 1;
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
            //glTranslatef(xSpeed,ySpeed,0);
            //collider curent position
            x_currentPosRight +=xSpeed ;
            x_currentPosLeft +=xSpeed;
            y_currentPosUp +=ySpeed ;
            y_currentPosDown +=ySpeed;
            cout<<x_currentPosLeft<<endl;
            if (x_currentPosRight >= 570 || x_currentPosLeft<=70){
                xSpeed = xSpeed*-1;
                }
            if(y_currentPosDown<=70 || y_currentPosUp>=370){
                ySpeed = ySpeed*-1;
                }
    };

    };

#endif // BOLA_MECHANIC_H_INCLUDED
