#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<windows.h>
#include<math.h>
#include<time.h>
#define PI 3.14

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,800,0,600);
    glPointSize(5);
}
void display()
{
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1,0,0);


}
GLint dataValue [12] = {420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438};
void barChart (void)
{
    GLint month, k;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    for (k = 0; k < 12; k++)
        glRecti (20 + k*50, 0, 40 + k*50, dataValue [k]);
        glFlush ();
    }

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Welcome to OpenGL");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
