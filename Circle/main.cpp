#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<time.h>
#include<math.h>

void delay(int duration)
{
    int end=clock()+duration;
    while(clock()<=end);
}
void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,1200,0,800);
}
void display()
{
    GLfloat xc1,yc1,xc2,yc2,xc3,yc3,xc4,yc4,xc5,yc5,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,r = 100;
    xc1 = 300, yc1 = 600;
    xc2 = 525, yc2 = 600;
    xc3 = 750, yc3 = 600;
    xc4 = 425, yc4 = 500;
    xc5 = 650, yc5 = 500;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(10);

    for(x1 = xc1-r; x1<=xc1+r; x1+=1)
    {
        glColor3f(1,0,0);
        y1=yc1 + sqrt(pow(r,2) - pow(x1-xc1,2));
        glBegin(GL_POINTS);
        glVertex2i(x1,y1);
        glEnd();

        y1 = yc1 - sqrt(pow(r,2) - pow(x1-xc1,2));
        glBegin(GL_POINTS);
        glVertex2i(x1,y1);
        glEnd();
        delay(10);
    }
        for(x2 = xc2-r; x2<= xc2+r; x2 +=1)
        {
            glColor3f(0,1,0);
            y2 = yc2 + sqrt(pow(r,2) - pow(x2-xc2,2));
            glBegin(GL_POINTS);
            glVertex2i(x2,y2);
            glEnd();

            y2 = yc2 - sqrt(pow(r,2) - pow(x2-xc2,2));
            glBegin(GL_POINTS);
            glVertex2i(x2,y2);
            glEnd();
        }

        delay(10);


        for(x3 = xc3-r; x3<= xc3+r; x3+=1)
        {
            glColor3f(0,0,1);
            y3 = yc3 + sqrt(pow(r,2) - pow(x3-xc3,2));
            glBegin(GL_POINTS);
            glVertex2i(x3,y3);
            glEnd();

            y3 = yc3 - sqrt(pow(r,2) - pow(x3-xc3,2));
            glBegin(GL_POINTS);
            glVertex2i(x3,y3);
            glEnd();
        }
        delay(10);

        for(x4 = xc4-r; x4<=xc4+r; x4+=1)
        {
            glColor3f(1,0.5,0);
            y4 = yc4 - sqrt(pow(r,2) - pow(x4-xc4,2));
            glBegin(GL_POINTS);
            glVertex2i(x4,y4);
            glEnd();

            y4 = yc4 + sqrt(pow(r,2) - pow(x4-xc4,2));
            glBegin(GL_POINTS);
            glVertex2i(x4,y4);
            glEnd();
        }
        delay(10);

        for(x5 = xc5-r; x5<=xc5+r; x5+=1)
        {
            glColor3f(1,0,0.5);
            y5 = yc5 - sqrt(pow(r,2) - pow(x5-xc5,2));
            glBegin(GL_POINTS);
            glVertex2i(x5,y5);
            glEnd();

            y5 = yc5 + sqrt(pow(r,2) - pow(x5-xc5,2));
            glBegin(GL_POINTS);
            glVertex2i(x5,y5);
            glEnd();
        }
        delay(10);



        glFlush();

}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(1200,800);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
