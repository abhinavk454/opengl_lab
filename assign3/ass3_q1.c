#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
void mydisp(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.5f,0.1f,0.1f);
glPointSize(5.0);
glBegin(GL_POINTS);
 glVertex2i(100, 50);
 glVertex2i(100, 130);
 glVertex2i(150, 130);
glEnd();
glFlush();
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
 myInit();
 glutMainLoop();
}
