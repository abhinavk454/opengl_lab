//Name:Abhinav(roll:63)
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
FILE *fp;
int flag=0;
int i,j,k,l;
void myInit(void)
{
 glClearColor(1.0,1.0,1.0,1.0);
 glColor3f(0.1f,1.0f,0.0f);
 glLineWidth(4.0);
 glPointSize(5.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,620.0,620.0,0.0);
}
void mous(int button,int state,int x,int y)
{
 fp=fopen("Poly.txt","a");
 if(state==GLUT_DOWN)
 {
  if(button==GLUT_LEFT_BUTTON)
  {
   switch(flag)
   {
    case 0:i=x;
           j=y;
           fprintf(fp,"%d,%d\n",x,y);
           flag=1;
           break;
    case 1:k=x;
           l=y;
           fprintf(fp,"%d,%d\n",x,y);
           glBegin(GL_LINES);
           glVertex2i(i,j);
           glVertex2i(k,l);
           glEnd();
           glFlush();
           i=x;
           j=y;
           flag=1;
           break;
   }
  }
  if(button==GLUT_MIDDLE_BUTTON)
  {
   glClear(GL_COLOR_BUFFER_BIT);
   glFlush();
  }
  if(button==GLUT_RIGHT_BUTTON)
  {
   switch(flag)
   {
    case 0:i=x;
           j=y;
           fprintf(fp,"%d,%d\n",x,y);
           flag=1;
           break;
    case 1:k=x;
           l=y;
           fprintf(fp,"%d,%d\n",x,y);
           glBegin(GL_LINES);
           glVertex2i(i,j);
           glVertex2i(k,l);
           glEnd();
           glFlush();
           flag=0;
           break;
   }
  }
 }
 fclose(fp);
}
void print(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 fp=fopen("Poly.txt","r");
 glColor3f(1.0f,0.0f,0.0f);
 int count=0,x1,y1,x2,y2;
 rewind(fp);
 while(!feof(fp) )
 {
	count++;
	if(count>2)
	{
		x1=x2;
		y1=y2;
		count=2;
	}
	if(count==1)
	{
		fscanf(fp, "%d,%d",&x1,&y1);
	}
	else
	{
		fscanf(fp, "%d,%d",&x2,&y2);
		glBegin(GL_LINES);
		glVertex2i( x1,y1);
		glVertex2i( x2,y2);
		glEnd();
		glFlush();
	}
 }		
fclose(fp);
}
void main( int argc,char **argv)
{
 int choice;
 printf("Enter options :\n1.To draw the figure by mouse.\n2.To draw figure by points stored in file.\n3.Exit.\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
   fp=fopen("Poly.txt","w");
   fclose(fp);
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
   glutInitWindowSize(620,620);
   glutInitWindowPosition(100,100);
   glutCreateWindow("Line's");
   glutMouseFunc(mous);
   myInit();
   glutMainLoop();
   break;
  case 2:
   fp=fopen("Poly.txt","r");
   fclose(fp);
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
   glutInitWindowSize(620,620);
   glutInitWindowPosition(100,100);
   glutCreateWindow("Line's");
   glutDisplayFunc(print);
   myInit();
   glutMainLoop();
   print();
   break;
  case 3:exit(1);
 }
}
