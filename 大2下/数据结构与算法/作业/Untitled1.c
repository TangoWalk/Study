#include<stdio.h>
#include<stdlib.h>
typedef struct data_form{
    int stu_num;
    char stu_name[50];
    char stu_dpm[50];
    char stu_pfss[50];
    char stu_cpn[50];
    char stu_work[50];
    struct data_form *prior;
    struct data_form *next;
};
int stus_count;//ѧ������
struct data_form *return_to_head(struct data_form *head,int stu_count){
 int each_stu;
    for(each_stu=1;each_stu<=stu_count;each_stu++){head=head->prior;}
    return head;}
struct data_form *init_head(struct data_form *head){//������ͷ
    head=(struct data_form *)malloc(sizeof(struct data_form));//��Ԫ���
    head->prior=NULL;//��Ԫǰ���ͺ�̾�Ϊ��
    head->next=NULL;
    return head;}
struct data_form *add_nude(struct data_form *head,int insert_loca,int insert_num,int num_check){//�˺����ɳ�ʼ������Ҳ�����ӽ�㡣
    //stus_countΪѧ������������֮ǰ����ı䣻insert_locaָ�������λ�ã���ʼ��ʱΪ0��insert_numָ������ı�������
    struct data_form *last = head;
    struct data_form *behind,*front;
    int stu_count,stu_num;
    char temp[50];
    if (insert_loca!=stus_count+1&&insert_loca!=1){//����ʱ����
        for (stu_count=1;stu_count<insert_loca;stu_count++){last = last->next;behind = last->next;}//ָ�����λ�õ�ǰ���ͺ��
    }
    else if (insert_loca!=stus_count+1&&insert_loca==1){behind = head->next;}//ָ�����λ�õĺ��

    for (stu_count=1;stu_count<=insert_num;stu_count++){
        struct data_form *nude=(struct data_form*)malloc(sizeof(struct data_form));//�����½��
        nude->prior=NULL;//ѭ����ʼʱ��ʼ��nude
        nude->next=NULL;


        if (num_check==0){printf("\n������ѧ��%d��ѧ�ţ�",stu_count);//ÿ����¼���������
        scanf("%d",&stu_num);
        nude->stu_num=stu_num;}
        else{stu_num=num_check; nude->stu_num=stu_num;}

        //printf("%s",nude->stu_num);

        printf("\n������ѧ��%d��������",stu_count);//ÿ����¼���������
        scanf("%s",&temp);
        strcpy(nude->stu_name,temp);

        printf("\n������ѧ��%d��ϵ��",stu_count);//ÿ����¼���������
        scanf("%s",&temp);
        strcpy(nude->stu_dpm,temp);

        printf("\n������ѧ��%d��רҵ��",stu_count);//ÿ����¼���������
        scanf("%s",&temp);
        strcpy(nude->stu_pfss,temp);

        printf("\n������ѧ��%d�Ĺ�����λ��",stu_count);//ÿ����¼���������
        scanf("%s",&temp);
        strcpy(nude->stu_cpn,temp);

        printf("\n������ѧ��%d��ְ��",stu_count);//ÿ����¼���������
        scanf("%s",&temp);
        strcpy(nude->stu_work,temp);

        if(stu_count==1){front=nude;}

        last->next=nude;//last�ĺ��ָ��nude
        nude->prior=last;//nude��ǰ��ָ��last
        //ǰ����������Ĵ������

        last=last->next;//last�ĺ��ָ�����һ����nude

    }

    if (insert_loca!=stus_count+1&&insert_loca!=1){//����ʱ����
        last->next=behind;behind->prior=last;}//�����ĺ��ָ�����λ�õĺ�һ����
        //for(int each=1;each<=stus_count-insert_loca;each++){behind=behind->next;}head->prior=behind;behind->next=head;}
    else if (insert_loca!=stus_count+1&&insert_loca==1){//����ʱ����
        {head->next=front;front->prior=head;last->next=behind;behind->prior=last;}//ָ�����λ�õ���һ����
    }
    else{last->next=head;head->prior=last;}//��ͷ��ǰ��ָ���β...
    //��ͷҲ�ڼ�����Χ�ڣ�Ϊ��0����

    stus_count+=insert_num;

    return head;}

struct data_form * index_by_label(struct data_form *head,char index_label,int stu_count){
    if(index_label<97||index_label>122){
            printf("\n��������Ҫ���ҵ���Ϣ(ѧ��:n,����:e,����ϵ:d,����רҵ:p,������λ:c,ְ��:w):");getchar();scanf("%c",&index_label);
    }

    switch(index_label){
    case 'n':return head->stu_num;break;
    case 'e':return head->stu_name;break;
    case 'd':return head->stu_dpm;break;
    case 'p':return head->stu_pfss;break;
    case 'c':return head->stu_cpn;break;
    case 'w':return head->stu_work;break;
    case 'a':{
        printf("\n\t%d\t%d\t%s\t%s\t%s\t%s\t\t%s",stu_count,head->stu_num,head->stu_name,head->stu_dpm,head->stu_pfss,head->stu_cpn,head->stu_work);
        break;}
    }//����һѧ��������Ϣ
}


