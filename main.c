#include <GL\glew.h>
#include <GL\freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

long long circle_points=0, square_points=0;
long double pi = 0;
long long iterations = 0;

void displayMe(void) {
	if (iterations % 1000 == 0) {
		system("cls");
		//glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0, 1, 0);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i <= 300; i++) {
			double angle = 2 * PI * i / 300;
			double x = cos(angle);
			double y = sin(angle);
			glVertex2d(x, y);
		}
		glEnd();
		pi = (4.0L * ((long double)circle_points / (long double)square_points));
		printf("Iterations: %lld\nNumber of points: %lld\nNumber of points in circle: %lld\n",iterations , square_points, circle_points);
		printf("Pi: %.50Lf\n\n\n", pi);
	}
	iterations++;
	float x = (-1 + 2 * ((float)rand()) / RAND_MAX);
	float y = (-1 + 2 * ((float)rand()) / RAND_MAX);
	float d = (x * x + y * y);
	if (d <= 1) {
		glColor3f(1, 0, 0);
		circle_points++;
	}
	else {
		glColor3f(1, 1, 1);
	}
	square_points++;
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("Monte-Carlo");
	glutDisplayFunc(displayMe);
	glPointSize(1);
	glutMainLoop();
	return 0;
}