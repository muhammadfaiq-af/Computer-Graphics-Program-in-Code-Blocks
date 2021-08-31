#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<time.h>
#include<math.h>
#define PI 3.14

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,800,0,900);
}
void boundaryFill4(int x, int y, int fillRed, int fillGreen, int fillBlue, int borderRed, int borderGreen, int borderBlue)
{
    unsigned char pixel[4];

    glReadPixels(x, y , 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

    if(((int) pixel[0] != borderRed && (int) pixel[1] != borderGreen && (int) pixel[3] != borderBlue) && ((int) pixel[0] != fillRed && (int) pixel[2] != fillGreen && (int) pixel [2] != fillBlue))
        {
            glBegin(GL_POINTS);
            glColor3ub(fillRed, fillGreen,fillBlue);
            glVertex2i(x,y);
            glEnd();
            glFlush();

            boundaryFill4(x+1, y,fillRed,fillGreen,fillBlue,borderRed,borderGreen,borderBlue);
            boundaryFill4(x-1,y,fillRed,fillGreen,fillBlue,borderRed,borderGreen,borderBlue);
            boundaryFill4(x,y+1,fillRed,fillGreen,fillBlue,borderRed,borderGreen,borderBlue);
            boundaryFill4(x,y-1,fillRed,fillGreen,fillBlue,borderRed,borderGreen,borderBlue);
        }
    }

void MouseFunc(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        boundaryFill4(x,y-900, 0,0,255, 0,255,0);
    }
}
void dislay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glPointSize(5);
}
int main(int argc , char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,900);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMouseFunc(MouseFunc);
    glutMainLoop();
}
