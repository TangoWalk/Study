#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,result,num_one,num_two,num_three,num_four,r_one[4],r_two[4],r_three[4],r_four[4];
    printf("请按照以下顺序依次输入各行的值：ai1,ai2,ai3,ai4\n");
    for(i=0;i<=3;i++)
    {
        scanf("%d,%d,%d,%d",&num_one,&num_two,&num_three,&num_four);
        if(i == 0)
        {
            r_one[0] = num_one;
            r_one[1] = num_two;
            r_one[2] = num_three;
            r_one[3] = num_four;
            printf("行一输入完毕\n");
        }
        else if(i == 1)
        {
            r_two[0] = num_one;
            r_two[1] = num_two;
            r_two[2] = num_three;
            r_two[3] = num_four;
            printf("行二输入完毕\n");
        }

        else if(i == 2)
        {
            r_three[0] = num_one;
            r_three[1] = num_two;
            r_three[2] = num_three;
            r_three[3] = num_four;
            printf("行三输入完毕\n");
        }

        else
        {
            r_four[0] = num_one;
            r_four[1] = num_two;
            r_four[2] = num_three;
            r_four[3] = num_four;
            printf("行四输入完毕\n");
        }
    }


        for(i=1;i<=3;i++)
        {
            r_two[i] -= r_one[i] * r_two[0];
            r_three[i] -= r_one[i] * r_three[0];
            r_four[i] -= r_one[i] * r_four[0];
        }

    result = r_four[2] * r_two[3] * r_three[1] + r_two[1] * r_three[2] * r_four[3] + r_three[3] * r_four[1] * r_two[2] - r_four[2] * r_two[1] * r_three[3] - r_two[3] * r_three[2] * r_four[1] - r_three[1] * r_four[3] * r_two[2];

    printf("此四阶行列式的结果是%d\n",result);

    return 0;
}

