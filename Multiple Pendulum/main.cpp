#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<time.h>
#define PI 3.14


float BallXR = 400,BallYR = 100;
float BallXL = 240,BallYL = 100;
float speed = 0.000001;
float angleStart = 5.24;
float angle = 5.23;
float angleEnd = 4.2;
float rad = 400 , inc = 1/1500.0;
char msg[] = "Multiple Pendulum";
int msgLength = 16;

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,800,0,600);
}

void drawCircle(float xc, float yc, float radius)
{
    float x, y, angle = 2* PI /32;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.75,0.75,0.75);
    glVertex2i(xc,yc);
    for(angle = 0; angle<=2*PI+ inc; angle+=inc)
    {
        x = xc + radius * cos(angle);
        y = yc + radius * sin(angle);
        glColor3f(0.25,0.25,0);
        glVertex2i(x,y);
    }
    glEnd();
}
void display()
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);

    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2i(200,500);
    glVertex2i(600,500);

    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(560,500);
    glVertex2i(BallXR,BallYR);

    glVertex2i(480,500);
    glVertex2i(480,100);

    glVertex2i(480,500);
    glVertex2i(480,100);

    glVertex2i(400,500);
    glVertex2i(400,100);

    glVertex2i(320,500);
    glVertex2i(320,100);

    glVertex2i(240,500);
    glVertex2i(BallXL,BallYL);

        glEnd();
    drawCircle(BallXR,BallYR,50);
    drawCircle(480,100,50);
    drawCircle(480,100,50);
    drawCircle(320,100,50);
    drawCircle(BallXL,BallYL,50);
    if(angle>4.712)
    {
    BallXR = 560 + rad * cos(angle);
    BallYR = 500 + rad * sin(angle);
    inc+=speed;
    }
    else
    {
        BallXL = 240 + rad * cos(angle);
        BallYL = 500 + rad * sin(angle);
        inc-=speed;
    }
        angle-=inc;
    glColor3f(1,1,1);
    for(i=0; i<msgLength; i++)
    {
        glRasterPos2i(330+i*10,525);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,msg[i]);
    }
    glutSwapBuffers();
}
int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();


}
