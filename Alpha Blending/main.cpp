#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<time.h>
#define PI * 3.14

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-400,400,-300,300,-500,500);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    glMatrixMode(GL_MODELVIEW);
    glColor4f(1,0,0,1);
    glTranslatef(0,0,300);
    glutSolidSphere(60,32,32);

    glColor4f(1,0.5,0,15);
    glLoadIdentity();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutSolidSphere(150,32,32);



    glutSwapBuffers();
    glDisable(GL_BLEND);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
