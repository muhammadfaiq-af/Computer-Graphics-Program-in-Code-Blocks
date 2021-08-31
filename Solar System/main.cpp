#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#define PI 3.1415926

float sunX = 500, sunY = 500, MercuryX = 700, MercuryY = 600, VenusX = 600, VenusY = 700, EarthX = 650, EarthY = 500, MoonX = 450, MoonY = 750, MarsX = 450, MarsY = 600, JupiterX = 500, JupiterY = 650 , SataurnX = 500, SataurnY = 400, UranusX = 650, UranusY = 700, NeptuneX = 700, NeptuneY = 500,
      MarMoon1X = 525, MarMoon1Y = 300, MarMoon2X = 450, MarMoon2Y = 500,
      JupMoon1X = 450, JupMoon1Y = 300, JupMoon2X = 475, JupMoon2Y = 350,
      SatMoon1X = 300, SatMoon1Y = 300, SatMoon2X = 400, SatMoon2Y = 275,
      UranMoon1X = 520, UranMoon1Y = 300, UranMoon2X = 550, UranMoon2Y = 320,
      NepMoon1X = 700, NepMoon1Y = 450, NepMoon2X = 750, NepMoon2Y =  400;

float MeSDist=100,MeAngle=0,MeInc=1/700.0;
float VSDist=175,VAngle=0,VInc=1/600.0;

float ESDist=250,EAngle=0,EInc=1/600.0;
float MEDist=50, MAngle=0,MInc=1/300.0;

float MaSDist=325, MaAngle=0, MaInc=1/500.0;
float MarMoon1Dist=50, Ma1Angle=0, Ma1Inc=1/400.0;
float MarMoon2Dist=75, Ma2Angle=0, Ma2Inc=1/400.0;

float JSDist=400,JAngle=0,JInc=1/300.0;
float JupMoon1Dist=50, J1Angle=0, J1Inc=1/200.0;
float JupMoon2Dist=75, J2Angle=0, J2Inc=1/200.0;

float SSDist=475,SAngle=0,SInc=1/400.0;
float SatMoon1Dist=50, S1Angle=0, S1Inc=1/200.0;
float SatMoon2Dist=75, S2Angle=0, S2Inc=1/200.0;

float USDist=550,UAngle=0,UInc=1/500.0;
float UranMoon1Dist=50, U1Angle=0, U1Inc=1/400.0;
float UranMoon2Dist=75, U2Angle=0, U2Inc=1/400.0;

float NSDist=625, NAngle=0,NInc=1/600.0;
float NepMoon1Dist=50, N1Angle=0, N1Inc=1/600.0;
float NepMoon2Dist=75, N2Angle=0, N2Inc=1/600.0;

//FAIQ

char msg[]="Solar Subsystem";
int strSize=15;
float ang=0;
float yv=300;
float cx,cy;

