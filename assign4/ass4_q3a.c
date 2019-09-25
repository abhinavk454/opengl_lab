//dda for line drawing
//name:->Abhinav Kumar
//enroll:->510817075(63-hy)
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
float x1,x2,y2;
float y_1;
void dda(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 float i;
 for(i=-6.5;i<=6.5;i=i+1.0)
 {
 glBegin(GL_LINES);
  glVertex2f(i,-6.5);
  glVertex2f(i,6.5);
 glEnd();
 glFlush();
 }
 for(i=-6.5;i<=6.5;i=i+1.0)
 {
 glBegin(GL_LINES);
  glVertex2f(-6.5,i);
  glVertex2f(6.5,i);
 glEnd();
 glFlush();
 }
 float m,x,y,dx,dy,step,x_inc,y_inc,k;
 dy=y2-y_1;
 dx=x2-x1;
 if(abs(dx)>abs(dy))
  step=abs(dx);
 else
  step=abs(dy);
 x_inc=dx/step;
 y_inc=dy/step;
 x=x1;
 y=y_1;
 glPointSize(40.0);
 glBegin(GL_POINTS);
  glVertex2i(x,y);
 glEnd();
 for(k=1;k<=step;k++)
 {
  x+=x_inc;
  y+=y_inc;
  glBegin(GL_POINTS);
   glVertex2i(x,y);
  glEnd();
 }
 glFlush();
}
void myInit(void)
{
 glClearColor(1.0,1.0,1.0,1.0);
 glColor3f(1.0f,0.0f,0.0f);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-6.0,6.0,-6.0,6.0);
}
void main(int argc,char **argv)
{
 printf("Enter the value of x1, y1 :\n");
 scanf("%f%f",&x1,&y_1);
 printf("Enter the value of x2, y2 :\n");
 scanf("%f%f",&x2,&y2);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(480,480);
 glutInitWindowPosition(300,300);
 glutCreateWindow("display");
 glutDisplayFunc(dda);
 myInit();
 glutMainLoop();
}

