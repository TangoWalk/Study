#include <stdio.h>


int cn[100][100],mt[100][100],eg[100][100],stu[100],class_amount;


int main()
{
    char choice;
    int scores_enter();int ave_each_sub();int sub_order_search();int score_search();int max_return();
    int i,times,sub_order[10000];
    void create();

    scores_enter();

    printf("\n请输入需要运行的次数:");
    scanf("%d",&times);

    while(i<=times-1)
    {
        getchar();
        printf("\n输入 'A' 计算每个班的单科平均成绩;\n输入 'B'返回单科班级最高和最低成绩;\n输入 'C'返回某同学的三科成绩;\n输入 'D'返回某科目的成绩排序;\n输入 'E' 退出程序。\n\n");
        scanf("%c",&choice);
        switch(choice)
        {

          case 'A':ave_each_sub();break;
          case 'B':max_return();break;
          case 'C':score_search();break;
          case 'D':sub_order_search();break;

          /*case 'D':Statics();break;*/

          case 'E':printf("program has ended.");return 0;

          default: printf("enter data error!\n\n");
        }
        i++;
    }
    create();
   return 0;
 }


 int scores_enter()
 {
     int amount_student,class_each,total_stus=0,student_each;

     printf("请输入班级总数:");
     scanf("%d",&class_amount);

     for (class_each=0;class_each<class_amount;class_each++)
     {
         printf("请输入班%d的学生人数:",class_each+1);
         scanf("%d",&stu[class_each]);

     }

     for (class_each=0;class_each<class_amount;class_each++)
     {
         for (student_each=0;student_each<stu[class_each];student_each++)
         {
            printf("\n请输入班级%d中学生%d的三科成绩（格式为a b c）：",class_each+1,student_each+1);
            scanf("%d %d %d",&cn[class_each][student_each],&mt[class_each][student_each],&eg[class_each][student_each]);
            /*printf("%d %d %d\n\n",cn[class_each][student_each],mt[class_each][student_each],eg[class_each][student_each]);*/
         }
     }
     printf("\n学生成绩录入完毕\n\n");
     return 0;

 }

 int ave_each_sub()
 {
     int class_each,student_each;
     float scores_ave_cn=0,scores_ave_mt=0,scores_ave_eg=0;
     FILE fp;

     for (class_each=0;class_each<class_amount;class_each++)
     {
         scores_ave_cn = 0;
         scores_ave_mt = 0;
         scores_ave_eg = 0;

         for (student_each=0;student_each<stu[class_each];student_each++)
         {
             scores_ave_cn += cn[class_each][student_each];
             scores_ave_mt += mt[class_each][student_each];
             scores_ave_eg += eg[class_each][student_each];
         }

         scores_ave_cn /= stu[class_each];
         scores_ave_mt /= stu[class_each];
         scores_ave_eg /= stu[class_each];

         printf("\n班级%d的语文平均成绩为%.2f",class_each+1,scores_ave_cn);
         printf("\n班级%d的数学平均成绩为%.2f",class_each+1,scores_ave_mt);
         printf("\n班级%d的英语平均成绩为%.2f\n",class_each+1,scores_ave_eg);

     }

 }


 int sub_order_search()
 {
     char sub;
     int student_total=0,sub_order[10000],class_each,student_each,box,i,j;

     printf("\n请输入想要查询的科目（语文：c，数学：m，英语：e）：");
     getchar();

     scanf("%c",&sub);
     /*printf("%c",sub);*/

     switch(sub)
     {
        case 'c':
        {
             for (class_each=0;class_each<class_amount;class_each++)
             {
                for (student_each=0;student_each<stu[class_each];student_each++)
                {
                    sub_order[student_total]=cn[class_each][student_each];
                    /*printf("%d\n",sub_order[student_total]);*/
                    student_total++;

                }
             }

             for(j=0;j<student_total-1;j++)
             {
                 for(i=0;i<student_total-1-j;i++)
                 if (sub_order[i]<sub_order[i+1]) {box=sub_order[i];sub_order[i]=sub_order[i+1];sub_order[i+1]=box;}
             }

             printf("\n经调整，该科成绩降序是：");

             for(i=0;i<student_total;i++)
                printf("%d ",sub_order[i]);

             break;

        }

        case 'm':
        {
             for (class_each=0;class_each<class_amount;class_each++)
             {
                for (student_each=0;student_each<stu[class_each];student_each++)
                {
                    sub_order[student_total]=mt[class_each][student_each];
                    /*printf("%d\n",sub_order[student_total]);*/
                    student_total++;

                }
             }

             for(j=0;j<student_total-1;j++)
             {
                 for(i=0;i<student_total-1-j;i++)
                 if (sub_order[i]<sub_order[i+1]) {box=sub_order[i];sub_order[i]=sub_order[i+1];sub_order[i+1]=box;}
             }

             printf("\n经调整，该科成绩降序是：");

             for(i=0;i<student_total;i++)
                printf("%d ",sub_order[i]);

             break;

        }

        case 'e':
        {
             for (class_each=0;class_each<class_amount;class_each++)
             {
                for (student_each=0;student_each<stu[class_each];student_each++)
                {
                    sub_order[student_total]=eg[class_each][student_each];
                    /*printf("%d\n",sub_order[student_total]);*/
                    student_total++;

                }
             }

             for(j=0;j<student_total-1;j++)
             {
                 for(i=0;i<student_total-1-j;i++)
                 if (sub_order[i]<sub_order[i+1]) {box=sub_order[i];sub_order[i]=sub_order[i+1];sub_order[i+1]=box;}
             }

             printf("\n经调整，该科成绩降序是：");

             for(i=0;i<student_total;i++)
                printf("%d ",sub_order[i]);

             break;

        }


        default: printf("enter data error!\n\n");
    }

    return 0;
 }

 int score_search()
 {
     int cl,num;
     printf("请输入学生班级和学生编号（格式：a b）：");
     scanf("%d %d",&cl,&num);
     printf("该学生的三科成绩分别为：%d %d %d\n\n",cn[cl-1][num-1],mt[cl-1][num-1],eg[cl-1][num-1]);
 }


