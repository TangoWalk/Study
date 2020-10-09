#include <stdio.h>

int main()
{
    char choice;
 void First();void Second();void Third();
    printf("input 'A' to check the year;\ninput 'B' to translate the letter;\ninput 'C' to compute the average score.\n");
    scanf("%c",&choice);

   switch(choice)
  { case 'A':First();break;
      
     case 'B':Second();break;

     case 'C':Third();break;
     default:  printf("enter data error!\n");
   }
   return 0;
 }
       

void First()
{
 int year;
 getchar();
    printf("input the year:");
    scanf("%d",&year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("%d is a leap year.\n ",year);
    else printf("%d is not a leap year.\n ",year);
 return 0;
}

void Second()
{
 char letter;
    getchar();
    printf("input the letter:");
    scanf("%c",&letter);
    if (letter <=64)
        printf("enter letter error!\n");
    else if (letter <= 89)
            {
              letter += 32;
              printf("It is %c.",letter);
             }
    else if (letter <= 122)
             {
              letter -= 32;
              printf("It is %c",letter);
             }
    else
              printf("enter letter error!\n");
 return 0;
}

void Third()
 {
   int num,count,score;
   float average;
   getchar();
   printf("input the amount of students:");
   scanf("%d",&num);
   average = 0;
   for (count=0;count<num;count++)
   {
          printf("input the score of Student %d:",count+1);
          scanf("%d",&score);
          average += score;
    }
   average /= num;
   printf("The average score is %4.2f.",average);
          return 0;
 }
      

​
