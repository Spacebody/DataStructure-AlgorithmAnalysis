/**
 *将顺序表中的元素循环移动，默认自动创建自然数组
 *
 *By Spacebody
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _ListShift_h

#define MAXSIZE 10  //初始分配量
#define LISTINCREMENT 10  //存储空间的分配增量
#define FINISHED 1
#define ERROR 0
#define OVERFLOW -2
typedef int eleType;
typedef struct list seqList;

//函数声明
int initList(seqList *se); //初始化顺序表
int insertElement(seqList *se,eleType e); //插入元素
int printList(seqList se); //打印顺序表
int circleShift(seqList *se,int n,int k); //循环移动元素

#endif /* ListShift.h */

struct list //定义一个结构体
{
    eleType *elem;  //存储空间基地址
    int listSize;   //当前分配的内存
    int length;   //当前顺序表的长度
};

//主函数
int main(void)
{
    seqList *list = (seqList *)malloc(sizeof(seqList));
    initList(list);
    int n,k,i;
    printf("请输入数组长度:\n");
    scanf("%d",&n);
    printf("请输入右移位数:\n");
    scanf("%d",&k);

    for(i = 1;i<=n;i++)
    {
        insertElement(list,i);
    }
    printf("原始数组:");
    printList(*list);
    printf("右移后数组:");
    circleShift(list,n,k);
    printList(*list);
    return 0;
}

//初始化顺序表
int initList(seqList *se)
{
    se->elem = (eleType *)malloc(sizeof(eleType)); //指定每个元素的内存大小为 int 型
    if(!se->elem)
    {   //存储空间分配失败
        exit(OVERFLOW);
    }
    se->length = 0; //置空白长度为 0
    se->listSize = MAXSIZE; //制定顺序表最大长度
    return FINISHED;
}

//插入元素
int insertElement(seqList *se,eleType e)
{
    eleType *p;
    if(se->length >= se->listSize)
    {   //检查顺序表是否已满
        return ERROR;
    }
    else
    {
        p = se->elem+se->length-1;  //指向最后一个元素
        *(p+1) = e;  //插入最后一个元素的后继元
        ++se->length; //列表增加一位
    }
    return  FINISHED;
}

//打印顺序表
int printList(seqList se)
{
    int i;
    //输出顺序表元素
    for(i = 1;i<=se.length;i++)
    {
        printf("%d\t",se.elem[i-1]);
    }
    printf("\n"); //换行
    return FINISHED;
}

//循环移动元素
int circleShift(seqList *se,int n,int k)
{
    int i;
    eleType *p,*q,*temp;
    for(i=0; i<k; i++)
    {
        q=&(se->elem[0]); //每次都把最后一个元素调到第一个
        *temp=*(se->elem+se->length-1); //把最后一个元素取出存储
        p=se->elem+se->length-1; //指向最后一个元素位置
        for(;p>=q;p--)
        {
            *(p+1)=*p; //每个元素往后移动一位
        }
        *q = *temp; //移动结束后，把取出的元素放到第一个位置
    }
    return FINISHED;
}

