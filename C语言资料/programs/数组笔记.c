#include <stdio.h>

int main()
/*
{
 int i,a[10];
 for(i=0;i<=9;i++)
  a[i]=i;
 for(i=9;i>=0;i--)
  printf("%d\n",a[i]);
 printf("\n");
 return 0;


{
 int i;int f[20]={1,1};
 for(i=2;i<20;i++)
  f[i]=f[i-2]+f[i-1];
 
 for(i=0;i<20;i++)
 {
  if(i%5==0) printf("\n");
  printf("%12d",f[i]);
 }

}

{
 int a[10];int i,j,t;
 printf("input 10 numbers:");
 for(i=0;i<10;i++) scanf("%d",a[i]);
  printf("\n");
 for(j=0;j<9;j++)
  for(i=0;i<9-j;i++)
   if(a[i]>a[i+1])
   {
    t=a[i];
    a[i]=a[i+1];
    a[i+1]=t;
   }
 printf("the sorted numbers:\n");
 for(i=0;i<10;i++) printf("%d",a[i]);
 printf("\n");
 return 0;
}

*/

{
 int a[2][3]={{1,2,3},{4,5,6}};
 int b[3][2],i,j;
 printf("array a:\n");

 for(i=0;i<=1;i++)
 {
  for(j=0;j<=2;j++)
  {
   printf("%5d",a[i][j]);
   b[j][i]=a[i][j];
  }
  printf("\n");
 }

 printf("array b:\n");

 for(i=0;i<=2;i++)
 {
  for(j=0;j<=1;j++)
   printf("%5d",b[i][j]);
   printf("\n");
 }
 return 0;
}





