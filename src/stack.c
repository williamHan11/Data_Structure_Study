#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, * PNODE;

typedef struct stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, int);
bool pop(PSTACK, int *);
void traverse(PSTACK);
bool empty(PSTACK);
void clear(PSTACK);

int main(void)
{
    STACK S; 
    int val;

    init(&S); //目的是造出一个空栈
    push(&S, 1); //压栈
    push(&S, 2);

    pop(&S, &val);
    traverse(&S); //遍历输出

    return 0;
}

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (NULL == pS->pTop)
    {
        printf("动态内存分配失败！");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;  //或pS->Bottom->pNext = NULL;    
    }

    return;
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop; //pS->pTop不能改成pS->pBottom
    pS->pTop = pNew;

}

void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;

    while(p != pS->pBottom)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
    
    return;
}

bool empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//把pS所指向的栈顶数据出栈，并把出栈的元素存入pVal形参所指向的变量中，如果出栈失败，返回false，否则返回true
bool pop(PSTACK pS, int *pVal)
{
    PNODE p = pS->pTop;

    if (empty(pS) == true) //pS本身存放的就是S的地址
    {
        printf("该栈为空栈！");
        return false;
    }
    else
    {
        pS->pTop = p->pNext;
        *pVal = p->data;
        free(p);
        p = NULL;

        return true;
    }
}

//clear清空
void clear(PSTACK pS)
{
    if (empty(pS) == true)
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;

        while (p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
    }
}
