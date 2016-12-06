/*
*  StackLinkedList.c
* 
* Implement in linkedlist
*
* By Spacebody
*/




#ifndef _StackLinkedList_h

#include <stdio.h>
#include <stdlib.h>
typedef struct StackRecord Stack;
typedef int ElemType;
#define EMPTY -1
#define MAX 10

Stack *Create(void); //create the stack
Stack *Pop(Stack *head); //pop out the node
Stack *Push(ElemType X, Stack *head); //push the element and create a new node 
int IsEmpty(Stack *head); //exam whether it is empty
int IsFull(Stack *head); //exam whether it is full
ElemType Top(Stack *head); //get the top element from the stack 
void DisposeStack(Stack *head); //dispose the stack, which means disposing the linkedlist
void Print(Stack *head); //print out the elements in the stack

#endif /* StackLinkedList.h */

struct StackRecord
{
	ElemType elem;
	struct StackRecord *next;
};

//global variables can be modified everywhere
int Capacity = MAX; //the capacity of the stack
int Size; //the current size

int main(void)
{
	Stack *S;
	S = Create();	
 	S = Push(10, S);
 	S = Push(20, S);
 	S = Push(50, S);
 	S = Push(200, S);
 	printf("The top elem is %d\n", Top(S));
 	Print(S);
 	S = Pop(S);
 	S = Pop(S);
 	Print(S);
 	DisposeStack(S);
	return 0;
}

Stack *Create(void)
{
	Stack *head;
	head = (Stack *)malloc(sizeof(Stack));
	head->next = NULL; //initialize the node
	Size = 0; //make the size to be 0 then we can more easily exam the stack
	return head;
}

Stack *Pop(Stack *head)
{
	if(!IsEmpty(head))
	{
		Stack *p;
		p = head;
		head = head->next;
		Size--; //decrease the size if the elem is popped out
		free(p); //free the space 
		return head;
	}
	exit(0); //exit if stack is empty
}

Stack *Push(ElemType X, Stack *head)
{
	if(!IsFull(head))
	{
		Stack *p;
		p = (Stack *)malloc(sizeof(Stack));
		p->elem = X;
		p->next = head;
		head = p;
		Size++;
		return head;
	}
	exit(0); //exit if the stack is full
}


int IsEmpty(Stack *head)
{
	return Size == EMPTY;
}

int IsFull(Stack *head)
{
	return Size == Capacity;
}

ElemType Top(Stack *head)
{
	if(!IsEmpty(head))
	{
		return head->elem;  
	}
	exit(0);
}

void Print(Stack *head)
{
	if(head != NULL)
	{
		Stack *p;
		p = head;
		while(p->next!= NULL)
		{
			printf("%d\n", p->elem);
			p = p->next;
		}
	}
}

void DisposeStack(Stack *head)
{	
	Stack *p;
	while(head != NULL)
	{
		p = head;
		head = head->next;
		free(p); //free the node 
	}
	Size = EMPTY;
}