void delay(int duration)
{
    int end=clock()+duration;
    while(clock()<=end);
}
void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,1000,0,1200);

}
void drawCircle(float xc,float yc, float radius)
{
    float x,y,angle,inc=2*PI/16;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc,yc);
    for(angle=0;angle<=2*PI+inc;angle+=inc)
    {

        x=xc+radius*cos(angle);
        y=yc+radius*sin(angle);

        glVertex2f(x,y);
    }
    glEnd();
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255,255,0);
    drawCircle(sunX,sunY,50);

    //Draw Mercury
    glColor3ub(112,128,144);
    drawCircle(MercuryX,MercuryY,30);

    //Draw Venus
    glColor3ub(210,105,30);
    drawCircle(VenusX,VenusY,30);

    //Draw Earth
    glColor3ub(46,139,87);
    drawCircle(EarthX,EarthY,30);

    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(MoonX,MoonY,10);

    //Draw Mars
    glColor3ub(64,224,208);
    drawCircle(MarsX,MarsY,35);
    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(MarMoon1X,MarMoon1Y,10);

    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(MarMoon2X,MarMoon2Y,10);


    //Draw Jupiter
    glColor3ub(165,42,42);
    drawCircle(JupiterX,JupiterY,33);
    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(JupMoon1X,JupMoon1Y,10);

    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(JupMoon2X,JupMoon2Y,10);


    //Draw Saturan
    glColor3ub(255,0,0);
    drawCircle(SataurnX,SataurnY,30);
    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(SatMoon1X,SatMoon1Y,10);

    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(SatMoon2X,SatMoon2Y,10);


    //Draw Uranus
    glColor3ub(0,0,255);
    drawCircle(UranusX,UranusY,30);
    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(UranMoon1X,UranMoon1Y,10);

    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(UranMoon2X,UranMoon2Y,10);


    //Draw Neptune
    glColor3ub(0,103,165);
    drawCircle(NeptuneX,NeptuneY,30);
    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(NepMoon1X,NepMoon1Y,10);

    //Draw Moon
    glColor3ub(192,192,192);
    drawCircle(NepMoon2X,NepMoon2Y,10);





    //Now Animate Mercury
    MercuryX=sunX + MeSDist*cos(MeAngle);
    MercuryY=sunY + MeSDist*sin(MeAngle);

    //Now Animate Venus
    VenusX=sunX + VSDist*cos(VAngle);
    VenusY=sunY + VSDist*sin(VAngle);

    //Now Animate Earth
    EarthX=sunX + ESDist*cos(EAngle);
    EarthY=sunY + ESDist*sin(EAngle);

    //Now Animate Moon
    MoonX=EarthX + MEDist*cos(MAngle);
    MoonY=EarthY + MEDist*sin(MAngle);

    //Now animate Mars
    MarsX=sunX + MaSDist*cos(MaAngle);
    MarsY=sunY + MaSDist*sin(MaAngle);
     //Now Animate Moon
    MarMoon1X=MarsX + MarMoon1Dist*cos(Ma1Angle);
    MarMoon1Y=MarsY + MarMoon1Dist*sin(Ma1Angle);
     //Now Animate Moon
    MarMoon2X=MarsX + MarMoon2Dist*cos(Ma2Angle);
    MarMoon2Y=MarsY + MarMoon2Dist*sin(Ma2Angle);

    //Now animate Jupiter
    JupiterX=sunX + JSDist*cos(JAngle);
    JupiterY=sunY + JSDist*sin(JAngle);
    //now animated Moon
    JupMoon1X=JupiterX + JupMoon1Dist*cos(J1Angle);
    JupMoon1Y=JupiterY + JupMoon1Dist*sin(J1Angle);
    //now animated Moon
    JupMoon2X=JupiterX + JupMoon2Dist*cos(J2Angle);
    JupMoon2Y=JupiterY + JupMoon2Dist*sin(J2Angle);

    //now animate Sataurn
    SataurnX=sunX + SSDist*cos(SAngle);
    SataurnY=sunY + SSDist*sin(SAngle);
    // now Animated Moon
    SatMoon1X=SataurnX + SatMoon1Dist*cos(S1Angle);
    SatMoon1Y=SataurnY + SatMoon1Dist*sin(S1Angle);
    // now Animated Moon
    SatMoon2X=SataurnX + SatMoon2Dist*cos(S2Angle);
    SatMoon2Y=SataurnY + SatMoon2Dist*sin(S2Angle);

    //now Animated Uranus
    UranusX=sunX + USDist*cos(UAngle);
    UranusY=sunY + USDist*sin(UAngle);
    // now animated Moon
    UranMoon1X=UranusX + UranMoon1Dist*cos(U1Angle);
    UranMoon1Y=UranusY + UranMoon1Dist*sin(U1Angle);
    // now animated Moon
    UranMoon2X=UranusX + UranMoon2Dist*cos(U2Angle);
    UranMoon2Y=UranusY + UranMoon2Dist*sin(U2Angle);

    //now Animated Neptune
    NeptuneX=sunX + NSDist*cos(NAngle);
    NeptuneY=sunY + NSDist*sin(NAngle);
    //now animated Moon
    NepMoon1X=NeptuneX + NepMoon1Dist*cos(N1Angle);
    NepMoon1Y=NeptuneY + NepMoon1Dist*sin(N1Angle);
    //now animated Moon
    NepMoon2X=NeptuneX + NepMoon2Dist*cos(N2Angle);
    NepMoon2Y=NeptuneY + NepMoon2Dist*sin(N2Angle);


    EAngle+=EInc;
    MAngle-=MInc;

    MaAngle+=MaInc;
    Ma1Angle-=Ma1Inc;
    Ma2Angle+=Ma2Inc;

    MeAngle+=MeInc;

    VAngle+=VInc;

    JAngle+=JInc;
    J1Angle-=J1Inc;
    J2Angle+=J2Inc;

    SAngle+=SInc;
    S1Angle-=S1Inc;
    S2Angle+=S2Inc;

    UAngle+=UInc;
    U1Angle-=U1Inc;
    U2Angle+=U2Inc;

    NAngle+=NInc;
    N1Angle-=N1Inc;
    N2Angle+=N2Inc;

    glFlush();
    delay(5);





}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1200);
    glutInitWindowPosition(50,50);
    glutCreateWindow(" Faiq's Solar System");
    setup();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();



}
