#include <stdio.h>

char char_five[][5],char_lenth[5],char_partion[100];

main()
{
    void char_input();void char_len();void char_search();
    char_input();
    char_len();
    char_search();
    return 0;
}

void char_input()
{
    int char_count,each_count;

    for (char_count=0;char_count<5;char_count++)
    {
        printf("\nÇëÊäÈëµÚ%d¸ö×Ö·û´®£º",char_count+1);
        scanf("%s",char_five[char_count]);
        getchar();
    }

    return 0;
}

void char_len()
{
    int char_count,char_count_order;int char_order[5];

    for (char_count=0;char_count<5;char_count++)
    {
        char_lenth[char_count]=strlen(char_five[char_count]);
        printf("%d\n",char_lenth[char_count]);
    }



    return 0;

    /*for(j=0;j<5;j++)
        {
            for(i=0;i<4-j;i++)
            {
            if (char_lenth[i]<char_lenth[i+1]) {box=char_lenth[i];char_lenth[i]=char_lenth[i+1];char_lenth[i+1]=box;}
            }

        }
    */
}

void char_search()
{
    int lenth_c,char_num;
    printf("ÇëÊäÈëÐèÒª²éÕÒµÄ×Ö·û£º");
    scanf("%s",char_partion);
    for (char_num=0;char_num<5;char_num++)
    {
        if (char_partion==char_five[100][char_num])printf("Æ¥Åäµ½×Ö·û´®%d");
    }
    return 0;
}

