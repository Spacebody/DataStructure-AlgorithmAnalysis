/*Stack.c
 * Implement stack in array 
 *
 * By Spacebody
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef  _StackArray_h 

#define EMPTY -1
#define MAX 10

typedef int ElemType;
typedef struct StackRecord *Stack;

//Funcitons
int IsEmpty(Stack S); //Is empty
int IsFull(Stack S);  //Is full
Stack CreateStack(int MaxSize); //create a stack
void DisposeStack(Stack S); //dispose the stack
ElemType Top(Stack S);  //get the elem in top
int Pop(Stack S);  //pop the elem out stack
int Push(ElemType X, Stack S); //push the elem into stack
void Print(Stack S); //print elements in the stack

#endif /* StackArray.h */

struct StackRecord
{
	int Capacity;
	int TopofStack;
	ElemType *array;
};



int main(void)
{
	Stack S;
	S = CreateStack(MAX);
	Push(5,S);
	Push(10,S);
	Push(200,S);
	Push(100,S);
	printf("%d\n", Top(S));
	Print(S);
	Pop(S);
	Pop(S);
	printf("%d\n", Top(S));
	Print(S);
	DisposeStack(S);
	return 0;
}

//create stack
Stack CreateStack(int MaxSize)
{
	Stack S;
	S = malloc(sizeof(Stack));
	S->array = (ElemType *)malloc(sizeof(ElemType)*MaxSize);
	S->Capacity = MaxSize;
	S->TopofStack = EMPTY;
	return S;
}

//dispose the stack
void DisposeStack(Stack S)
{
	free(S->array);
	free(S);
}

//Is empty
int IsEmpty(Stack S)
{
	return S->TopofStack == EMPTY; 
} 

//Is full
int IsFull(Stack S)
{
	return S->Capacity == S->TopofStack;;
}

//get the elem in top
ElemType Top(Stack S)
{
	if(!IsEmpty(S))
	{
		return S->array[S->TopofStack];
	}
	exit(0);
}

//pop the elem out stack
int Pop(Stack S)
{
	if(!IsEmpty(S))
	{
		S->TopofStack--;
		return 1;
	}
	exit(0);
}

//push the elem into stack
int Push(ElemType X, Stack S)
{
	if(!IsFull(S))
	{
		S->TopofStack++;
		S->array[S->TopofStack] = X;
		return 1;
	}
	exit(0);
}

//print elements in the stack
void Print(Stack S)
{
	if(IsEmpty(S))
	{
		printf("Empty Stack!\n");
	}
	else
	{
		int i;
		for(i = S->TopofStack; i >= 0;i--)
		{
			printf("%d\n", S->array[i]);
		}
	}
}


