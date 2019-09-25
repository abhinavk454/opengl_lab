#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdlib.h>
int x1,ya,x2,y2;
void setPixel(int x,int y)
{
 glColor3f(1.0f,0.0f,0.0f);
 glPointSize(40.0);
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
 glFlush();
}
void bres(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 float j;
 for(j=-6.5;j<=6.5;j=j+1.0)
 {
 glBegin(GL_LINES);
  glVertex2f(j,-6.5);
  glVertex2f(j,6.5);
 glEnd();
 glFlush();
 }
 for(j=-6.5;j<=6.5;j=j+1.0)
 {
 glBegin(GL_LINES);
  glVertex2f(-6.5,j);
  glVertex2f(6.5,j);
 glEnd();
 glFlush();
 }
 /*int x,y,dx,dy,xend,p,yend;
 dx=xb-xa;
 dy=yb-ya;
 p=(2*dy)-dx;
 if(xa>xb)
 {
  x=xb;
  y=yb;
  xend=xa;
  yend=ya;
 }
 else
 {
  x=xa;
  y=ya;
  xend=xb;
  yend=yb;
 }
 setPixel(x,y);
 while(x<xend)
 {
  x=x+1;
  if(p<0)
  {
   p=p+(2*dy);
  }
  else
  {
   y=y+1;
   p=p+(2*(dy-dx));
  }
  setPixel(x,y);
 }
 while(y<yend)
 {
  y=x+1;
  if(p<0)
  {
   p=p+(2*dy);
  }
  else
  {
   x=x+1;
   p=p+(2*(dy-dx));
  }
  setPixel(x,y);
 }*/
 int dx, dy, i, pk;
 int incx, incy, inc1, inc2;
 int x,y;
 dx = x2-x1;
 dy = y2-ya;
 if (dx < 0)
  dx = -dx;
 if (dy < 0)
  dy = -dy;
  incx = 1;
 if (x2 < x1)
  incx = -1;
  incy = 1;
 if (y2 < ya)
  incy = -1;
 x = x1;
 y = ya;
 if (dx > dy)
 {
  setPixel(x, y);
  pk = 2 * dy-dx;
  inc1 = 2*(dy-dx);
  inc2 = 2*dy;
  for (i=0; i<dx; i++)
  {
   if (pk >= 0)
   {
	y += incy;
	pk += inc1;
   }
	else
    pk += inc2;
	x += incx;
	setPixel(x, y);
  }
 }
 else
 {
  setPixel(x, y);
  pk = 2*dx-dy;
  inc1 = 2*(dx-dy);
  inc2 = 2*dx;
  for (i=0; i<dy; i++)
  {
   if (pk >= 0)
   {
	x += incx;
	pk += inc1;
   }
   else
	pk += inc2;
   y += incy;
   setPixel(x, y);
  }
 }
}
void myInit(void)
{
 glClearColor(1.0,1.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 gluOrtho2D(-6,6,-6,6);
}
void main(int argc,char **argv)
{
 printf("Enter point1 co-ordinates :\n");
 scanf("%d%d",&x1,&ya);
 printf("Enter point2 co-ordinates :\n");
 scanf("%d%d",&x2,&y2);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(480,480);
 glutInitWindowPosition(100,100);
 glutCreateWindow("bresenhem's");
 glutDisplayFunc(bres);
 myInit();
 glutMainLoop();
}
