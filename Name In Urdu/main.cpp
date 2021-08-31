#include <gl/gl.h>
#include <gl/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sleep2(int duration)
{
    int end=clock()+duration;
    while(clock()<=end);
}

void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,800,0,700);
}
void DDALine(GLint x0,GLint y0, GLint xEnd, GLint yEnd)
{
    GLint k;
    GLint dx=xEnd -x0;
    GLint dy=yEnd-y0;
    GLfloat xinc,yinc,x=x0,y=y0,steps;

    if (fabs (dx) > fabs (dy))
        steps = fabs (dx);
    else
        steps = fabs (dy);

    xinc = dx/steps;
    yinc = dy/steps;

    //glPointSize(4);


    glColor3f(1,0,0);
    //glVertex2i(round (x), round (y));

    for (k = 0; k < steps; k++) {
        x += xinc;
        y += yinc;

        glBegin(GL_POINTS);
            glVertex2i (round (x), round (y));
        glEnd();


    glFlush();
    //sleep2(5);

    }

glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(10);
    // Muhammad
    DDALine(500,450,550,450);
    DDALine(550,450,600,400);
    DDALine(600,400,500,400);
    DDALine(500,400,550,350);
    DDALine(550,350,500,400);
    DDALine(500,400,450,350);
    DDALine(450,350,500,350);
    DDALine(500,350,450,300);
    DDALine(450,300,500,300);
    DDALine(500,300,450,250);
    DDALine(450,250,500,250);
    DDALine(500,250,500,300);
    DDALine(450,250,400,200);
    DDALine(400,200,350,200);
    DDALine(400,200,400,250);

    //Dots

    DDALine(350,400,350,350);
    DDALine(350,350,300,350);
    DDALine(300,350,350,400);

    DDALine(150,400,150,450);
    DDALine(150,450,70,450);
    DDALine(70,450,70,400);
    DDALine(70,400,150,400);

    DDALine(70,400,70,450);
    DDALine(70,450,100,450);
    DDALine(100,450,100,400);
    DDALine(100,400,70,400);


    //Faiq
    DDALine(350,300,350,250);
    DDALine(350,250,300,250);
    DDALine(300,250,300,300);
    DDALine(300,300,350,300);
    DDALine(300,250,250,250);
    DDALine(250,250,250,400);
    DDALine(200,400,200,350);
    DDALine(200,350,150,350);
    DDALine(150,350,70,350);
    DDALine(70,350,70,200);
    DDALine(70,200,150,200);
    DDALine(150,350,150,300);
    DDALine(150,300,100,300);
    DDALine(100,300,100,350);
    DDALine(250,500,200,500);
    DDALine(200,500,200,450);
    DDALine(200,450,250,450);
    DDALine(250,450,200,400);


}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,600);
    glutCreateWindow("DDA Line Demo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}
