#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<time.h>
#define PI 3.14

float angle = 0.01 , cubeAngle = 0.01;
void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-5,5);
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glRotatef(angle,1,1,0);
    glutWireOctahedron();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(2.5,0,0);
    glRotatef(cubeAngle,0,1,1);
    glutWireCube(1);

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.5,0,0);
    glRotatef(cubeAngle,1,0,1);
    glutWireOctahedron();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0,2.5,0);
    glRotatef(cubeAngle,0,0.5,1);
    glutWireDodecahedron();


    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    glDisable(GL_DEPTH_TEST);
    cubeAngle += 0.01;
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
