#ifndef PLAYER_CONTROL_H_INCLUDED
#define PLAYER_CONTROL_H_INCLUDED

int kx = 0, ky = 0; /// kotak
int sx = 0, sy = 0; /// segitia
int speed = 30;
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

static void specialKey(int key, int x, int y) {
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


#endif // PLAYER_CONTROL_H_INCLUDED
