#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<windows.h>
#include<math.h>
#define PI 3.14

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,600,0,800);
}
void display()
{
    int i;
    char name[] = "MUHAMMAD FAIQ";
    GLubyte bitShape [20] = {0xf3,0x02, 0xf3, 0x00,0xf3,
                             0xf3,0x02, 0xf3, 0x00,0xf3,
                             0xf3,0x02, 0xf3, 0x00,0xf3,
                             0xf3,0x02, 0xf3, 0x00,0xf3 };

    GLubyte FA [9] = {0x3c, 0x20, 0xa0, 0x30, 0xf0, 0x22, 0x08, 0x20, 0x20};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glRasterPos2i(400,400);

    glBitmap(20,20,0,0,0,8,FA);
    glRasterPos2i(300,400);
    for(i=0; i<strlen(name); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name[i]);
    glFlush();
    }
}
int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}

