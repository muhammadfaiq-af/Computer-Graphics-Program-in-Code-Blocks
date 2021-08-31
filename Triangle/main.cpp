#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<time.h>
#define PI 3.14

void setuo()
{
    glClearColor(0,0,0,0);
    gluOrtho2D(0,800,0,700);
    glMatrixMode(GL_PROJECTION);
}
void display()
{
    struct point{
    GLfloat x,y
    };


    int i,v;
    struct point vertices[] = {{100,100},{100,700},{400,600}};
    struct point p = {170,240};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glPointSize(1);
    for(i=0; i<50000; i++)
    {
        v = rand()%3;

        p.x=(p.x+ vertices[v].x)/2;
        p.y=(p.y+ vertices[v].y)/2;

        glBegin(GL_POINTS);
        glVertex2i(p.x,p.y);
        glEnd();
    }

    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,700);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY_WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();


}
