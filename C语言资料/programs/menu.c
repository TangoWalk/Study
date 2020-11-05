#include <stdio.h>

int main()
{
    char choice;
    void First();void Second();void Third();void Statics();
    int i=0,times=1;
    printf("enter the times you are to run:");
    scanf("%d",&times);


    while(i<=times)
    {
        getchar();
        printf("input 'A' to check the year;\ninput 'B' to translate the letter;\ninput 'C' to compute the average score;\ninput 'D' to compute the average score of each student;\ninput 'E' to end the program.\n\n");
        scanf("%c",&choice);
        switch(choice)
        { case 'A':First();break;

          case 'B':Second();break;

          case 'C':Third();break;

          case 'D':Statics();break;

          case 'E':printf("program has ended.");return 0;

          default: printf("enter data error!\n\n");
        }
        i++;
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
   int num,count,score,scores_array[num][3],subject;
   float average;
   getchar();
   printf("input the amount of students:");
   scanf("%d",&num);
   average = 0;
   for (count=0;count<num;count++)
   {
          for (subject=0;subject<3;subject++)
          {
              printf("input the score of Student %d:",count+1);
              scanf("%d",&score);
              scores_array[count][subject]=score;
              average += score;
          }
          printf("%d %d %d\n",scores_array[count][0],scores_array[count][1],scores_array[count][2]);
    }
   average /= num;
   printf("The average score is %4.2f.",average);
   return 0;
 }

void average()
{
    int cn,mt,eg,i=1;
    float result=0;
    getchar();
    printf("input the scores of students:");
    scanf("%d,%d,%d",&cn,&mt,&eg);
    /*
    printf("%d,%d,%d",cn,mt,eg);
    */
    result=0;
    result=cn+mt+eg;
    result/=3;
    printf("The average score of this student is %4.2f\n\n",result);
}

void Statics()
{
    void average();
    int count,i=1;
    getchar();
    printf("input the amount of students:");
    scanf("%d",&count);

    do
    {
        average();
        i++;
    }
    while(i<=count);
    return 0;
}

