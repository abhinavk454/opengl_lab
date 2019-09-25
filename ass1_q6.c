#include<stdio.h>
void main()
{
 int size;
 printf("Enter the size of array.\n");
 scanf("%d",&size);
 float arr[size];
 int i;
 for(i=0;i<size;i++)
 {
  scanf("%f",&arr[i]);
 }
 int j;
 for(i=0;i<size;i++)
 {
  for(j=i+1;j<size;j++)
  {
   if(arr[i]>arr[j])
   {
    float temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
   }
  }
 }
 for(i=0;i<size;i++)
 {
  printf("%f",arr[i]);
 }
}
