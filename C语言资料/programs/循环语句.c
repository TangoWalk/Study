#include <stdio.h>
#define SUM 100000
/* SUM代表100000这个数字*/
int main()
/*
{
 int i,count,score,result;
 result = 0;
 i = 1;
 scanf("%d",&count);
 while(i<= count)
 {
  scanf("%d",&score);
  result += score;
  i++;
 }
 result /= count;
 printf("%d",result);
 return 0;

}
*/
/*
{
 int i=1,count,score,result=0;
 scanf("%d",&count);
 while(i<= count)
 {
  result += i;
  i++;
 }
 printf("%d",result);
 return 0;

}
*/
/*
{
 int i=1,count,result=0;
 scanf("%d",&count);
 do
 {
  result += i;
  i++;
 }while(i <= count);
 printf("%d",result);
 return 0;
}
第一次条件为真，二者一样；第一次条件为假，后者会做一遍。
*/
/*
{
 int i = 0;
 char c;
 for (i=0;(c=getchar())!='\n';i+=c)
  printf(" %c",c);
 return 0;
}
*/
/*
{
 float amount,aver,total; int i;
 for(i=1,total=0;i<=1000;i++)
 {
  printf("please enter amount:");
  scanf("%f",&amount);
  total += amount;
  if(total>=SUM)break;
  /*break终止整个循环过程，不再判断执行循环条件是否成立
 }
 
 aver = total / i;
 printf("num=%d\naver=%10.2f\n",i,aver);
 return 0;
}
*/
/*
{
 int i;
 for(i=100;i<=200;i++)
 {
  if(i % 3 == 0)
   continue;
  /*continue是跳过下面的语句，终止单次循环，继续执行循环的意思。
  printf("%d\n",i);
 }
 return 0;
}
*/
{
 int i,j,n=0;
 for(i=1;i<=4;i++)
 {
  for(j=1;j<=5;j++,n++)
  {
   if(n%5 == 0)printf("\n");
   if(i==3 && j==1)break;
   printf("%d\t",i*j);
  }
 }
 
 printf("\n");
 return 0;
}