int max_return()
{
    int max(one,thoth);
    int class_each,student_each,score_max_cn,score_max_mt,score_max_eg,score_min_cn,score_min_mt,score_min_eg;

    for (class_each=0;class_each<class_amount;class_each++)
    {
        for (student_each=0;student_each<stu[class_each];student_each++)
        {
            score_max_cn=max(cn[class_each][student_each],cn[class_each][student_each+1]);
            score_max_mt=max(mt[class_each][student_each],mt[class_each][student_each+1]);
            score_max_eg=max(eg[class_each][student_each],eg[class_each][student_each+1]);
            score_min_cn=min(cn[class_each][student_each-1],cn[class_each][student_each]);
            score_min_mt=min(mt[class_each][student_each-1],mt[class_each][student_each]);
            score_min_eg=min(eg[class_each][student_each-1],eg[class_each][student_each]);

        }

       printf("班级%d的语文成绩的最大值是：%d\n",class_each+1,score_max_cn);
       printf("班级%d的语文成绩的最小值是：%d\n",class_each+1,score_min_cn);
       printf("班级%d的数学成绩的最大值是：%d\n",class_each+1,score_max_mt);
       printf("班级%d的数学成绩的最小值是：%d\n",class_each+1,score_min_mt);
       printf("班级%d的英语成绩的最大值是：%d\n",class_each+1,score_max_eg);
       printf("班级%d的英语成绩的最小值是：%d\n\n",class_each+1,score_min_eg);

    }
}

int max(one,thoth)
{
    return (one>thoth?one:thoth);
}

int min(one,thoth)
{
    return (one<thoth?one:thoth);
}

void create()
{
    FILE *fp;
    int i;
   char ch,filename[10];

   for (i=0;i<class_amount;i++)
   {
     printf("请输入第%d个班所用的文件名：",i+1);
     scanf("%s",filename);
     if((fp=fopen(filename,"w+"))==NULL)
	{  printf("无法打开此文件\n");
       exit(0);
    }
   }




}
