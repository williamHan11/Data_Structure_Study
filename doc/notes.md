# 1.数据结构概述
## 1.1 数据结构定义：什么叫数据结构？
我们如何把现实中大量而复杂的问题以特定的数据类型和特定的存储结构保存到主存储器（内存）中，以及在此基础上为实现某个功能（比如查找某个元素，删除某个元素，对所有元素进行排序）而执行的相应操作，这个相应的操作叫算法。<br><br>
即，如何保存一个个体，如何保存一个个体和个体之间的关系。解决了这个问题，就解决了数据存储的问题。<br><br>
数据结构解决存储的问题，算法解决操作的问题。<br><br>
当我们想要存储15个人的信息时，可以使用数组，但是当这个人数过大时，就没有办法使用数组了。因为数组是连续存储的，内存不够，这个问题就无法解决。数据过大，数据就无法存储，这个时候就可以使用链表来解决，这样就不需要连续存放。
数据结构 = 个体 + 个体的关系<br><br>
算法 = 对存储数据的操作

## 1.2 算法的定义
### 1.2.1 衡量算法的标准
主要是前面两个：<br>
1. 时间复杂度：大概程序要执行的次数，而非执行的时间。<br>
2. 空间复杂度：算法执行过程中，大概所占用的最大内存。<br>
3. 难易程度（编程实现时，最重要）<br>
4. 健壮性

### 1.2.2 数据结构的特点（地位）
数据结构是软件中最核心的课程<br>
程序 = 数据的存储 + 数据的操作 + 可以被计算机执行的语言

# 2.预备知识
## 2.1 指针
### 2.1.1 指针的重要性：
指针是C语言的灵魂

### 2.1.2 定义：
#### 2.1.2.1 地址：
内存单元的编号（CPU使用地址总线、控制总线、数据总线控制内存，地址线确定对哪一个地址进行控制，控制线确定读还是写，数据线进行数据传输）<br>
从0开始的非负整数<br>
范围：0——FFFFFFFF

#### 2.1.2.2 指针：
指针就是地址，地址就是指针<br>
指针变量是存放内存单元地址的变量<br>
指针的本质是一个操作受限的非负整数（不能加、乘、除）<br>
指针变量也是变量，只不过它存放的不能是内存单元的内容，只能存放内存单元的地址。普通变量前不能加*，常量和表达式前不能加&。

##### 2.1.2.2.1 分类：
1. 基本类型的指针<br>
2. 指针和一维数组的关系

##### 2.1.2.2.2 如何通过被调函数修改主调函数中普通变量的值？
实参为相关变量的地址<br>
形参为以该变量的类型为类型的指针变量<br>
在被调函数中通过 *形参变量名 的方式就可以修改主函数<br>
例程1:

```
#include <stdio.h>
int main(void)
{  
  int *p; //p是个变量名，int *表示该p变量只能存储int变量的地址
  int i=10;
  int j;
  
  p = &i; //p保存了i的地址，所以p指向i，修改i的值不改变p的值，修改p的值不改变i的值，即*p和i可以在任何情况下进行互换
  j = *p; //等价于j=i;
}
```
例程2：

```
#include <stdio.h>
void f(int * p)//不是定义了一个名字叫做*p的形参，而是定义了一个形参，该形参名字叫做p，它的类型是int *
{
  *p = 100;
}
int main(void)
{
  int i = 9;
  
  f(&i);
  printf(“i = %d\n”,i);
  
  return 0;
}
```
例程3：

```
#include <stdio.h>
int main(void)
{
  int a[5] = {1, 2, 3, 4, 5};
  
  //a[3] == *(3+a);
  printf(“%p\n”, a+1);
  printf(“%p\n”, a+2);
  printf(“%d\n”, *a+3);//*a+3等价于 a[0]+3
  
  return 0;
}
```
例程4：

```
#include <stdio.h>
void Show_Array(int * p, int len)
{
  p[2] = -1;//p[0] == *p  p[2] == *(p+2) == *(a+2) ==a[2]
  //p[i]就是主函数a[i]
}

int main(void)
{
  int a[5] = [1,2,3,4,5];
  Show_Array(a,5); //a等价于&a[0],&a[0]本身就是int *类型
  printf(“%d\n”,a[2]);
}
```

