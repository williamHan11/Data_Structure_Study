/*循环队列实现代码*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct queue
{
    int * pBase; //存放数据的数组
    int front;
    int rear;
}QUEUE, *PQUEUE;

#define queue_size  6
/*初始化队列*/
void init(PQUEUE);
/*数据入队*/
bool en_queue(PQUEUE, int);
/*数据遍历*/
void traverse_queue(PQUEUE);
/*判断队列是否为满*/
bool full_queue(PQUEUE);
/*数据出队*/
bool out_queue(PQUEUE, int *);
/*判断队列是否为空*/
bool empty_queue(PQUEUE);

int main(void)
{
    QUEUE q;
    int val;

    init(&q);
    en_queue(&q, 1);
    en_queue(&q, 2);
    en_queue(&q, 3);
    en_queue(&q, 4);
    en_queue(&q, 5);
    traverse_queue(&q);
    out_queue(&q,&val);

    traverse_queue(&q);

    return 0;
}

void init(PQUEUE pQ)
{
    pQ->pBase = (int *)malloc(sizeof(int) * queue_size);
    pQ->front = 0;
    pQ->rear = 0;

    return;
}

bool full_queue(PQUEUE pQ)
{
    if (pQ->front == (pQ->rear + 1) % queue_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool en_queue(PQUEUE pQ, int val)
{
    if (full_queue(pQ))
    {
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear+1) % queue_size;
        return true;
    }
}

void traverse_queue(PQUEUE pQ)
{
    int i = pQ->front;

    while(i != pQ->rear)
    {
        printf("%d ",pQ->pBase[i]);
        i = (i+1) % queue_size;
    }
    printf("\n");
    return;
}

bool empty_queue(PQUEUE pQ)
{
    if (pQ->front == pQ->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool out_queue(PQUEUE pQ, int * pVal)
{
    if (empty_queue(pQ))
    {
        printf("队列为空！\n");
        return false;
    }
    else
    {
        *pVal = pQ->pBase[pQ->front];
        pQ->front = (pQ->front+1) % queue_size;
        printf("出栈元素的值为 %d\n", *pVal);

        return true;
    }
}
