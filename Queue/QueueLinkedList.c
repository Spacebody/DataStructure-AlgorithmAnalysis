/*
 * QueueLinkedList.c
 *
 * Queue implement
 * Implement by circle linkedlist
 *
 * By Spacebody
 *
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _QueueLinkedList_h_

typedef struct QueueRecord Queue;
typedef int ElemType;

#define MAX 5
#define EMPTY 0

Queue *Create(void); //initialize the queue
Queue *Enqueue(ElemType X, Queue *head); //enqueue
Queue *Dequeue(Queue *head); //dequeue
int Front(Queue *head); //get the elem at the front
int Rear(Queue *head); //get the elem at the rear
int IsEmpty(void); //exam whether it is empty
int IsFull(void); //exam whether it is full
void Print(Queue *head); //print out the elements in the queue
void Error(char s[]);  //print ou the error message
void Dispose(Queue *head); //dispose the queue

#endif /* QueueLinkedList.h */

struct QueueRecord
{
	ElemType elem;
	struct QueueRecord *next;
};

int Size;

int main(void)
{
	Queue *Q;
	Q = Create();
	Q = Enqueue(10,Q);
	Q = Enqueue(20,Q);
	Q = Enqueue(40,Q);
	Q = Enqueue(300,Q);
	Q = Enqueue(500,Q);
	Print(Q);
	printf("%d\n", Front(Q));
	printf("%d\n", Rear(Q));
	Q = Dequeue(Q);
	Q = Dequeue(Q);
	Print(Q);
	printf("%d\n", Front(Q));
	printf("%d\n", Rear(Q));
	Dispose(Q);
	Print(Q);
	return 0;
}

Queue *Create(void)
{
	Queue *head;
	head = (Queue *)malloc(sizeof(Queue));
	head->next = head;    //circle the linkedlist
	Size = EMPTY; //make it empty
	return head;
}


Queue *Enqueue(ElemType X, Queue *head)
{ 
	if(IsEmpty())
	{	
		head->elem = X; //assign if the head node hasn't been assigined the value
		Size++; //increase the size
	}
	else if(!IsEmpty() && !IsFull())
	{
		Queue *p,*q;
		p = (Queue *)malloc(sizeof(Queue));
		p->elem = X;
		p->next = head;
		q = head;
		while(q->next != head)
		{
			q = q->next; //fine the front element
		}
		q->next = p;
		head = p;
		Size++;
	}
	else if(IsFull())
	{
		Error("Full Queue!");
		exit(0);
	}
	return head;
}


Queue *Dequeue(Queue *head)
{
	if(!IsEmpty())
	{
		Queue *p, *q;
		p = head;
		while(p->next->next != head)
		{
			p = p->next;
		}
		q = p->next;
		p->next = head;
		free(q);
		Size--;
		return head;
	}
	else
	{
		Error("Empty Queue!");
		exit(0);
	}
}

int Front(Queue *head)
{
	if(!IsEmpty())
	{
		Queue *p;
		p = head;
		while(p->next != head)
		{
			p = p->next;
		}
		return p->elem;
	}
	else
	{
		Error("Empty Queue!");
		exit(0);
	}
}

int Rear(Queue *head)
{
	if(!IsEmpty())
	{
		return head->elem;
		
	}
	else
	{
		Error("Empty Queue!");
		exit(0);	
	}
}

int IsEmpty(void)
{
	return Size == EMPTY; 
}


int IsFull(void)
{
	return Size == MAX;
}


void Print(Queue *head)
{
	if(!IsEmpty())
	{
		int i;
		Queue *p;
		p = head;
		for (int i = 0; i < Size; i++)
		{ //print out the element
			printf("%d\n", p->elem);
			p = p->next;
		}
	}
	else
	{
		Error("Empty Queue!");
		exit(0);
	}
}


void Error(char s[])
{
	printf("%s\n", s);
}


void Dispose(Queue *head)
{
	Queue *p;
	p = head;
	while(p->next != head)
	{
		p = p->next;
	}
	p->next = NULL; //untie the circle

	while(head != NULL)
	{
		p = head;
		head = head->next;
		free(p);
	} //free the node one by one
	Size = EMPTY;
}


