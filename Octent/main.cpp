#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/gl.h>
#include<time.h>
#include<math.h>
#define PI 3.14

void delay(int duration)
{
    int end = clock() + duration;
    while(clock()<=end);

}
void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,900,0,800);
}
void DrawCircle(float xc, float yc, float radius)
{
    float x,y,p;
    p = 1-radius;

    x = 0;
    y = radius;

    while(x <= y)
    {
    if(p<0)
    {
        x = x+1;
        p = p + (2*x+2) + 1;
    }
    else
    {
        x = x+1;
        y = y-1;
        p = p + (2*x+2) + 1 - (2*y-2);
    }
    glBegin(GL_POINTS);
    glVertex2i(xc+ x,yc + y);
    glEnd();

    glBegin(GL_POINTS);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glEnd();
    glFlush();
    delay(20);
    }

}
void display()
{


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(3);
    DrawCircle(320,240,100);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(900,800);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
