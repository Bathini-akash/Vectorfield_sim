#include <stdio.h>
#include <glut.h>

int X1, X2, Y1, Y2;
void init();
void plotPixel(int x, int y);
void plotDisplay();
void printLine(int X1, int Y1, int X2, int Y2);

int main(int argc, char **argv) {
	printf("Enter x1, y1; x2, y2 : ");
	scanf_s("%d %d %d %d", &X1, &Y1, &X2, &Y2);
	//used to initialise glut library
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Line drawing algorithm");//create a window to draw and names it as the parameter given inside the function
	//call to the init function
	init();
	glutDisplayFunc(plotDisplay);
	glutMainLoop();

	return 0;
}

void init() {
	glClear(GL_COLOR_BUFFER_BIT);//clears the color buffer, equivalent to erasing the black boarding before writing.
	glClearColor(0.0, 0.0, 0.0, 1.0);//clears the color buffer.
	glMatrixMode(GL_PROJECTION);//specifies which matrix stack is targetted, in this case it is the projection matrix stack.
	gluOrtho2D(0, 500, 0, 500);//defines a 2D orthographic projecion matrix sets up a 2D orthographic viewing region. Its parameters are used to clip the plane.
}

void plotPixel(int x, int y){
	//glBegin specifies the way in which the vertices are to be interpreted, its argument gives the value
	//GL_POINTS treats each vertex as a single point
	//glVertex is used to check specifie a vertex
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void plotDisplay() {
	printLine(X1, Y1, X2, Y2);
	glFlush();//force executes GL commands until this func is called
}

void printLine(int X1, int Y1, int X2, int Y2) {
	//x1, x2, y1, y2 are the end vertices of the line to be drawn
	int x = X1, y = Y1;
	int dx, dy;
	int incX = 1, incY = 1;
	int incE, incNE;
	int d;

	dx = X2 - X1;
	dy = Y2 - Y1;

	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	if (X2 < X1)
		incX = -1;
	if (Y2 < Y1)
		incY = -1;

	if (dx > dy) {
		plotPixel(x,y);
		d = 2 * dy - dx;
		incNE = 2 * (dy - dx);
		incE = 2 * dy;

		for (int i = 0; i < dx; i++) {
			if (d < 0) {
				x += incX;
				d += incE;
			}
			else {
				y += incY;
				d += incNE;
			}
			plotPixel(x, y);
		}
	
	}
}	
