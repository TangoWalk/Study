#include <stdio.h>

int cn[100][100],mt[100][100],eg[100][100],stu[100];

int main()
{
    char choice;
    void scores_enter();
    int i=0,times=1;

    scores_enter();
    printf("���������г���Ĵ���:");
    scanf("%d",&times);

    /*
    while(i<=times)
    {
        getchar();
        printf("���� 'A' ����ÿ����ĵ���ƽ���ɼ�;\n���� 'B'���ص��ư༶��߳ɼ�;\n���� 'C' ����ĳͬѧ�����Ƴɼ�;\n���� 'D'����ĳ��Ŀ�ĳɼ�����;\n���� 'E' �˳�����\n\n");
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

     printf("������༶����:");
     scanf("%d",&amount_class);

     for (class_each=0;class_each<amount_class;class_each++)
     {
         printf("�������%d��ѧ������",class_each+1);
         scanf("%d",&stu[class_each]);
         total_stus += stu[class_each];
     }

     for (class_each=0;class_each<amount_class;class_each++)
     {
         for (student_each=0;student_each<stu[class_each];student_each++)
         {
            printf("������༶%d��ѧ��%d�����Ƴɼ�������ʽΪa b c��",class_each+1,student_each+1);
            scanf("%d %d %d",&cn[class_each][student_each],&mt[class_each][student_each],&eg[class_each][student_each]);
            printf("%d %d %d\n\n",cn[class_each][student_each],mt[class_each][student_each],eg[class_each][student_each]);
         }
     }
     printf("ѧ���ɼ�¼�����");
     return 0;

 }
