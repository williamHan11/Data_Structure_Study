#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data; //数据域
    struct Node * pNext; //指针域
}NODE, *PNODE;

//函数声明
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int); //在pHead所指向的链表的第pos个节点前插入一个新的节点，该节点的值是val，并且pos的值是从1开始
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);

int main(void)
{
    PNODE pHead = NULL; //等价于 struct Node * pHead = NULL;
    pHead = create_list(); //create_list()功能：创建一个非循环单链表，并将该链表的头节点的地址赋给pHead
    traverse_list(pHead); //遍历
    sort_list(pHead);
    traverse_list(pHead);

    system("pause");
    return 0;
}

PNODE create_list(void)
{
    int len; //用来存放有效节点的个数
    int i;
    int val; //用来临沭存放用户输入的节点的值

    //分配了一个不存放有效数据的头节点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead)
    {
        printf("分配失败，程序终止");
        exit(-1);
    }

    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入您要生成的链表节点个数：len= ");
    scanf("%d",&len);

    for (i=0; i<len; ++i)
    {
        printf("请输入第%d个节点的值：", i+1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("分配失败，程序终止");
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;

    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");

    return;
}

bool is_empty(PNODE pHead)
{
    if (pHead->pNext == NULL)
        return true;
    else
        return false;
}

int length_list(PNODE pHead)
{
    int len;

    PNODE p = pHead->pNext;

    while (NULL != pHead->pNext)
    {
        ++len;
        p = p->pNext;
    }
    return len;
}

void sort_list(PNODE pHead)
{
    int i, j, t;
    int len = length_list(pHead);
    PNODE p, q;

    for (i=0, p=pHead->pNext; i<len-1; ++i, p=p->pNext)
    {
        for (j=0, q=p->pNext; j<len; ++j, q=q->pNext)
        {
            if (p->data > q->data)  //类似于数组中的：a[i] > a[j]
            {
                t = p->data; //类似于数组中的：t = a[i];
                p->data = q->data;  //类似于数组中的：a[i] = a[j];
                q->data = t;  //类似于数组中的：a[j] = t;
            }
        }
    }

    return;
}

//在pHead所指向的链表的第pos个节点前插入一个新的节点，该节点的值是val，并且pos的值是从1开始
bool insert_list(PNODE pHead, int pos, int val)
{
    int i = 0;
    PNODE p = pHead;

    //求pHead链表的长度
    while (NULL!=p && i<pos-1)
    {
        p = p->pNext;
        ++i; 
    }

    if (i>pos-1 || NULL == p)
        return false;

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("动态分配内存失败！\n");
        exit(-1);
    }
    pNew->data = val;
    PNODE q= p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;

    return true;
}

bool delete_list(PNODE pHead, int pos, int *pval)
{
    int i = 0;
    PNODE p = pHead;

    //求pHead链表的长度
    while (NULL!=p->pNext && i<pos-1)
    {
        p = p->pNext;
        ++i; 
    }

    if (i>pos-1 || NULL == p->pNext)
        return false;

    PNODE q = p->pNext;  //q表示要删除的数
    *pval = q->data;

    //删除p节点后面的节点
    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;

    return true;
}