struct data_form * get_elem(struct data_form *head,int stu_count,char choice){
 int each_stu;
    //printf("\n%s",head->prior->stu_num);//�����׽���Ƿ�ָ��ĩ���
    for(each_stu=1;each_stu<=stu_count;each_stu++){
        head=head->next;
        //printf("\n%s",head->stu_num);
    }
    //printf("%d",stu_count);

    switch(choice){
        case 'c':{char value[50];printf("\n�������޸ĵ�ֵ��");getchar();scanf("%s",&value);strcpy(index_by_label(head,0,stu_count),value);break;}//����ĳ����Ϣ
        case 'a':{printf("\n\n\t���\tѧ��\t����\tϵ\tרҵ\t������λ\tְ��");index_by_label(head,'a',stu_count);break;}//����һѧ����������Ϣ
    }

    head=return_to_head(head,stu_count);
    return head;

}

void search_by_index(struct data_form *head){//���ط���������ѧ������
    int stu_count,each_stu,amount=0;
    char index,value[50];
    printf("��������ҵ�ֵ��");
    scanf("%s",&value);

    printf("\n������ƥ�����Ϣ(ѧ��:n,����:e,����ϵ:d,����רҵ:p,������λ:c,ְ��:w):");
    getchar();scanf("%c",&index);//printf("%c",index);

    printf("\n\n\t���\tѧ��\t����\tϵ\tרҵ\t������λ\tְ��");

    for(stu_count=0;stu_count<=stus_count;stu_count++){
        //printf("%s",index_by_label(head,index,stu_count));
        if (strcmp(value,index_by_label(head,index,stu_count))==0&&stu_count!=0){
            index_by_label(head,'a',stu_count);
            head=return_to_head(head,stu_count);
            for(each_stu=0;each_stu<stu_count;each_stu++){head=head->next;}amount+=1;}
        head = head->next;
    }
    //printf("OK");
    //head = return_to_head(head,stus_count+1);
 printf("��%d��ѧ��",amount);

}

struct data_form * init_chain(struct data_form *head,int stus_init){//��ʼ������
    head = init_head(head);
    head = add_nude(head,1,stus_init,0);
    return head;
}

void get_status(struct data_form *head){
 int stu_count;
    printf("\n\n\t����������������������ǰ״̬��������������������");
    for(stu_count=0;stu_count<=stus_count;stu_count++){
        if(stu_count==0){printf("\n\t����������������������ͷ��������������������");printf("\n\n\t���\tѧ��\t����\tϵ\tרҵ\t������λ\tְ��");}
        else{index_by_label(head,'a',stu_count);}
        head=head->next;
    }
}

struct data_form * delete_form(struct data_form *head,int form_to_delete){
    struct data_form *form_copy;
 int form_count;
    for (form_count=0;form_count<form_to_delete;form_count++){head=head->next;}
    form_copy=head;
    form_copy->prior->next=form_copy->next;
    form_copy->next->prior=form_copy->prior;
    return_to_head(head,form_to_delete);
    free(form_copy);
    stus_count-=1;
    printf("ɾ���ɹ�");
    return head;
}

void main()
{
    struct data_form *head = NULL;
    char choice,next;
    int num,insert_num,insert_loca,times_count,stu_num,stu_count;

    printf("��ʼ������...");
    stus_count = 0;
    printf("\n������ѧ��������");
    scanf("%d",&num);

    head = init_chain(head,num);


    for (times_count=1;times_count<2;times_count++){
        get_status(head);
        printf("\n\n��������Ҫ���еĹ���(\n������:p,\n����ĳѧ����������Ϣ:a,\n����ѧ������ֵͬ:t,\nɾ��ĳѧ����������Ϣ:l���޸�ĳѧ����ĳ����Ϣ:c,\n)��");
        getchar();scanf("%c",&choice);
        switch(choice){
        case 'p':{
            printf("\n����������ѧ��ѧ�ţ�");scanf("%d",&stu_num);
            head=head->next;
            for (insert_loca=1;insert_loca<=stus_count;insert_loca++){if(stu_num<=head->stu_num){break;}else{head=head->next;}}
            head=return_to_head(head,insert_loca);
            head=add_nude(head,insert_loca,1,stu_num);
            break;}

        case 'a':{printf("\n��������Ҫ���ҵ�ѧ����ţ�");getchar();scanf("%d",&insert_num);get_elem(head,insert_num,'a');break;}
        case 't':{search_by_index(head);break;}
        case 'c':{printf("\n��������Ҫ������Ϣ��ѧ����ţ�");getchar();scanf("%d",&insert_num);get_elem(head,insert_num,'c');break;}
        case 'l':{printf("\n��������Ҫɾ����ѧ����ţ�");getchar();scanf("%d",&insert_num);delete_form(head,insert_num);break;}
        }
        printf("\n����һ����?(Y/N):");getchar();scanf("%c",&next);
        if(next=='Y'){times_count=0;}
}
 printf("\n�������н���");
}


