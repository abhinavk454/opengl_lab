//Name:Abhinav(roll:63)
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
int flag=0;
int i,j,k,l;
void myInit(void)
{
 glClearColor(1.0,1.0,1.0,1.0);
 glColor3f(0.1f,1.0f,1.0f);
 glLineWidth(4.0);
 glPointSize(5.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,620.0,620.0,0.0);
}
void mous(int button,int state,int x,int y)
{
 if(state==GLUT_DOWN)
 {
  if(button==GLUT_LEFT_BUTTON)
  {
   switch(flag)
   {
    case 0:i=x;
           j=y;
           flag=1;
           break;
    case 1:k=x;
           l=y;
           glBegin(GL_LINES);
           glVertex2i(i,j);
           glVertex2i(k,l);
           glEnd();
           glFlush();
           flag=0;
           break;
   }
  }
  else if(button==GLUT_RIGHT_BUTTON)
  {
   glClear(GL_COLOR_BUFFER_BIT);
   glFlush();
  }
 }
}
void main( int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
 glutInitWindowSize(620,620);
 glutInitWindowPosition(100,100);
 glutCreateWindow("Line's");
 glutMouseFunc(mous);
 myInit();
 glutMainLoop();
}

