#include <GL/glut.h>

#define WINDOW_SIZE_X 500
#define WINDOW_SIZE_Y 500
#define TAM_ATUAL 4

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glOrtho(0, WINDOW_SIZE_X, 0, WINDOW_SIZE_Y, -1, 1);
}

void desenhar_quadrado(int x, int y, int tam)
{
	glBegin(GL_POLYGON);
	glVertex2f(tam * x, tam * y); // canto esquerdo inferior
	glVertex2f(tam * x, tam * (y + 1)); // canto esquerdo superior
	glVertex2f(tam * (x + 1), tam * (y + 1)); // canto direito superior
	glVertex2f(tam * (x + 1), tam * y); // canto direito inferior
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(217.0/255,217.0/255,25.0/255); // Bright Ouro
	//tÊ
	desenhar_quadrado(0,0,50);
	desenhar_quadrado(0,1,50);
	desenhar_quadrado(1,1,50);
	desenhar_quadrado(0,2,50);
	glColor3f(35.0/255,142.0/255,104.0/255); // Verde Oceano claro
	// barrinha
	desenhar_quadrado(0,4,50);
	desenhar_quadrado(1,4,50);
	desenhar_quadrado(2,4,50);
	desenhar_quadrado(3,4,50);
	glColor3f(1,28.0/255,174.0/255); // rosa temperado
	//quadrado
	desenhar_quadrado(3,0,50);
	desenhar_quadrado(3,1,50);
	desenhar_quadrado(4,0,50);
	desenhar_quadrado(4,1,50);
	glColor3f(1,0,0); // vermelho
	//éle
	desenhar_quadrado(6,0,50);
	desenhar_quadrado(6,1,50);
	desenhar_quadrado(6,2,50);
	desenhar_quadrado(7,2,50);
	glColor3f(0,0,1); // azul
	//ésse
	desenhar_quadrado(5,4,50);
	desenhar_quadrado(6,4,50);
	desenhar_quadrado(6,5,50);
	desenhar_quadrado(7,5,50);
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tetris");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
