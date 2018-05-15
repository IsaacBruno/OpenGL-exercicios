#include <GL/glut.h>

#define TAM_ATUAL 5

// global variables :'(
int alternar_cor = 1;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glOrtho(0, 500, 0, 500, -1, 1);
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

void desenhar_tabuleiro(int n, float color1[], float color2[])
{
	int i, j, muda_cor = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if (muda_cor) {
				glColor3f(color1[0], color1[1], color1[2]);
				muda_cor = 0;
			} else {
				glColor3f(color2[0], color2[1], color2[2]);
				muda_cor = 1;
			}
			desenhar_quadrado(i, j, 40);
		}
		if (n % 2 == 0) {
			muda_cor = !muda_cor;
		}
	}
}

void keyboard(unsigned char key, int x, int y)
{

	switch(key) {
		float c1[3], c2[3];
	case 32:
		// limpar buffers para valores predefinidos
		glClear(GL_COLOR_BUFFER_BIT);
		if (alternar_cor) {
			c1[0] = c1[1] = c1[2] = 1;
			c2[0] = 139 / 255.0;
			c2[1] = 69 / 255.0;
			c2[2] = 19 / 255.0;
			desenhar_tabuleiro(TAM_ATUAL, c1, c2);
			alternar_cor = 0;
		} else {
			c1[0] = c1[1] = 1;
			c1[2] = 0;
			c2[0] = c2[2] = 0;
			c2[1] = 1;
			desenhar_tabuleiro(TAM_ATUAL, c1, c2);
			alternar_cor = 1;
		}
		// força a execução dos comandos da OpenGL
		glFlush();
		break;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	float c1[] = {1, 1, 0};
	float c2[] = {0, 1, 0};
	desenhar_tabuleiro(TAM_ATUAL, c1, c2);
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tabuleiro");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