### 2.1.3 指针和数组
#### 2.1.3.1 指针和一维数组
##### 2.1.3.1.1 数组名
一维数组名是个指针常量，他存放的是一维数组第一个元素的地址，它的值不能被改变。<br>
一维数组名指向的是数组的第一个元素

##### 2.1.3.1.2 下标和指针的关系

```
a[i] <==> *(a+i)
```
假设指针变量的名字为p<br>
则p+i的值是p+i*（p所指向的变量所占字节数）<br>
指针变量指向的变量无论占多少个字节，其本身所占用字节数为4个字节。

##### 2.1.3.1.3 指针变量的运算
指针变量不能相加，不能相乘，不能相除<br>
如果两指针变量属于同一个数组，则可以相减<br>
指针变量可以加减一整数，前提是最终结果不能超过指针<br>
p+i的值是p+i*(p所指向的变量所占的字节数)<br>
p-i的值是p-i*(p所指向的变量所占的字节数)<br>
p++ <==> p+1

##### 2.1.3.1.4 举例：如何通过被调函数修改主调函数中一维数组的内容【如何界定】
两个参数：<br>
存放数组首元素的指针变量<br>
存放数组元素长度的整型变量

## 2.2 结构体
### 2.2.1 为什么会出现结构体？
为了表示一些复杂的数据，而普通的基本类型变量无法满足要求。

### 2.2.2 什么叫做结构体？
结构体是用户根据实际需要自己定义的复合数据类型。

### 2.2.3 如何使用结构体？
两种方式：<br>

```
Struct student st = {1000,”zhangsan”,20};
```

```
Struct student *pst=&st;
```

1. st.sid<br>
2. pst->sid：pst所指向的结构体变量中的sid这个成员

### 2.2.4 注意事项：
结构体变量不能加减乘除，但可以相互赋值<br>
普通结构体变量和结构体指针变量作为函数传参的问题<br>
例程1：

```
#include <stdio.h>
Struct student
{
  int sid;
  char name[200];
  int age;
};

int main(void)
{
  Struct student st = {1000,”zhangsan”,20};
  //st.sid = 99; //第一种方式
  
  Struct student *pst;
  pst = &st;
  pst->sid = 99; //pst->sid等价于(*pst).sid，而(*pst).sid等价于st.sid，所以pst->sid等价于st.sid
  
  return 0;
}
```
例程2：

```
#include <stdio.h>
#include <string.h>
Struct student
{
  int sid;
  char name[200];
  int age;
};

void f(struct student *pst);
void g(struct student st);
void g2(struct student *pst);
int main(void)
{
  Struct student st;
  f(&st);
  //g(st);
  g2(&st);
  
  return 0;
}

//这种方式耗内存，耗时间，不推荐
void g(struct student st)
{
  Printf(“%d %s %d\n”,st.sid,st.name,st.age);
}
void g2(struct student *pst)
{
  printf(“%d %s %d\n”,pst->sid,pst->name,pst->age);
}
void f(struct student *pst)
{
  (*pst).sid = 99;
  strcpy(pst->name,”zhangsan”);
  pst->age = 22;
}
```

## 2.3 动态内存的分配和释放
### 2.3.1 动态构造一维数组
#### 2.3.1.1 假设动态构造一个int型数组
实现代码：

```
#include <stdio.h>
#include <malloc.h>
int main(void)
{
  int a[5] = {4, 10, 2, 8, 6};
  
  int len;
  scanf(“%d”,&len);
  int * pArr = (int *)malloc(sizeof(int) * len);
  //*pArr = 4; //类似于a[0]=4
  //pArr[1] = 10;//类似于a[1]=10
  //printf(“%d %d\n”, *pArr, pArr[1]);
  
  //我们可以把pArr当做一个普通数组来使用
  for (int i=0; i<len; ++i)
  scanf(“%d”,&pArr[i]);
  
  for (i=0; i<len; ++i)
  printf(“%d\n”, *(pArr+i));
  free(pArr); //把pArr所代表的动态分配的20个字节的内存释放
  
  return 0;
}
```

