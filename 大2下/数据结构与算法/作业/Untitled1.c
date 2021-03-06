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
int stus_count;//学生总数
struct data_form *return_to_head(struct data_form *head,int stu_count){
 int each_stu;
    for(each_stu=1;each_stu<=stu_count;each_stu++){head=head->prior;}
    return head;}
struct data_form *init_head(struct data_form *head){//创建表头
    head=(struct data_form *)malloc(sizeof(struct data_form));//首元结点
    head->prior=NULL;//首元前驱和后继均为空
    head->next=NULL;
    return head;}
struct data_form *add_nude(struct data_form *head,int insert_loca,int insert_num,int num_check){//此函数可初始化链表，也可增加结点。
    //stus_count为学生总数，插入之前不需改变；insert_loca指明插入的位置，初始化时为0；insert_num指明插入的表数量。
    struct data_form *last = head;
    struct data_form *behind,*front;
    int stu_count,stu_num;
    char temp[50];
    if (insert_loca!=stus_count+1&&insert_loca!=1){//插入时启用
        for (stu_count=1;stu_count<insert_loca;stu_count++){last = last->next;behind = last->next;}//指向插入位置的前驱和后继
    }
    else if (insert_loca!=stus_count+1&&insert_loca==1){behind = head->next;}//指向插入位置的后继

    for (stu_count=1;stu_count<=insert_num;stu_count++){
        struct data_form *nude=(struct data_form*)malloc(sizeof(struct data_form));//创建新结点
        nude->prior=NULL;//循环开始时初始化nude
        nude->next=NULL;


        if (num_check==0){printf("\n请输入学生%d的学号：",stu_count);//每个表录入具体数据
        scanf("%d",&stu_num);
        nude->stu_num=stu_num;}
        else{stu_num=num_check; nude->stu_num=stu_num;}

        //printf("%s",nude->stu_num);

        printf("\n请输入学生%d的姓名：",stu_count);//每个表录入具体数据
        scanf("%s",&temp);
        strcpy(nude->stu_name,temp);

        printf("\n请输入学生%d的系：",stu_count);//每个表录入具体数据
        scanf("%s",&temp);
        strcpy(nude->stu_dpm,temp);

        printf("\n请输入学生%d的专业：",stu_count);//每个表录入具体数据
        scanf("%s",&temp);
        strcpy(nude->stu_pfss,temp);

        printf("\n请输入学生%d的工作单位：",stu_count);//每个表录入具体数据
        scanf("%s",&temp);
        strcpy(nude->stu_cpn,temp);

        printf("\n请输入学生%d的职务：",stu_count);//每个表录入具体数据
        scanf("%s",&temp);
        strcpy(nude->stu_work,temp);

        if(stu_count==1){front=nude;}

        last->next=nude;//last的后继指向nude
        nude->prior=last;//nude的前驱指向last
        //前面两个步骤的次序可逆

        last=last->next;//last的后继指回最后一个表nude

    }

    if (insert_loca!=stus_count+1&&insert_loca!=1){//插入时启用
        last->next=behind;behind->prior=last;}//插入点的后继指向插入位置的后一个表
        //for(int each=1;each<=stus_count-insert_loca;each++){behind=behind->next;}head->prior=behind;behind->next=head;}
    else if (insert_loca!=stus_count+1&&insert_loca==1){//插入时启用
        {head->next=front;front->prior=head;last->next=behind;behind->prior=last;}//指向插入位置的下一个表
    }
    else{last->next=head;head->prior=last;}//表头的前驱指向表尾...
    //表头也在计数范围内，为第0个表

    stus_count+=insert_num;

    return head;}

struct data_form * index_by_label(struct data_form *head,char index_label,int stu_count){
    if(index_label<97||index_label>122){
            printf("\n请输入需要查找的信息(学号:n,姓名:e,所属系:d,所属专业:p,工作单位:c,职务:w):");getchar();scanf("%c",&index_label);
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
    }//查找一学生所有信息
}


struct data_form * get_elem(struct data_form *head,int stu_count,char choice){
 int each_stu;
    //printf("\n%s",head->prior->stu_num);//测试首结点是否指向末结点
    for(each_stu=1;each_stu<=stu_count;each_stu++){
        head=head->next;
        //printf("\n%s",head->stu_num);
    }
    //printf("%d",stu_count);

    switch(choice){
        case 'c':{char value[50];printf("\n请输入修改的值：");getchar();scanf("%s",&value);strcpy(index_by_label(head,0,stu_count),value);break;}//更改某项信息
        case 'a':{printf("\n\n\t编号\t学号\t姓名\t系\t专业\t工作单位\t职务");index_by_label(head,'a',stu_count);break;}//查找一学生的所有信息
    }

    head=return_to_head(head,stu_count);
    return head;

}

void search_by_index(struct data_form *head){//返回符合条件的学生数组
    int stu_count,each_stu,amount=0;
    char index,value[50];
    printf("请输入查找的值：");
    scanf("%s",&value);

    printf("\n请输入匹配的信息(学号:n,姓名:e,所属系:d,所属专业:p,工作单位:c,职务:w):");
    getchar();scanf("%c",&index);//printf("%c",index);

    printf("\n\n\t编号\t学号\t姓名\t系\t专业\t工作单位\t职务");

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
 printf("共%d个学生",amount);

}

struct data_form * init_chain(struct data_form *head,int stus_init){//初始化链表
    head = init_head(head);
    head = add_nude(head,1,stus_init,0);
    return head;
}

void get_status(struct data_form *head){
 int stu_count;
    printf("\n\n\t——————————当前状态——————————");
    for(stu_count=0;stu_count<=stus_count;stu_count++){
        if(stu_count==0){printf("\n\t——————————表头——————————");printf("\n\n\t编号\t学号\t姓名\t系\t专业\t工作单位\t职务");}
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
    printf("删除成功");
    return head;
}

void main()
{
    struct data_form *head = NULL;
    char choice,next;
    int num,insert_num,insert_loca,times_count,stu_num,stu_count;

    printf("初始化链表...");
    stus_count = 0;
    printf("\n请输入学生数量：");
    scanf("%d",&num);

    head = init_chain(head,num);


    for (times_count=1;times_count<2;times_count++){
        get_status(head);
        printf("\n\n请输入需要运行的功能(\n插入结点:p,\n查找某学生的所有信息:a,\n查找学生的相同值:t,\n删除某学生的所有信息:l，修改某学生的某项信息:c,\n)：");
        getchar();scanf("%c",&choice);
        switch(choice){
        case 'p':{
            printf("\n请输入插入的学生学号：");scanf("%d",&stu_num);
            head=head->next;
            for (insert_loca=1;insert_loca<=stus_count;insert_loca++){if(stu_num<=head->stu_num){break;}else{head=head->next;}}
            head=return_to_head(head,insert_loca);
            head=add_nude(head,insert_loca,1,stu_num);
            break;}

        case 'a':{printf("\n请输入需要查找的学生编号：");getchar();scanf("%d",&insert_num);get_elem(head,insert_num,'a');break;}
        case 't':{search_by_index(head);break;}
        case 'c':{printf("\n请输入需要更改信息的学生编号：");getchar();scanf("%d",&insert_num);get_elem(head,insert_num,'c');break;}
        case 'l':{printf("\n请输入需要删除的学生编号：");getchar();scanf("%d",&insert_num);delete_form(head,insert_num);break;}
        }
        printf("\n再试一次吗?(Y/N):");getchar();scanf("%c",&next);
        if(next=='Y'){times_count=0;}
}
 printf("\n程序运行结束");
}


