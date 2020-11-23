#include <stdio.h>
/*
int main()
{
 int i,n;
 printf("nt=?");
 scanf("%d",&n);
 for (i=2;i<=n-1;i++)
  if(n%i==0)continue;
 if(i<n)printf("%d is",n);
 else printf("%d is not",n);
 return 0;
}
{
 char c;
 while((c=getchar())!='\n')
 {
  if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
  {
   c+=4;
   if(c>='Z'&&c<='Z'+4||c>'z')
    c-=26;
  }
   printf("%c",c);
 }
}
*/
void print_star();
void print_message();
int main()
{
 print_star();
 print_message();
 print_star();
 return 0;
}
void print_star()
{
 printf("*********************\n");
