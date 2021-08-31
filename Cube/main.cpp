#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
void setup ()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,600,0,700);
}
void display()
{
    int i;
    int vertices [7][2] = {{200,100},{200,400},{450,400},{450,100},{260,600},{540,600},{540,200}};
    GLubyte ind[12][3] = {0,1,2,3, 1,4,5,2, 3,2,5,6};
    GLfloat col[7][3] = {{1,0,0},{1,1,0},{1,0,1},{1,0.5,0},{0.5,1,0},{1,0,0.5},{0,0,1}};
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);

    glShadeModel(GL_BLEND);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2,GL_INT,0,vertices);
    glColorPointer(3,GL_FLOAT,0,col);

    glDrawElements(GL_QUADS,12,GL_UNSIGNED_BYTE,ind);
    glFlush();
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

}
int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,600);
    glutCreateWindow("Faiq");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
