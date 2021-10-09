/*阶乘的递归实现代码*/

#include <stdio.h>
#include <stdlib.h>

long f(long);

long f(long n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }
    else
    {
        return f(n-1) * n;
    }
}

int main(void)
{
    int val, mult;

    printf("请输入一个数字：");
    printf("val = ");
    scanf("%d",&val);

    if (val<0)
    {
        printf("该数无法计算阶乘！\n");
        exit(-1);
    }
    else
    {
        mult = f(val);
    }

    printf("%d 的阶乘是：%ld\n", val, mult);

    return 0;
}
