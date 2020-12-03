#include<stdio.h>
#include<string.h>
void main()
{
    int a;char str1[5][10];char str2[10];char str3[10];int i;char *p;
    printf("请输入字符串数组\n");
    for(a=0;a<5;a++)
        gets(str1[a]);
    if(strcmp(str1[0],str1[1])>0)
        strcpy(str2,str1[0]);
    else
        strcpy(str2,str1[1]);
    if(strcmp(str1[2],str2)>0)
        strcpy(str2,str1[2]);
    if(strcmp(str1[3],str2)>0)
        strcpy(str2,str1[3]);
    if(strcmp(str1[4],str2)>0)
        strcpy(str2,str1[4]);
    printf("the largest:%s\n",str2);
    while(1)
    {
        printf("请输入查询字符串或输入'ESC'退出程序\n");
        gets(str3);
        i=0;
        while(i<5)
        {
            if(p=strstr(str1[i],str3)!=NULL)
                printf("搜索结果为%s\n",str1[i]);
            i++;
            continue;
        }
        if(strcmp(str3,"ESC")==0)
            break;
    }
    return 0;
}
