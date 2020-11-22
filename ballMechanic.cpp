#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#define PI 3.14159265f
#include <math.h>
#include <windows.h>

//global variable area
GLfloat ballRadius = 0.5f;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
GLfloat ballXmax, ballXmin, ballYmax, ballYmin;
GLfloat xSpeed = 0.02f;
GLfloat ySpeed = 0.007f;
int refreshMillis = 30;

//clipping area
static void ballMechanic(void){

}
