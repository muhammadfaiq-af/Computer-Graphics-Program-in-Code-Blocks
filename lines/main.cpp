#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

void setup()
{

    glClearColor(0.2,0.2,0.2,0);
    glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,640,0,700);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(4);

    glBegin(GL_POINTS);
    glVertex2i(250,300);
    glColor3f(1,0,0);
    glVertex2i(300,250);


    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    setup();

    glutDisplayFunc(display);
    glutMainLoop();
}