1. 分配了两块内存，一块内存是动态分配的，总共len个字节；另一块是静态分配的，是pArr变量本身所占的内存，总共4个字节。<br>
2. malloc只有一个int型的形参，表示要求系统分配的字节数。<br>
3. malloc函数的功能时请求系统分配len个字节的内存空间，如果分配成功，则返回第一个字节的地址，如果分配不成功，则返回NULL。<br>
4. malloc函数能且只能返回第一个字节的地址，所以我们需要把这个无任何实际意义的第一个字节的地址（俗称干地址）转化为一个有实际意义的地址，因此，malloc函数前面必须加强制类型转换（数据类型*），表示把这个无实际意义的第一个字节的地址转化为响应类型的地址。<br>
5. free(*pArr)表示把pArr所指向的内存给释放掉，pArr本身的内存是静态的，不能由程序员手动释放，只能在pArr变量所在的函数运行终止时由系统自动释放。

#### 2.3.1.2 跨函数使用内存
实现代码：

```
#include <stdio.h>
#include <malloc.h>

Struct student
{
  int sid;
  int age;
};

Struct student * createstudent(void);
void showstudent(struct student *);

int main(void)
{
  Struct student * ps;
  
  ps = createstudent();
  Showstudent();
  
  return 0;
}

void showstudent(struct student *pst)
{
  printf(“%d %d\n”, pst->sid, pst->age);
}

Struct student * createstudent(void)
{
  Struct student * p = (struct student *)malloc(sizeof(struct student));
  p->sid = 99;
  p->age = 88;

  return p;
}
```

静态内存不可以库函数使用：
- 静态内存在函数执行期间可以被其他函数使用
- 静态内存在函数执行完毕之后就不能再被其他函数使用<br>
动态内存可以跨函数使用：
- 动态内存在函数执行完毕之后仍然可以被其他函数使用<br>
 
# 3.模块一：线性结构
什么是线性结构？
- 把所有的结点（数组的元素）用一根直线串起来

## 3.1 连续存储【数组】
1. 什么叫数组？
- 元素类型相同，大小相等<br>
2. 数组的优缺点（与链表比较）：
- 优点：存取速度快
- 缺点：
	- 实现必须知道数组的长度
	- 需要大块连续的内存块
	- 插入和删除元素很慢
	- 空间通常是有限制的
<br>
实现代码：

