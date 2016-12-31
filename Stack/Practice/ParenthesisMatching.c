//
//Use stack to test whether parenthesis in a string does match.
//
//By Spacebody
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //use the isalpha funtion

#ifndef  _StackArray_h 

#define EMPTY -1
#define MAX 50

typedef char ElemType;
typedef struct StackRecord *Stack;

//Funcitons
int IsEmpty(Stack S); //Is empty
int IsFull(Stack S);  //Is full
Stack CreateStack(int MaxSize); //create a stack
void DisposeStack(Stack S); //dispose the stack
ElemType Top(Stack S);  //get the elem in top
void Pop(Stack S);  //pop the elem out stack
void Push(ElemType X, Stack S); //push the elem into stack
void Print(Stack S); //print elements in the stack
void PareMatch(char test[], Stack S);

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
	char test1[]="(dbfef{dsdfsd]adfa}dfaf)"; //for test
	char test2[]="(sdvsv{dsdfs}sss[dsdfsd]df)";
	// printf("%s\n", test1);
	// PareMatch(test1, S);
	// Print(S);
	printf("%s\n", test2);
	PareMatch(test2, S);
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
void Pop(Stack S)
{
	if(!IsEmpty(S))
	{
		S->TopofStack--;
	}
}

//push the elem into stack
void Push(ElemType X, Stack S)
{
	if(!IsFull(S))
	{
		S->TopofStack++;
		S->array[S->TopofStack] = X;
	}
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
			printf("%c\n", S->array[i]);
		}
	}
}


void PareMatch(char test[], Stack S)
{
	int i;
	char a, b;
	for(i = 0;i < (int)strlen(test); i++)
	{
		if(isalpha(test[i]))
		{  //skip into next loop if char is an  alphabet
			continue;
		}
		
		if(test[i] == '(' || test[i] == '{' || test[i] == '[')
		{ //if the char is '(' or '{' or '[', then push into stack
			Push(test[i],S);
			continue; //skip the following codes to go on next loop
		}
		
		a = Top(S)+2; //the corresponding char according to ASCII
		b = Top(S)+1;
		if( a == test[i] || b == test[i])
		{  //if they are matched, pop out the top elemment
			Pop(S);
		}
		else
		{   //find the case which doesn't match, print put error then exit the application
			printf("Parenthesis doesn't match!\n");
			exit(0);
		}
	}
}