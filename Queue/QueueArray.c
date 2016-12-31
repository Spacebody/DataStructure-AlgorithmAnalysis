
/*
 * By Spacebody
 * 
 *
 * Implement the queue in circle by array
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#ifndef _QueueArray_h

typedef struct QueueRecord *Queue;
typedef int ElemType;
#define MinQueueSize 5 
int IsEmpty(Queue Q);  //exam whether it is empty
int IsFull(Queue Q);  //exam whether it is full
void MakeEmpty(Queue Q);  //empty the queue
Queue CreateQueue(int MinSize);  //initialize the queue
void EnQueue(ElemType X, Queue Q);  //enqueue
ElemType Front(Queue Q);  //get the front element of the queue
void Dequeue(Queue Q);  //dequeue
void Print(Queue Q);  //print out the elements
void Error(char s[]);  //print out the error messages

#endif /* QueueArray.h*/

struct QueueRecord
{
    int Front;
    int Rear;
    int Size;
    int Capacity;
    ElemType *Array;
};  //ues struct to implement the queue


int main(void)
{
    Queue Q;
    Q = CreateQueue(MinQueueSize); 
    EnQueue(5, Q); 
    EnQueue(6, Q);
    EnQueue(10, Q);
    EnQueue(25, Q);
    Print(Q);  
    printf("%d\n",Front(Q)); 
    Dequeue(Q);  
    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);
    Print(Q);
    return 0;
}


Queue CreateQueue(int MinSize)
{
    Queue Q;
    Q = malloc(sizeof(struct QueueRecord));
    Q->Array = (ElemType *)malloc( sizeof(ElemType) * MinSize );
    Q->Capacity = MinSize; //assign the value to limit the queue
    MakeEmpty(Q); //empty the queue
    return Q;
}


void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = 0;
}


int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}


int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}


void EnQueue(ElemType X, Queue Q)
{
    
    if(IsFull(Q))
    {
        Error("Full Queue!");
    }
    else
    {
        Q->Size++; //increase the size of the queue if element is enqueued
        Q->Array[Q->Rear] = X; //assign the last value to the rear
        Q->Rear = (Q->Rear+1)% Q->Capacity; //change the location of the rear
    }
}


ElemType Front(Queue Q)
{
    return Q->Array[Q->Front];
}


void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
    {
        Error("Empty Queue!");
    }
    else
    {
        Q->Size--; //decrease the size if element is dequeued
        Q->Front = (Q->Front+1)%Q->Capacity; //withdraw the front
    }
}


void Error(char s[])
{
    printf("%s\n", s);
}



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





