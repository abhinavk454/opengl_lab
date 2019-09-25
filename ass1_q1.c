#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
void main()
{
 char st1[50],st2[50];
 printf("Enter the 1st string :\n");
 scanf("%s",st1);
 printf("Enter the 2nd string :\n");
 scanf("%s",st2);
 int v=strcmp(st1,st2);
 if(v==0)
  printf("strings are same.\n");
 else
  printf("string are different.\n");
}

