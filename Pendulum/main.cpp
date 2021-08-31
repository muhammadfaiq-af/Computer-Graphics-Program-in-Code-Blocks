#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<time.h>
#define PI 3.14


float BallX = 400,BallY = 100;
float speed = 0.000001;
float angleStart = 5.24;
float angle = 5.23;
float angleEnd = 4.2;
float rad = 400 , inc = 1/1500.0;
char msg[] = "Simple Pendulum";
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
    glColor3f(0.5,0.5,0);
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

    glBegin(GL_LINES);
    glVertex2i(300,500);
    glVertex2i(500,500);

    glEnd();

    glBegin(GL_LINES);
    glVertex2i(400,500);
    glVertex2i(BallX,BallY);

    glEnd();
    drawCircle(BallX,BallY,50);

    BallX = 400 + rad * cos(angle);
    BallY = 500 + rad * sin(angle);

    if(angle<= angleEnd || angle>=angleStart)
    {
        inc*=-1;
    }
    if(BallX>400)
        inc+=speed;
    else
        inc-=speed;

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
