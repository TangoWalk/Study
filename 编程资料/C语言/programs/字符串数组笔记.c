#include <stdio.h>
int main()

{
 int i,result;
 char c[]={'I',' ','A','M',' ','H','A','P','P','Y'};
 char d[]="CHINA";
 char e[20];
 char f[]="computer",f_[]="compare";
 
 for(i=0;i<10;i++)
  printf("%c",c[i]);

 printf("\n\n");

 printf("%s\n\n",d);

 puts(d);
 printf("\n");
 
 gets(e);
 strcat(e,d);

 puts(e);
 strncat(e,d,3);

 puts(e);

 result = strcmp(f,f_);

 printf("%d\n\n",result);

 strlen

 return 0;
}



 