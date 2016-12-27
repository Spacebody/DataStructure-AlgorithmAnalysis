//
//Heap sort
//
//Use heap
//
//Test array 97, 53, 59, 26, 41, 58, 31
//
//By Spacebody
// 

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

#define LeftChild(i) (2 * (i) + 1)

void HeapSort(ElemType A[], int N); //heap sort
void Swap(ElemType *Large, ElemType *Small); //delete max
void PercDown(ElemType A[], int i, int N); //build heap
void Print(ElemType A[], int N); 

int main(void)
{
	ElemType array[] = {97, 53, 59, 26, 41, 58, 31};
	int N = sizeof(array)/sizeof(array[0]);
	HeapSort(array, N);
	Print(array, N);
	return 0;
}

void PercDown(ElemType A[], int i, int N)
{
	int Child;
	ElemType Tmp;

	for(Tmp = A[i]; LeftChild(i) < N; i = Child)
	{
		Child = LeftChild(i);
		if(Child != N-1 && A[Child + 1] > A[Child])
		{
			Child++; 
		}
		if(Tmp < A[Child])
		{
			A[i] = A[Child];
		}
		else
		{
			break;
		}
	}
	A[i] = Tmp;
}

void HeapSort(ElemType A[], int N)
{
	int i;
	for(i = N/2; i >= 0; i--)
	{
		PercDown(A, i, N); //build heap
	}
	for(i = N-1; i > 0; i--)
	{
		Swap(&A[0], &A[i]); //delete max
		PercDown(A, 0, i);
	}
}

void Swap(ElemType *Large, ElemType *Small)
{
	ElemType Tmp;
	Tmp = *Small;
	*Small = *Large;
	*Large = Tmp;
}

void Print(ElemType A[], int N)
{
	int i; 
	for(i = 0; i < N; i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n");
}

