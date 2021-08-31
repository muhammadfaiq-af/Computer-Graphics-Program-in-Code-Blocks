#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <windows.h>

float ang = 6;
void setup()
{
    glClearColor(0.4,0.5,0.8,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-400,400,-300,300,-400,400);

}

void createquads(int x ,int y, int z)
{
    glBegin(GL_QUADS);
      glColor3f(1,0,0);

        glVertex3i(-x,y,z);
        glVertex3i(x,y,z);
        glVertex3i(x,-y,z);
        glVertex3i(-x,-y,z);

        //Left Face
        glColor3f(1,0,1);
        glVertex3i(-x,y,-z);
        glVertex3i(-x,-y,-z);
        glVertex3i(-x,-y,z);
        glVertex3i(-x,y,z);

        //Right Face
        glColor3f(0,1,1);
        glVertex3i(x,y,-z);
        glVertex3i(x,-y,-z);
        glVertex3i(x,-y,z);
        glVertex3i(x,y,z);

        //Top Face
        glColor3f(0,0,1);
        glVertex3i(-x,y,-z);
        glVertex3i(x,y,-z);
        glVertex3i(x,y,z);
        glVertex3i(-x,y,z);

        //Bottom Face
        glColor3f(0,1,0);
        glVertex3i(-x,-y,-z);
        glVertex3i(x,-y,-z);
        glVertex3i(x,-y,z);
        glVertex3i(-x,-y,z);

        //Front Face
        glColor3f(1,1,0);
        glVertex3i(-x,y,-z);
        glVertex3i(x,y,-z);
        glVertex3i(x,-y,-z);
        glVertex3i(-x,-y,-z);

    glEnd();

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glRotatef(ang,1,-1,0);
    glTranslatef(-70,-10,70);
    glScalef(1,2,3);
    createquads(50,50,50);
    glLoadIdentity();
    glScalef(1,1,2);
    glRotatef(ang+2,1,-1,0);
    glTranslatef(160,-60,70);
    createquads(50,50,50);
    glLoadIdentity();
    glRotatef(10,1,-1,0);
    glScalef(5,1,7);
    glTranslatef(10,-150,1);
    createquads(50,50,50);
    glutSwapBuffers();
    glDisable(GL_DEPTH_TEST);
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("check");
    setup();
    glutDisplayFunc(display);
   //glutIdleFunc(display);
    glutMainLoop();
}
