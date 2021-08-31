#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define PI 3.1415926

void delay(int duration)
{
    int end=clock()+duration;
    while(clock()<=end);
}
void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}


void drawCircle1(float xc, float yc, float radius)
{
    float x,y,angle;


    for(angle = 0; angle<=2; angle+=1/radius)
    {
        x = xc + radius * cos(angle);
        y = yc + radius * sin(angle);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
         glEnd();
    glFlush();
    delay(2);
    }


}

void drawCircle2(float xc2, float yc2, float radius)
{
    float x2,y2,angle;


    for(angle = 0; angle<=2; angle+=1/radius)
    {
        x2 = xc2 + radius * cos(angle);
        y2 = yc2 + radius * sin(angle);
        glBegin(GL_POINTS);
        glVertex2i(x2,y2);
         glEnd();
    glFlush();
    delay(2);
    }


}
void drawCircle3(float xc3, float yc3, float radius)
{
    float x3,y3,angle;


    for(angle = 0; angle<=2; angle+=1/radius)
    {
        x3 = xc3 + radius * cos(angle);
        y3 = yc3 + radius * sin(angle);
        glBegin(GL_POINTS);
        glVertex2i(x3,y3);
         glEnd();
    glFlush();
    delay(2);
    }


}
   void display()
{


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(2);
    drawCircle1(320,240,100);
    drawCircle2(100,300,100);
    drawCircle3(500,200,100);

}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Circle Drawing 1");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
