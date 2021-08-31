#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<time.h>
#define PI * 3.14

void setup()
{
    GLfloat whiteLight[] = {1,1,1,1};
    GLfloat pos[] = {100,200,100};


    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-400,400,-300,300,-500,500);
    gluLookAt(0,0,100,  0,0,0,  0,1,0);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,whiteLight);
    glLightfv(GL_LIGHT0,GL_POSITION,pos);

    glLightModelfv(GL_AMBIENT,whiteLight);
}
void display()
{
    GLfloat col1[] = {1,0,0};
    GLfloat col2[] = {1,0,1};
    GLfloat col3[] = {0,1,0};


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(-100,0,250);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,col2);
    glutSolidSphere(150,32,32);

    glLoadIdentity();
    glTranslatef(100,0,250);
    glRotatef(-90,1,0,0);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,col3);
    glutSolidCone(50,100,32,32);

    glLoadIdentity();
    glTranslatef(100,-200,250);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,col1);
    glutSolidTeapot(120);

    glutSwapBuffers();
    glDisable(GL_DEPTH_TEST);

}
void kb(unsigned char key, int x,int y)
{
    switch(key)
    {
        case 'o':
            glEnable(GL_LIGHT0);
            break;
        case 'f':
            glDisable(GL_LIGHT0);
    }
}
int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    setup();
    glutKeyboardFunc(kb);
    glutIdleFunc(display);
    glutMainLoop();
}
