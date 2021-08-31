#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/freeglut.h>

void setup()
{

    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,700,0,600);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(4);

    glBegin(GL_LINES);
    glVertex2i(100,200);
    glVertex2i(50,80);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