```
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//定义了一个数据类型，该数据类型，该数据类型的名字叫做struct Arr，该数据类型含有三个成员，分别是pBase，len，cnt；
Struct Arr
{
  int * pBase; //存储的是数组第一个元素的地址
  int len; //数组所能容纳的最大元素的个数
  int cnt; //当前数组有效元素的个数
  //int increment; //自动增长因子
}

void init_arr(struct Arrr *pArr, int length);
bool append_arr(struct Arr *pArr, int val); //追加元素
bool insert_arr(struct Arr *pArr, int pos, int val); //插入元素 pos的值从1开始
bool delete_arr(struct Arr *pArr, int pos, int *pVal); //删除元素
int get();
bool is_empty(struct Arrr *pArr); //判断数组是否为空
bool is_full(struct Arrr *pArr); //判断数组是否存满
void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void inversion_arr(struct Arr *pArr);

int main(void)
{
  Struct Arr arr;
  int val;
  
  init_arr(&arr, 6);
  Show_arr(&arr);
  Append_arr(&arr, 1);
  Delete_arr(&arr, 1, &val);
  
  return 0;
}

Void init_arr(struct Arr *pArr, int length)
{
  pArr->pBase = (int *)malloc(sizeof(int) * length);
  if (NULL == pArr->pBase)
  {
    printf(“动态内存分配失败！”);
    exit(-1); //终止整个程序
  }
  else
  {
    pArr->len = length;
    pArr->cnt = 0;
  }
  
  return;
}

bool is_empty(struct Arrr *pArr)
{
  if (0 == pArr->cnt)
    return True;
  else
    return false;
}

Bool is_full(struct Arrr *pArr)
{
  if (pArr->cnt == pArr->len)
    return true;
  else
    return false;
}

void show_arr(struct Arr *pArr)
{
  if (is_empty(pArr) == True)
  {
    printf(“数组为空！\n”);
  }
  else
  {
    for (i=0; i<pArr->cnt; ++i)
    printf(“%d”, pArr->pBase[i]);
    printf(“\n”);
  }
}

bool append_arr(struct Arrr *pArr, int val)
{
  //存满时返回false
  if (is_full(pArr))
    return false;
  //未存满时追加
  else
  {
    pArr->pBase[pArr->cnt] = val;
    (pArr->cnt)++;
    return True;
  }
}

bool insert_arr(struct Arr *pArr, int pos, int val)
{
  int i;
  if (is_full(pArr))
    return false;
    
  if (pos<1 || pos>pArr->cnt+1)
    return false;
  for (i=pArr->cnt-1; i>=pos-1; --i)
  {
    pArr->pBase[i] = pArr->pBase[i+1];
  }
  pArr->pBase[pos-1] = val;
  (pArr->cnt)++;
  
  return true;
}

bool delete_arr(struct Arr *pArr, int pos, int *pVal)
{
  int i;
  
  if (is_empty(pArr))
    return false;
  if (pos<1 || pos>pArr->cnt)
    return false;
    
  *pVal = pArr->pBase[pos-1];
  for (i=pos; i<pArr->cnt; ++i)
  {
    pArr->pBase[i-1] = pArr->pBase[i];
  }
  pArr->cnt--;
  
  return true;
}

void inversion_arr(struct Arr *pArr)
{
  int i = 0;
  int j = pArr->cnt-1;
  int t;
  
  while (i<j)
  {
    t = pArr->pBase[i];
    pArr->pBase[i] = pArr->pBase[j];
    pArr->pBase[j] = t;
    ++i;
    --j;
  }
  
  return;
}

void sort_arr(struct Arr *pArr)
{
  int i,j;
  
  for (i=0; i<pArr->cnt; ++i)
  {
    for (j=i+1; j<pArr->cnt; ++j)
    {
      if (pArr->pBase[i] > pArr->pBase[j])
      {
        t = pArr->pBase[i];
	pArr->pBase[i] = pArr->pBase[j];
	pArr->pBase[j] = t;
      }
    }
  }
}
```

## 3.2 离散存储【链表】
### 3.2.1 Typedef的用法
例程一：

```
#include<stdio.h>

Typedef Struct student
{
  int sid;
  char name[100];
  char sex;
}ST;

int main(void)
{
  Struct student st; //等价于ST st；
  Struct student * ps = &st; //等价于ST * ps;

  ST st2;
  St2.sid = 200;
  printf(“%d\n”, st2.sid);
	
  return 0;
}
```
例程2：

```
#include<stdio.h>

Typedef Struct student
{
  int sid;
  char name[100];
  char sex;
}*PSTU, STU; //等价于STU代表了struct student, PSTU代表了struct student *

int main(void)
{
  STU st; //struct student st
  PSTU ps = &st; //struct student * ps = &st;
  ps->sid = 99
  printf(“%d\n”, ps->sid);
  
  return 0;
}
```

### 3.2.2 链表介绍
#### 3.2.2.1 定义：
n个节点离散分配<br>
彼此通过指针相连<br>
每个节点只有一个前驱节点，每个节点只有一个后续节点<br>
首节点没有前驱节点 尾节点没有后续节点

#### 3.2.2.2 链表的优缺点
优点：
- 空间没有限制；
- 插入删除元素很快<br>
缺点：存取速度很慢

#### 3.2.2.3 专业术语：
- 首节点：第一个有效的节点
- 尾节点：最后一个有效的节点
- 头节点：头节点的数据类型和首节点类型一样，第一个有效节点之前的那个节点，头节点并不存放有效数据，加头节点的目的主要是为了对链表的操作。
- 头指针：指向头节点的指针变量
- 尾指针：指向尾节点的指针变量<br>

Q：如果希望通过一个函数来对链表进行处理，我们至少需要接收链表的哪些参数？<br>
A：只需要一个参数：头指针；因为我们通过头指针可以推算出链表的其他所有参数。

#### 3.2.2.4 分类：
链表的结构体包含两个变量，一个是数据域，另一个是指向下一个节点的指针。

