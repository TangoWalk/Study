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

char value[50];//�����ַ�����������֮��.

struct data_form *init_head(struct data_form *head){//������ͷ
    head=(struct data_form *)malloc(sizeof(struct data_form));//��Ԫ���
    head->prior=NULL;//��Ԫǰ���ͺ�̾�Ϊ��
    head->next=NULL;

    return head;}

struct data_form *add_nude(struct data_form *head,int stus_count,int insert_loca,int insert_num){//�˺����ɳ�ʼ������Ҳ�����ӽ�㡣
    //stus_countΪѧ������������֮ǰ����ı䣻insert_locaָ�������λ�ã���ʼ��ʱΪ0��insert_numָ������ı�������
    struct data_form *last = head;
    struct data_form *temper;

    char temp[50];

    for (int stu_count=1;stu_count<insert_loca;stu_count++){
            last = last->next;
            temper = last->next;//ָ�����λ�õ���һ����
    }

    for (int stu_count=1;stu_count<=stus_count-insert_num;++stu_count){
        struct data_form *nude=(struct data_form*)malloc(sizeof(struct data_form));//�����½��
        nude->prior=NULL;//ѭ����ʼʱ��ʼ��nude
        nude->next=NULL;


        printf("\n������ѧ��ѧ�ţ�");//ÿ����¼���������
        scanf("%s",&temp);
        strcpy(nude->stu_num,temp);
        //printf("%s",nude->stu_num);

        last->next=nude;//last�ĺ��ָ��nude
        nude->prior=last;//nude��ǰ��ָ��last
        //ǰ����������Ĵ������

        last=last->next;//last�ĺ��ָ�����һ����nude

    }

    if(insert_loca>=1){last->next=temper;}
    else{last->next=head;head->prior=last;}//��ͷ��ǰ��ָ���β...
    //��ͷҲ�ڼ�����Χ�ڣ�Ϊ��0����

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



