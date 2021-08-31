#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<time.h>
#define PI 3.14

void setup()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-400,400, -300,300, -300,300);
    gluPerspective(130,800/600.0,1,2000);
    gluLookAt(200,200,2000,0,0,0,0,1,0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glRotatef(0.01,1,0,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3i(-100,100,100);
    glVertex3i(100,100,100);
    glVertex3i(100,-100,100);
    glVertex3i(-100,-100,100);

    glColor3f(0,0,0);

    glVertex3i(-100,100,-100);
    glVertex3i(-100,-100,-100);
    glVertex3i(-100,-100,100);
    glVertex3i(-100,100,100);

    glColor3f(1,0,0);

    glVertex3i(-100,100,-100);
    glVertex3i(100,100,100);
    glVertex3i(100,-100,100);
    glVertex3i(-100,-100,100);

    glColor3f(1,0,1);

    glVertex3i(100,100,-100);
    glVertex3i(100,-100,-100);
    glVertex3i(100,-100,100);
    glVertex3i(100,100,100);

    glColor3f(0,1,0);

    glVertex3i(-100,100,-100);
    glVertex3i(100,100,-100);
    glVertex3i(100,100,100);
    glVertex3i(-100,100,100);

    glColor3f(1,1,0);

    glVertex3i(-100,-100,-100);
    glVertex3i(100,-100,-100);
    glVertex3i(100,-100,100);
    glVertex3i(-100,-100,100);

    glColor3f(0,0,1);

    glVertex3i(-100,100,-100);
    glVertex3i(100,100,-100);
    glVertex3i(100,-100,-100);
    glVertex3i(-100,-100,-100);

    glEnd();
    glutSwapBuffers();
    glDisable(GL_DEPTH_TEST);
}

int main(int argc , char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
