//
//Binary tree to recover the tree (A(B(E(K,L),F),C(G),D(H(M),I,J)))
//Traverse the tree in recursion/non-recursion algorithms
//Traverse the tree in depth first(preorder/inorder/postorder)
//Traverse the tree in breath first
//
//Enter "ABDH##I##EJ###CFL###G###" to test
//By Spacebody
//
//



#ifndef _BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode *Tree;
typedef struct QueueRecord *Queue;
typedef struct StackRecord *Stack;
typedef char ElemType;
#define MAX 10
#define EMPTY -1

//functions of tree
Tree CreateTree(Tree T); //create the tree
int SumLeaf(Tree T); //count the sum of leaves
int Depth(Tree T); //count the depth of the binary tree
ElemType Get(Tree T); //get the element
void Set(ElemType X, Tree T); //set the element
int HasChild(Tree T); //exam wether the node has child

//recursion alogrithm
/*  depth first traversal  */
void PreOrder(Tree T); //traversal in preorder
void InOrder(Tree T); //traversal in inorder
void PostOrder(Tree T); //traversal in postorder

/*breath first traversal */
void BreadthFirst(Tree T,Queue Q);//breath first traversal

//functions of queue
Queue CreateQueue(int MAXSIZE); //create queue
void EnQueue(Tree T, Queue Q); //enqueue
Tree DeQueue(Queue Q); //dequeue
int IsEmptyQueue(Queue Q); //is empty
int IsFullQueue(Queue Q); //is full
void Error(char s[]); //return error message

//non-recursion algorithm
void NonRePreOrder(Tree T, Stack S);
void NonReInOrder(Tree T, Stack S);
void NonRePostOrder(Tree T, Stack S);

//functions of stack
int IsEmptyStack(Stack S); //Is empty
int IsFullStack(Stack S);  //Is full
Stack CreateStack(int MaxSize); //create a stack
Tree Top(Stack S);  //get the elem in top
int Pop(Stack S);  //pop the elem out stack
int Push(Tree T, Stack S); //push the elem into stack

#endif /* BinaryTree.h */

struct TreeNode
{
    ElemType elem;
    Tree Left;
    Tree Right;
};

struct QueueRecord
{
    struct TreeNode *(*elem); //use structure pointer array to store the pointer of node of the tree
    int front;
    int rear;
    int Capacity;
    int Size;
};

struct StackRecord
{
    struct TreeNode *(*elem);
    int TopofStack;
    int Capacity;
};


//Drivring function
int main(void)
{

    Tree T;
    Queue Q;
    Stack S;
    T = CreateTree(T);
    Q = CreateQueue(MAX);
    S = CreateStack(MAX);
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");
    printf("%d\n", SumLeaf(T));
    printf("%d\n", Depth(T));
    BreadthFirst(T, Q);
    printf("\n");
    NonRePreOrder(T, S);
    printf("\n");
    NonReInOrder(T, S);
    printf("\n");
    NonRePostOrder(T, S);
    printf("\n");
    return 0;

}


Tree CreateTree(Tree T)
{ //create the tree in inorder
    ElemType elem;
    elem = getchar(); //get the string "ABDH##I##EJ###CFL###G###"
    if(elem == '#')
    {  //if the character is '#', the end the pointer
        T = NULL; 
    }
    else
    {
        if(!(T=(Tree)malloc(sizeof(struct TreeNode))))
        {
            printf("Error!");
            exit(0);
        }
        T->elem = elem;
        T->Left = CreateTree(T->Left);  //Call the function in recursion
        T->Right = CreateTree(T->Right); 
    }
    return T;
}


void PreOrder(Tree T)
{   
    if(T)
    {
        printf("%c\t", T->elem);
        PreOrder(T->Left); //Call the function in recursion
        PreOrder(T->Right);
    }
}

void InOrder(Tree T)
{    
    if(T)
    {
        InOrder(T->Left); //Call the function in recursion
        printf("%c\t", T->elem);
        InOrder(T->Right);
    }
}

void PostOrder(Tree T)
{   
    if(T)
    { 
        PostOrder(T->Left); //Call the function in recursion
        PostOrder(T->Right);
        printf("%c\t", T->elem);
    }
}

int SumLeaf(Tree T)
{                         
    int Sum = 0, Left, Right;
    if(T)
    {
        if((!T->Left) && (!T->Right))
        {
            Sum++;
        }
        Left = SumLeaf(T->Left);  //count the left leaves
        Sum += Left;
        Right = SumLeaf(T->Right);  //count the right leaves
        Sum += Right;
    }
    return Sum;
} 


int Depth(Tree T)  
{
    int depth = 0, DepthLeft, DepthRight;
    if(!T)
    {
        depth = 0;
    }
    else
    {
        DepthLeft = Depth(T->Left); //conut the left depth 
        DepthRight = Depth(T->Right); //count the right depth
        depth = 1 + (DepthLeft > DepthRight ? DepthLeft : DepthRight); //choose the maximum
    }
    return depth;
}

