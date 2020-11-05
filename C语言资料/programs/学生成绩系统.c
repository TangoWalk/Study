#include <stdio.h>

int cn[100][100],mt[100][100],eg[100][100],stu[100];

int main()
{
    char choice;
    void scores_enter();
    int i=0,times=1;

    scores_enter();
    printf("请输入运行程序的次数:");
    scanf("%d",&times);

    /*
    while(i<=times)
    {
        getchar();
        printf("输入 'A' 计算每个班的单科平均成绩;\n输入 'B'返回单科班级最高成绩;\n输入 'C' 返回某同学的三科成绩;\n输入 'D'返回某科目的成绩排序;\n输入 'E' 退出程序。\n\n");
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
    }*/
   return 0;
 }


 void scores_enter()
 {
     int amount_student,amount_class,class_each,total_stus=0,student_each;

     printf("请输入班级总数:");
     scanf("%d",&amount_class);

     for (class_each=0;class_each<amount_class;class_each++)
     {
         printf("请输入班%d的学生人数",class_each+1);
         scanf("%d",&stu[class_each]);
         total_stus += stu[class_each];
     }

     for (class_each=0;class_each<amount_class;class_each++)
     {
         for (student_each=0;student_each<stu[class_each];student_each++)
         {
            printf("请输入班级%d中学生%d的三科成绩：（格式为a b c）",class_each+1,student_each+1);
            scanf("%d %d %d",&cn[class_each][student_each],&mt[class_each][student_each],&eg[class_each][student_each]);
            printf("%d %d %d\n\n",cn[class_each][student_each],mt[class_each][student_each],eg[class_each][student_each]);
         }
     }
     printf("学生成绩录入完毕");
     return 0;

 }
