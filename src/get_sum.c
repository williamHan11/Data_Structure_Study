/*阶和的递归实现代码*/

#include <stdio.h>
#include <stdlib.h>

long f(long);

long f(long n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + f(n-1);
    }
}

int main(void)
{
    int val, sum;

    printf("请输入一个数：");
    printf("val = ");
    scanf("%d", &val);

    if (val < 0)
    {
        printf("该数没有阶和！");
        exit(-1);
    }
    else
    {
        sum = f(val);
    }

    printf("%d 的阶和为 %ld", val, sum);

    return 0;
}
