//
//Expression tree 
//
//Transfer suffix to an expression tree
//Use stack to store tree node 
//
//Traverse the tree in inorder, which expresses the expression as the form of infix notation
//Do not consider the priority of the arithmetic operator
//
//By Spacebody

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#ifndef _ExpressionTree_h

struct TreeNode;
struct StackRecord;
typedef struct TreeNode *Tree;
typedef struct StackRecord *Stack;
typedef char ElemType;
#define EMPTY -1
#define MAX 10
#define EXPRESSION 100

//Funcitons of stack
int IsEmpty(Stack S); //Is empty
int IsFull(Stack S);  //Is full
Stack CreateStack(int MaxSize); //create a stack
void DisposeStack(Stack S); //dispose the stack
Tree Top(Stack S);  //get the elem in top
int Pop(Stack S);  //pop the elem out stack
int Push(Tree T, Stack S); //push the elem into stack

//functions of tree
Tree PostfixToTree(Tree T, Stack S);
void InOrder(Tree T); //traversal in preorder

#endif /* ExpressionTree.h */

struct TreeNode 
{
	ElemType elem;
	Tree Left;
	Tree Right;
};

struct StackRecord
{
	int Capacity;
	int TopofStack;
	Tree *array;
};

//driving functions
int main(void)
{
	Tree T;
	Stack S;
	S = CreateStack(MAX);
	T = PostfixToTree(T, S);
	InOrder(T);
	printf("\n");
	DisposeStack(S);
	return 0;
}

Tree PostfixToTree(Tree T, Stack S)
{
    ElemType elem[EXPRESSION];
    scanf("%s",elem); //get the expression
    int i = 0;
    while(i < (int)strlen(elem) && elem[i] != '\0')
    {
        if(!(T = (Tree)malloc(sizeof(struct TreeNode))))
       	{
           	printf("Out of Space!");
           	exit(0);
       	}
       	else
       	{
            if(isalpha(elem[i]))
            { //if element is a letter, create a node store and push into the stack 
                T->elem = elem[i];
                T->Left = T->Right = NULL;
                Push(T, S);
            }
            else
            {  //if not a letter, then get two elements to make a binary tree and pop out those two elements
                Tree Tmp1, Tmp2;
                Tmp1 = (Tree)malloc(sizeof(struct TreeNode));
                Tmp2 = (Tree)malloc(sizeof(struct TreeNode));
                Tmp1->Left = Tmp1->Right = Tmp2->Left = Tmp2->Right = NULL;
                Tmp2 = Top(S);
                Pop(S);
                Tmp1 = Top(S);
                Pop(S);
                T->elem = elem[i];
                T->Left = Tmp1;
                T->Right = Tmp2;
                Push(T, S); //push the root of the tree into stack
            }
       	}
        i++;
    }
    return T;
}


void InOrder(Tree T)
{
	if(T)
	{
		InOrder(T->Left);
		printf("%c\t", T->elem);
		InOrder(T->Right);
	}
}

Stack CreateStack(int MaxSize)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct StackRecord));
	S->array = (Tree *)malloc(sizeof(Tree)*MaxSize);
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
Tree Top(Stack S)
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
int Push(Tree T, Stack S)
{
	if(!IsFull(S))
	{
		S->TopofStack++;
		S->array[S->TopofStack] = T;
		return 1;
	}
	exit(0);
}
