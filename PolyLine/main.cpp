#include<GL/freeglut.h>
#include<GL/gl.h>
#include<Gl/glu.h>

GLint dataValue[12]  = {420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438};
void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,800,0,600);
}

void lineGraph()
{

    GLint month, k;
    GLint x = 30;

    glBegin (GL_LINE_STRIP);
    // Plot data as a polyline.
    for (k = 0; k < 12; k++)
    {
        glVertex2i (x + k*50, dataValue [k]);
        glEnd();
        glFlush();
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 1.0);
    lineGraph();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
