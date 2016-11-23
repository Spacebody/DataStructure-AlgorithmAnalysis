//
//Binary tree to recover the tree (A(B(E(K,L),F),C(G),D(H(M),I,J)))
//Call the functions in recursion/non-recursion
//Traverse the tree in depth first(preorder/inorder/postorder)
//Traverse the tree in breath first
//
//Enter "ABDH##I##EJ###CFL###G###" to test
//By Spacebody
//
//



#ifndef _BinaryTree_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode *Tree;
typedef struct QueueRecord *Queue;
typedef struct StackRecord *Stack;
typedef char ElemType;
#define MAX 10
#define EMPTY -1
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

//functions of tree
Tree CreateTree(Tree T); //create the tree
int SumLeaf(Tree T); //count the sum of leaves
int Depth(Tree T); //count the depth of the binary tree
ElemType Get(Tree T); //get the element
void Set(Tree T); //set the element
int HasChild(Tree T); //exam wether the node has child


//recursion alogrithm
/*  depth first traversal  */
void PreOrder(Tree T); //traversal in preorder
void InOrder(Tree T); //traversal in inorder
void PostOrder(Tree T); //traversal in postorder

/*breath first traversal */
void BreadthFirst(Tree T,Queue Q);//breath first traversal

//functions of queue
Queue CreateQueue(int MAXSIZE);
void EnQueue(Tree T, Queue Q);
Tree DeQueue(Queue Q);
int IsEmptyQueue(Queue Q);
int IsFullQueue(Queue Q);
void PrintQueue(Queue Q);
void Error(char s[]);

//non-recursion algorithm


//functions of stack
int IsEmptyStack(Stack S); //Is empty
int IsFullStack(Stack S);  //Is full
Stack CreateStack(int MaxSize); //create a stack
ElemType Top(Stack S);  //get the elem in top
int Pop(Stack S);  //pop the elem out stack
int Push(Tree T, Stack S); //push the elem into stack
void PrintStack(Stack S); //print elements in the stack


int main(void)
{

    Tree T;
    Queue Q;
    T = CreateTree(T);
    Q = CreateQueue(MAX);
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");
    printf("%d\n", SumLeaf(T));
    printf("%d\n", Depth(T));
    BreadthFirst(T,Q);
    return 0;

}


Tree CreateTree(Tree T)
{
    ElemType elem;
    elem = getchar(); //get the string "ABEK#L##F##CG##DHM##I#J####"
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
        printf("%c\t",T->elem);
        PreOrder(T->Left); //Call the function in recursion
        PreOrder(T->Right);
    }
}

void InOrder(Tree T)
{    
    if(T)
    {
        InOrder(T->Left); //Call the function in recursion
        printf("%c\t",T->elem);
        InOrder(T->Right);
    }
}

void PostOrder(Tree T)
{   
    if(T)
    { 
        PostOrder(T->Left); //Call the function in recursion
        PostOrder(T->Right);
        printf("%c\t",T->elem);
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
{
    if(T != NULL)
    {
        return true;
    }
    return false;
}


// ElemType Get(Tree T)
// {
  

// } 
// void Set(Tree T); 

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
        printf("%c", Q->elem[Q->front]->elem);
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



void PrintQueue(Queue Q)
{
    if(IsEmptyQueue(Q))
    {
        Error("Empty Queue!");
    }
    else
    {
        int i;
        for(i = 0; i< Q->Size; i++)
        {
            printf("%c\n", Q->elem[i]->elem);
        }
    }
}

void BreadthFirst(Tree T,Queue Q)
{
    Tree tmp;
    EnQueue(T,Q);
    while(!IsEmptyQueue(Q))
    {
        tmp = DeQueue(Q);
        if(HasChild(tmp->Left))
        {
            EnQueue(tmp->Left, Q);
        }
        if(HasChild(tmp->Right))
        {
            EnQueue(tmp->Right, Q);
        }
        printf("\n");
    }
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
ElemType Top(Stack S)
{
    if(!IsEmptyStack(S))
    {
        return S->elem[S->TopofStack]->elem;
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

//print elements in the stack
void PrintStack(Stack S)
{
    if(IsEmptyStack(S))
    {
        printf("Empty Stack!\n");
    }
    else
    {
        int i;
        for(i = S->TopofStack; i >= 0;i--)
        {
            printf("%c\n", S->elem[i]->elem);
        }
    }
}


