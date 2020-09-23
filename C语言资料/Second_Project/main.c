#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letter,transformed_letter;
    printf("请输入一个待转换的字母：\n");
    scanf("%c",&letter);
    transformed_letter = letter;
    if (letter <=64)printf("输入的字符不合法！");
    if (65 <= letter <= 89)transformed_letter += 32; printf("%c",transformed_letter);
    if (90 <= letter <=122)transformed_letter -=32; printf("%c",transformed_letter);
    if (letter >= 123)printf("输入的字符不合法！");
    return 0;
}
