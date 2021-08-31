#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

void setup()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,1300,0,600);
}


void display()
{
    GLint vertices [12] = {420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438};
    GLint k;
    GLint x = 100;
    GLint y2 = 50;


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(6);


    glBegin(GL_QUADS);
    for(int i=0;i<12;i++)
    {
        glVertex2i(x,vertices[i]);
        glVertex2i(x,y2);
        glVertex2i(x+50,y2);
        glVertex2i(x+50,vertices[i]);
        x = x+100;
    }


    glEnd();
  glFlush();


}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
