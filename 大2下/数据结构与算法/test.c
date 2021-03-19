#include<stdio.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

struct data_form{
    char stu_num[50];
    char stu_name[50];
    char stu_dpm[50];
    char stu_pfss[50];
    char stu_unit[50];
    char stu_work[50];

    struct data_form *prior;
    struct data_form *next;
};

struct data_form form_head,stu_one,stu_two,stu_three;


/*
void init_list(struct data_form L){//创建L表
    L.stu_num = (char *)calloc(LIST_INIT_SIZE,sizeof(char));
    if(!L.stu_num) exit("OVERFLOW");
    L.stu_name = (char *)calloc(LIST_INIT_SIZE,sizeof(char));
    if(!L.stu_name) exit("OVERFLOW");
    L.stu_dpm = (char *)calloc(LIST_INIT_SIZE,sizeof(char));
    if(!L.stu_dpm) exit("OVERFLOW");
    L.stu_pfss = (char *)calloc(LIST_INIT_SIZE,sizeof(char));
    if(!L.stu_pfss) exit("OVERFLOW");
    L.stu_unit = (char *)calloc(LIST_INIT_SIZE,sizeof(char));
    if(!L.stu_unit) exit("OVERFLOW");
    L.stu_work = (char *)calloc(LIST_INIT_SIZE,sizeof(char));
    if(!L.stu_work) exit("OVERFLOW");

}
*/

void init_head(){
struct data_form form_head;
char *p;
p = &form_head;
printf("%s\n",p);}

void put_elem(struct data_form L,char *p){//录入数据
    char str[100],*n;


    scanf("%s",&str);
    printf("%s",str);
    strcpy(L.stu_num,str);

    printf("%s",L.stu_num);



}

void main()
{
    void init_head();
    void put_elem(struct data_form L);

    init_head();
    put_elem(stu_one);

    /*
    init_list(stu_name)
    init_list(stu_dpm)
    init_list(stu_pfss)
    init_list(stu_unit)
    init_list(stu_work)
    */

	printf("OK");
}