```
#include <stdio.h>

typedef struct Node
{
    int data; //数据域
    struct Node * pNext; //指针域
}NODE, *PNODE;
```

##### 3.2.2.4.1 单链表
每一个节点的指针域只能指向后一个节点

##### 3.2.2.4.2 双链表
每一个节点有两个指针域，一个指向后节点，一个指向前节点

##### 3.2.2.4.3 循环链表
能通过任何一个节点找到其他所有的节点

##### 3.2.2.4.4 非循环链表
#### 3.2.2.5 算法
狭义的算法是与数据的存储方式密切相关的<br>
广义的算法是与数据的存储方式无关的<br>
泛型：利用某种技术达到的效果就是：不同的存储方式，执行的操作是一样的<br>
遍历、查找、清空、销毁、求长度、排序、删除节点、插入节点<br>
实现代码：

```
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
```

## 3.3 线性结构的应用
### 3.3.1 栈
#### 3.3.1.1 定义
一种可以实现“先进后出”的存储结构<br>
栈类似于箱子

#### 3.3.1.2 分类
静态栈：以数组为内核<br>
动态栈：以链表为内核

#### 3.3.1.3 算法
出栈<br>
压栈<br>
实现代码：

```
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
```

#### 3.3.1.4 应用
函数调用
中断
表达式求值（计算器）
内存分配
缓冲处理
迷宫

### 3.3.2 队列
#### 3.3.2.1 定义
一种可以实现“先进先出”存储结构

#### 3.3.2.2 分类
链式队列——用链表实现<br>
静态队列——用数组实现：静态队列通常都必须是循环队列；

##### 3.3.2.2.1 循环队列
1. 静态队列为什么必须是循环队列？<br>
A：普通队列的参数front和rear只增不减，导致内存浪费。<br><br>
2. 循环队列需要几个参数来确定？及其含义的讲解？<br>
A：需要两个参数来确定，front/rear。<br><br>
3. 循环队列各个参数的含义？<br>
A：两个参数不同场合有不同的含义；建议初学者先记住，然后慢慢体会。
   - 1.队列初始化：front和rear的值都是零。
   - 2.队列非空：front代表队列的第一个元素，rear代表队列的最后一个有效元素的下一个元素。
   - 3.队列空：front和rear的值相等，但不一定是零。<br><br>
4. 循环队列入队伪算法讲解（在尾部入队）<br>
A：第一步：将值存入rear所指向的位置
   第二步：rear=(rear+1)%数组的长度<br><br>
5. 循环队列出队伪算法讲解（在头部出队）<br>
A：front=(front+1)%数组的长度<br><br>
6. 如何判断循环队列是否为空？<br>
A：如果front与rear的值相等，则该队列一定为空<br><br>
7. 如何判断循环队列是否已满？<br>
A：预备知识：front值可能比rear大，front值也可能比rear小，两者也可能相等。
   - 第一种方法：多增加一个标识参数，即数组的长度
   - 第二种方法（常用）：少用一个元素，即长度为10只使用9个空间存放数据；如果front==(rear+1)%数组的长度，则循环队列已满

#### 3.3.2.3 具体应用
所有和时间有关的操作都有队列的影子

## 3.4 专题：递归
### 3.4.1 定义
一个函数自己直接或间接调用自己

### 3.4.2 例一：1+2+3+4+…+100的和
实现代码：

```
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
```

### 3.4.3 例二：求阶乘
使用For循环的实现代码：

```
/*阶乘的for循环实现代码*/

#include <stdio.h>

int main(void)
{
    int val;
    int i, mult = 1;

    printf("请输入一个数字：");
    printf("val = ");
    scanf("%d",&val);

    for (i=1; i<=val; ++i)
    {
        mult = mult * i;
    }

    printf("%d 的阶乘是：%d\n", val, mult);

    return 0;
}
```
使用递归的实现代码：

```
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
```

### 3.4.4 例三：汉诺塔
汉诺塔的规则在于n与n-1的差值为2^(n-1) <br>
3.4.5 走迷宫
4 模块二：非线性结构
树
图
5 模块三：查找和排序
折半查找
排序：冒泡
		插入
		选择
		快速排序
		归并排序
6 Java中容器和数据结构相关知识
Ierator接口
Map
哈希表
