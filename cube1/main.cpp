#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,600);
}
void display()
{
    GLint vertices[7][2] = {{100,100}, {100,300}, {400,400}, {400,100}, {200,400},{500,125},{500,125}};
    GLubyte ind[12][3] = {0,1,2,3, 0,4,5,2, 3,2,5,6};
    GLfloat col[7][3] = {{1,0,0}, {0,0,1}, {0,1,0}, {1,1,0}, {1,1.5,0}, {0,0,0.5}, {0.5,1,0}};

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);

    glShadeModel(GL_FLAT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glDrawElements(GL_QUADS, 12, GL_UNSIGNED_BYTE,ind);
    glFlush();
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);


}
int main(int argv,char** argc)
{
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Faiq");
    glutInitWindowSize(500,600);
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
