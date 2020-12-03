#include <stdio.h>
#include <string.h>

char char_five[][5],char_searched[];
int char_lenth[5];

int main()
{
    void char_create();void char_len();void char_search_input();
    char_create();
    char_len();
    char_search_input();
    return 0;
}

void char_create()
{
    int char_count,char_size,count=0;
    char char_tem[1000];

    printf("请输入五个字符串：(格式：a*b*c*d*e*)");
    scanf("%s",char_tem[1000]);

    for (char_count=0;char_count<5;char_count++)
    {
        for (char_size=0;char_size<1000;char_size++)
        {
          char_five[char_size][char_count]=char_tem[count];
          count++;
          if(char_tem[char_size]=='*')continue;
        }
    }

    return 0;
}

void char_len()
{
    int char_count;

    for (char_count=0;char_count<5;char_count++)
    {
        char_lenth[char_count]=strlen(char_five[char_count]);
        printf("%d",char_lenth[char_count]);
    }

    return 0;
}

void char_search_input()
{
    int lenth_c,char_num;
    void char_search_process();
    printf("请输入需要查找的字符：");
    scanf("%s",char_searched);
    char_search_process();
    return 0;
}

void char_search_process()
{
    int char_amount,char_count,char_searched_count,char_searched_lenth,times,count=0;
    int first_matched_location[100][5];
    char char_tem[100];

    char_searched_lenth=strlen(char_searched);
    printf("%d",char_searched_lenth);

    for (char_amount=0;char_amount<5;char_amount++)
    /*for (char_searched_count=0;char_searched_count<char_searched_lenth;char_searched_count++)
    for (char_count=0;char_count<char_lenth[char_amount];char_count++)*/
    {
        for (times=0;times<char_lenth[char_amount]-char_searched_lenth+1;times++)
        {
             for (char_searched_count=0;char_searched_count<char_searched_lenth;char_searched_count++)
             {
                char_tem[count]=char_five[char_searched_count][char_amount];
                count++;
             }
             printf("%s\n",char_tem);
            if(strcmp(char_tem,char_searched)==0)printf("%d %d",char_searched_count,char_amount);
            count=0;
        }

    }
}
