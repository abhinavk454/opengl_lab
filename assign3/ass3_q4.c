#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
void mydisp(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.5f,0.1f,0.1f);
glPointSize(10.0);
glBegin(GL_POINTS);
 glVertex2i(0,0);
glEnd();
glFlush();
}
void mymouse(int button,int state,int x,int y)
{
 if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
 {
  int l=x;
  int m=480-y;
  glBegin(GL_POINTS);
   glVertex2i(l,m);
  glEnd();
  glFlush();
 }
}
void myInit(void)
{
 glClearColor(1.0,1.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0,480,0,480);
}
void main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(480,480);
 glutInitWindowPosition(0,0);
 glutCreateWindow("Point");
 glutDisplayFunc(mydisp);
 glutMouseFunc(mymouse);
 myInit();
 glutMainLoop();
}
