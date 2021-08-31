
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#define PI 3.1415926

void setup()
{

    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}
void display()
{
    int i;
    char name[] = "Faiq";
    GLubyte bitShape[20] = {0x1c, 0x00, 0x1c, 0x00,
                            0x1c, 0x00, 0x1c, 0x00,
                            0x1c, 0x00,0xff, 0x80,
                            0x7f, 0x00, 0x3e, 0x00,
                            0x1c, 0x00, 0x08, 0x00 };
                            glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
                            glRasterPos2i (30, 40);
                            glBitmap (9, 10, 0.0, 0.0, 20.0, 15.0, bitShape);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glFlush();

}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("OpenGL Bitmap");
    setup();
    glutDisplayFunc(display);

    glutMainLoop();
}

