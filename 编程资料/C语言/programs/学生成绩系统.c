#include <stdio.h>

int cn[100][100],mt[100][100],eg[100][100],stu[100],class_amount;


int main()
{
    char choice;
    int scores_enter();int ave_each_sub();int sub_order_search();int score_search();int max_return();
    int i,times,sub_order[10000];

    scores_enter();

    printf("\n��������Ҫ���еĴ���:");
    scanf("%d",&times);

    while(i<=times-1)
    {
        getchar();
        printf("\n���� 'A' ����ÿ����ĵ���ƽ���ɼ�;\n���� 'B'���ص��ư༶��ߺ���ͳɼ�;\n���� 'C'����ĳͬѧ�����Ƴɼ�;\n���� 'D'����ĳ��Ŀ�ĳɼ�����;\n���� 'E' �˳�����\n\n");
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
   return 0;
 }


 int scores_enter()
 {
     int amount_student,class_each,total_stus=0,student_each;

     printf("������༶����:");
     scanf("%d",&class_amount);

     for (class_each=0;class_each<class_amount;class_each++)
     {
         printf("�������%d��ѧ������:",class_each+1);
         scanf("%d",&stu[class_each]);

     }

     for (class_each=0;class_each<class_amount;class_each++)
     {
         for (student_each=0;student_each<stu[class_each];student_each++)
         {
            printf("\n������༶%d��ѧ��%d�����Ƴɼ�����ʽΪa b c����",class_each+1,student_each+1);
            scanf("%d %d %d",&cn[class_each][student_each],&mt[class_each][student_each],&eg[class_each][student_each]);
            /*printf("%d %d %d\n\n",cn[class_each][student_each],mt[class_each][student_each],eg[class_each][student_each]);*/
         }
     }
     printf("\nѧ���ɼ�¼�����\n\n");
     return 0;

 }

 int ave_each_sub()
 {
     int class_each,student_each;
     float scores_ave_cn=0,scores_ave_mt=0,scores_ave_eg=0;

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

         printf("\n�༶%d������ƽ���ɼ�Ϊ%.2f",class_each+1,scores_ave_cn);
         printf("\n�༶%d����ѧƽ���ɼ�Ϊ%.2f",class_each+1,scores_ave_mt);
         printf("\n�༶%d��Ӣ��ƽ���ɼ�Ϊ%.2f\n",class_each+1,scores_ave_eg);

     }

 }


 int sub_order_search()
 {
     char sub;
     int student_total=0,sub_order[10000],class_each,student_each,box,i,j;

     printf("\n��������Ҫ��ѯ�Ŀ�Ŀ�����ģ�c����ѧ��m��Ӣ�e����");
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

             printf("\n���������ÿƳɼ������ǣ�");

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

             printf("\n���������ÿƳɼ������ǣ�");

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

             printf("\n���������ÿƳɼ������ǣ�");

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
     printf("������ѧ���༶��ѧ����ţ���ʽ��a b����");
     scanf("%d %d",&cl,&num);
     printf("��ѧ�������Ƴɼ��ֱ�Ϊ��%d %d %d\n\n",cn[cl-1][num-1],mt[cl-1][num-1],eg[cl-1][num-1]);
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

       printf("�༶%d�����ĳɼ������ֵ�ǣ�%d\n",class_each+1,score_max_cn);
       printf("�༶%d�����ĳɼ�����Сֵ�ǣ�%d\n",class_each+1,score_min_cn);
       printf("�༶%d����ѧ�ɼ������ֵ�ǣ�%d\n",class_each+1,score_max_mt);
       printf("�༶%d����ѧ�ɼ�����Сֵ�ǣ�%d\n",class_each+1,score_min_mt);
       printf("�༶%d��Ӣ��ɼ������ֵ�ǣ�%d\n",class_each+1,score_max_eg);
       printf("�༶%d��Ӣ��ɼ�����Сֵ�ǣ�%d\n\n",class_each+1,score_min_eg);

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
