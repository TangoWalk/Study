#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letter,transformed_letter;
    printf("������һ����ת������ĸ��\n");
    scanf("%c",&letter);
    transformed_letter = letter;
    if (letter <=64)printf("������ַ����Ϸ���");
    if (65 <= letter <= 89)transformed_letter += 32; printf("%c",transformed_letter);
    if (90 <= letter <=122)transformed_letter -=32; printf("%c",transformed_letter);
    if (letter >= 123)printf("������ַ����Ϸ���");
    return 0;
}