int HasChild(Tree T)
{   //exam whether it has child
    if(T != NULL)
    {
        return true;
    }
    return false;
}


ElemType Get(Tree T)
{
    return T->elem; //get the value of the node 
}
 
void Set(ElemType X, Tree T)
{
    T->elem = X; //set the value of the node 
} 

Queue CreateQueue(int MAXSIZE)
{
    Queue Q;
    Q = malloc(sizeof(struct QueueRecord));
    Q->elem = (Tree *)malloc(sizeof(struct TreeNode)*MAXSIZE);
    Q->Capacity = MAXSIZE;
    Q->Size = 0;
    Q->front = 0;
    Q->rear = 0;
    return Q;
}


int IsEmptyQueue(Queue Q)
{
    return Q->Size == 0;
}


int IsFullQueue(Queue Q)
{
    return Q->Size == Q->Capacity;
}


void EnQueue(Tree T, Queue Q)
{
    
    if(IsFullQueue(Q))
    {
        Error("Full Queue!");
    }
    else
    {
        Q->Size++; //increase the size of the queue if element is enqueued
        Q->elem[Q->rear] = T; //assign the last value to the rear
        Q->rear = (Q->rear+1)% Q->Capacity; //change the location of the rear
    }
}


Tree DeQueue(Queue Q)
{
    Tree tmp;
    if(IsEmptyQueue(Q))
    {
        Error("Empty Queue!");
    }
    else
    {
        printf("%c\t", Q->elem[Q->front]->elem);
        tmp = Q->elem[Q->front];
        Q->Size--; //decrease the size if element is dequeued
        Q->front = (Q->front+1)%Q->Capacity; //withdraw the front
    }
    return tmp;
}


void Error(char s[])
{
    printf("%s\n", s);
}


void BreadthFirst(Tree T,Queue Q)
{
    Tree tmp;
    EnQueue(T,Q);
    while(!IsEmptyQueue(Q))
    {
        tmp = DeQueue(Q);
        if(HasChild(tmp->Left))
        {   //has left child, enqueue
            EnQueue(tmp->Left, Q);
        }
        if(HasChild(tmp->Right))
        {  //has right child, enqueue
            EnQueue(tmp->Right, Q);
        }
    }
    printf("\n");
}


Stack CreateStack(int MaxSize)
{
    Stack S;
    S = malloc(sizeof(struct StackRecord));
    S->elem = (Tree *)malloc(sizeof(struct TreeNode)*MaxSize);
    S->Capacity = MaxSize;
    S->TopofStack = EMPTY;
    return S;
}



//Is empty
int IsEmptyStack(Stack S)
{
    return S->TopofStack == EMPTY; 
} 

//Is full
int IsFullStack(Stack S)
{
    return S->Capacity == S->TopofStack;;
}

//get the elem in top
Tree Top(Stack S)
{
    if(!IsEmptyStack(S))
    {
        return S->elem[S->TopofStack];
    }
    exit(0);
}

//pop the elem out stack
int Pop(Stack S)
{
    if(!IsEmptyStack(S))
    {
        S->TopofStack--;
        return 1;
    }
    exit(0);
}

//push the elem into stack
int Push(Tree T, Stack S)
{
    if(!IsFullStack(S))
    {
        S->TopofStack++;
        S->elem[S->TopofStack] = T;
        return 1;
    }
    exit(0);
}

void NonRePreOrder(Tree T, Stack S)
{
    Tree Tmp = T;
	while(Tmp || !IsEmptyStack(S))
	{
		while(Tmp)
		{
			printf("%c\t", Tmp->elem);
			Push(Tmp, S); //push the root into stack
			Tmp = Tmp->Left;
		}
		if(!IsEmptyStack(S))
		{
			Tmp = Top(S); //get the top elem
			Tmp = Tmp->Right; //go right
			Pop(S); //pop out the top elem
		}
	}

}

void NonReInOrder(Tree T, Stack S)
{
    Tree Tmp = T;
	while(Tmp || !IsEmptyStack(S))
	{
		while(Tmp)
		{                                                                                                                      
			Push(Tmp, S); 
			Tmp = Tmp->Left; //go left
		}
		if(!IsEmptyStack(S))
		{
			Tmp = Top(S);
			printf("%c\t", Tmp->elem);
            Pop(S);
			Tmp = Tmp->Right;
		}
	}
}

void NonRePostOrder(Tree T, Stack S)
{
    Tree Tmp = T, PreChild = NULL;
    Push(Tmp, S);
    while(!IsEmptyStack(S))
    {
        Tmp = Top(S);
        if((!Tmp->Left && !Tmp->Right) || (Tmp->Left == PreChild || Tmp->Right == PreChild))
        {   //if no child or either of its children ever been visited
            printf("%c\t", Tmp->elem);
            Pop(S);
            PreChild = Tmp;
        }
        else
        { 
            if(Tmp->Right)
            {
                Push(Tmp->Right, S); //push into stack
            }
            if(Tmp->Left)
            {
                Push(Tmp->Left, S);
            }
        }       
    }
}
