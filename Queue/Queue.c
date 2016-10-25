
/*
 * By Spacebody
 * EnQueue
 * Dequeue
 * Front
 * IsEmpty
 * IsFull
 * Print
 *
 * Implement the queue in circle
 * 实现使用循环队列，利用数组实现
 */

//implement in array

#include <stdio.h>
#include <stdlib.h>
#ifndef _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElemType;

struct QueueRecord
{
    int Front;
    int Rear;
    int Size;
    int Capacity;
    ElemType *Array;
};  //定义结构体作为队列

#endif /* Queue.h*/


#define MinQueueSize 5  //定义最小容量

int IsEmpty(Queue Q);  //检查是否为空
int IsFull(Queue Q);  //检查是够队满
void MakeEmpty(Queue Q);  //置为空队列
Queue CreateQueue(int MinSize);  //初始化队列
void EnQueue(ElemType X, Queue Q);  //入队
ElemType Front(Queue Q);  //取队列头元素
void Dequeue(Queue Q);  //出队
void Print(Queue Q);  //打印
void Error(char s[]);  //输出错误信息

int main(void)
{
    Queue Q;
    Q = CreateQueue(MinQueueSize);  //创建队列
    EnQueue(5, Q); //入队
    EnQueue(6, Q);
    EnQueue(10, Q);
    EnQueue(25, Q);
    Print(Q);  //打印
    printf("%d\n",Front(Q));  //取头元素
    Dequeue(Q);  //出队
    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);
    Print(Q);
    return 0;
}

//初始化队列
Queue CreateQueue(int MinSize)
{
    Queue Q;
    Q = malloc(sizeof(Queue));
    Q->Array = (ElemType *)malloc( sizeof(ElemType) * MinSize );
    Q->Capacity = MinSize;
    MakeEmpty(Q);
    return Q;
}

//置为空队列
void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = 0;
}

//检查是否为空
int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

//检查是否队满
int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

//入队
void EnQueue(ElemType X, Queue Q)
{
    
    if(IsFull(Q))
    {
        Error("Full Queue!");
    }
    else
    {
        Q->Size++;
        Q->Array[Q->Rear] = X;
        Q->Rear = (Q->Rear+1)% Q->Capacity;
    }
}

//取队列头元素
ElemType Front(Queue Q)
{
    return Q->Array[Q->Front];
}

//出队
void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
    {
        Error("Empty Queue!");
    }
    else
    {
        Q->Size--;
        Q->Front = (Q->Front+1)%Q->Capacity;
    }
}

//输出错误信息
void Error(char s[])
{
    printf("%s\n", s);
}


//按序列输出队列元素
void Print(Queue Q)
{
    if(IsEmpty(Q))
    {
        Error("Empty Queue!");
    }
    else
    {
        int i;
        for(i = 0; i< Q->Size; i++)
        {
            printf("%d\n", Q->Array[i]);
        }
    }
}





