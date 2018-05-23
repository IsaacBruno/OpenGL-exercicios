#include <GL/glut.h>

int angle = 0;
int posX = 0;
int posY = 0;

int loopPosX = 0;
int loopPosY = 0;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glOrtho(0, 500, 0, 500, -1, 1);
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key) {
	case 'a':
		posX -= 20;
		break;
	case 'd':
		posX += 20;
		break;
	case 'w':
		posY += 20;
		break;
	case 's':
		posY -= 20;
		break;
	case 32:
		//rotacionar 90º
		angle -= 90;
		break;
	}
	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
		glTranslatef(posX, posY, 0);
		glRotatef(angle, 0, 0, 1);
		
		glColor3f(0, 1, 0);
		glBegin(GL_POLYGON);
			glVertex2i(0, 0);
			glVertex2i(0, 20);
			glVertex2i(20, 20);
			glVertex2i(20, 0);
		glEnd();
		
		glColor3f(0, 0, 1);
		glBegin(GL_POLYGON);
			glVertex2i(0, 20);
			glVertex2i(0, 40);
			glVertex2i(20, 40);
			glVertex2i(20, 20);
		glEnd();
		
		glColor3f(1, 0, 1);
		glBegin(GL_POLYGON);
			glVertex2i(0, 40);
			glVertex2i(0, 60);
			glVertex2i(20, 60);
			glVertex2i(20, 40);
		glEnd();
		
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
			glVertex2i(20, 40);
			glVertex2i(20, 60);
			glVertex2i(40, 60);
			glVertex2i(40, 40);
		glEnd();
	glPopMatrix();
	
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Keyboard examples");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
