#include<stdio.h>
#include<stdlib.h>

typedef struct data_form{
    char stu_num[50];
    char stu_name[50];
    char stu_dpm[50];
    char stu_pfss[50];
    char stu_unit[50];
    char stu_work[50];

    struct data_form *prior;
    struct data_form *next;
}form_head,stu_one,stu_two,stu_three;

char value[50];//返回字符串出错，无奈之举.

struct data_form *init_head(struct data_form *head){//创建表头
    head=(struct data_form *)malloc(sizeof(struct data_form));//首元结点
    head->prior=NULL;//首元前驱和后继均为空
    head->next=NULL;

    return head;}

struct data_form *add_nude(struct data_form *head,int stus_count,int insert_loca,int insert_num){//此函数可初始化链表，也可增加结点。
    //stus_count为学生总数，插入之前不需改变；insert_loca指明插入的位置，初始化时为0；insert_num指明插入的表数量。
    struct data_form *last = head;
    struct data_form *temper;

    char temp[50];

    for (int stu_count=1;stu_count<insert_loca;stu_count++){
            last = last->next;
            temper = last->next;//指向插入位置的下一个表
    }

    for (int stu_count=1;stu_count<=stus_count-insert_num;++stu_count){
        struct data_form *nude=(struct data_form*)malloc(sizeof(struct data_form));//创建新结点
        nude->prior=NULL;//循环开始时初始化nude
        nude->next=NULL;


        printf("\n请输入学生学号：");//每个表录入具体数据
        scanf("%s",&temp);
        strcpy(nude->stu_num,temp);
        //printf("%s",nude->stu_num);

        last->next=nude;//last的后继指向nude
        nude->prior=last;//nude的前驱指向last
        //前面两个步骤的次序可逆

        last=last->next;//last的后继指回最后一个表nude

    }

    if(insert_loca>=1){last->next=temper;}
    else{last->next=head;head->prior=last;}//表头的前驱指向表尾...
    //表头也在计数范围内，为第0个表

    return head;}

char get_elem(struct data_form *head,int stu_count){
    printf("\n%s",head->prior->stu_num);
    for(int each_stu=1;each_stu<=stu_count;each_stu++){
        head=head->next;
        printf("\n%s",head->stu_num);
    }
    strcpy(value,head->stu_num);
    printf("\n%s",value);
}


void main()
{
    struct data_form *head = NULL;
    head = init_head(head);
    head = add_nude(head,6,0,0);
    get_elem(head,0);

    head = add_nude(head,6,2,3);
    get_elem(head,9);

    printf("\n%s",value);


	printf("OK");
}



