/*
 *Priority queue
 *Use array to implement priority queue
 *
 *for every element with index i,
 *its left child is the element with index 2*i, 
 *its right child is the elem with index 2*i+1.
 *
 * By Spacebody
 */

#ifndef _PriorityQueue_h

#include <stdio.h>
#include <stdlib.h>
typedef struct QueueRecord *PriQueue;
typedef int ElemType;
#define MAX 20
#define MINDATA -100000

//functions of priority queue
PriQueue Initialize(int MaxSize); //initialize the heap
void Destory(PriQueue H); //destory heap
void MakeEmpty(PriQueue H);  //empty the queue
void Insert(ElemType X, PriQueue H); //insert the elements
ElemType DeleteMin(PriQueue H); //delete the minma in the heap
ElemType FindMin(PriQueue H); //fine the minma in the heap
void Delete(PriQueue H, int i); //delete the elements with the index i
PriQueue BuildHeap(PriQueue H, int data[], int length); //build heap 
void PercolateDown(int p, PriQueue H); //percolate down 
void PercolateUp(int p, PriQueue H); //perlocate up 
void DecreaseKey(int i, ElemType delta, PriQueue H); //decrease key by delta
void IncreaseKey(int i, ElemType delta, PriQueue H); //increase key by delta 
int IsEmpty(PriQueue H);  //exam whether it is empty
int IsFull(PriQueue H);  //exam whether it is full
void Print(PriQueue H);  //print out the elements
void Error(char s[]);  //print out the error messages

#endif /* PriorityQueue.h */

struct QueueRecord
{
    int Size;
    int Capacity;
    ElemType *elem;
}; 


//Driving function
int main(void)
{
	int data[] = {13, 14, 19, 22, 65, 26, 32, 31, 68, 20};
	int length = sizeof(data)/sizeof(data[0]);
	PriQueue H;
	H = BuildHeap(H, data, length);
	Print(H);
	printf("%d\n",FindMin(H));
	printf("%d\n",DeleteMin(H));
	Print(H);
	DecreaseKey(3, 16, H);
	Print(H);
	IncreaseKey(1, 16, H);
	Print(H);
	Delete(H, 3);
	Print(H);
	Destory(H);
	Print(H); //since H is been deleted, than it will print out nothing
	return 0;
}


PriQueue Initialize(int MaxSize)
{
    PriQueue H;

    H = (PriQueue)malloc(sizeof(struct QueueRecord));
    if(H == NULL)
    {
    	Error("Out of Space!");
    }
    H->elem = (ElemType *)malloc(sizeof(ElemType) * (MaxSize + 1) ); //the element with index 0 should be included
    H->Capacity = MaxSize; 
    MakeEmpty(H);  //make the heap empty
    H->elem[0] = MINDATA; //assign the minma to first element
    return H;
}

void MakeEmpty(PriQueue H)
{
    H->Size = 0;
}

void Insert(ElemType X, PriQueue H)
{
	int i;
	if(IsFull(H))
	{
		Error("Full Priority queue!");
		exit(0);
	}

	for(i = ++H->Size; H->elem[i/2] > X; i /= 2)
	{
		H->elem[i] = H->elem[i/2]; //change the position if larger than its father
	}
	H->elem[i] = X;//insert the element
}


int IsEmpty(PriQueue H)
{
    return H->Size == 0;
}


int IsFull(PriQueue H)
{
    return H->Size == H->Capacity;
}


void Error(char s[])
{
    printf("%s\n", s);
}

ElemType DeleteMin(PriQueue H)
{
	int i, Child;
	ElemType MinElem, LastElem;

	if(IsEmpty(H))
	{
		Error("Empty Priority queue!");
		exit(0);
	}
	MinElem = H->elem[1]; //the root, which is the element with index 1 is the smallest
	LastElem = H->elem[H->Size--]; //assign the last elem to LastElem and decrease Size by 1

	for(i = 1; i * 2 <= H->Size; i = Child)
	{
		Child = i * 2;
		if(Child != H->Size && H->elem[Child + 1] < H->elem[Child])
		{
			Child++;
		} 
		if( LastElem > H->elem[Child])
		{
			H->elem[i] = H->elem[Child];
		}
		else
		{
			break;
		}
	}
	H->elem[i] = LastElem;
	return MinElem;	
}

ElemType FindMin(PriQueue H)
{
	return H->elem[1]; //return the root, which is the minma
}

void Print(PriQueue H)
{
    if(IsEmpty(H))
    {
        Error("Empty Priority queue!");
    }
    else
    {
        int i;
        for(i = 1; i<= H->Size; i++)
        {
            printf("%d\t", H->elem[i]); //skip the element with index 0
        }
    }
    printf("\n");
}

void Delete(PriQueue H, int i)
{
	DecreaseKey(i,99999,H); //decrease the element which will be deleted to smallest
	DeleteMin(H); //use delete minma to delete the element
}


PriQueue BuildHeap(PriQueue H, int data[], int length)
{
	int i;
	H = Initialize(MAX);
	for(i = 0; i < length;i++)
	{
		Insert(data[i], H); //firstlt insert all elements into the heap
	}
	for(i = length/2; i > 0; i--)
	{
		PercolateDown(i, H); //after that, percolate the larger down
	}
	return H;
}

void PercolateDown(int p, PriQueue H)  
{  
    int Child, i;  
    ElemType tmp = H->elem[p];  
    for(i = p; i * 2 <= H->Size; i = Child)
    {  
        Child = i * 2;  
        if(Child != H->Size && H->elem[Child] > H->elem[Child + 1])
        {  
            Child++;
       	}  
        if(tmp > H->elem[Child])
        {  
        	H->elem[i] = H->elem[Child];
        }  
        else
        {  
            break; 
        } 
    }  
    H->elem[i] = tmp;  
}  

void PercolateUp(int p, PriQueue H)  
{  
    ElemType temp = H->elem[p];  
    while(temp < H->elem[p / 2])
    {  //exchange if necessary
        H->elem[p] = H->elem[p / 2];  
        p /= 2;  
    }  
    H->elem[p] = temp;  
}   

void DecreaseKey(int i, ElemType delta, PriQueue H)
{
	if(i > H->Size || i < 1)
	{
		 Error(" Failed! Overstep the boundary!");
		 exit(0); 
	}
	H->elem[i] -= delta; //substract the delta
	PercolateUp(i, H); //percolate up to keep the heap order
}


void IncreaseKey(int i, ElemType delta, PriQueue H)
{
	if(i > H->Size || i < 1)  
    {  
        Error("Failed! Overstep the boundary!");  
        exit(0);  
    }  
    H->elem[i] += delta; //add the delta
    PercolateDown(i, H); //percolate down to maintain the heap order
}

void Destory(PriQueue H)
{
	free(H); //free H to destroy the heap
}



