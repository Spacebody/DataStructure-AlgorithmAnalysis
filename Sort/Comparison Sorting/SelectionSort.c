//
//Selection sort
//
//Test array 49, 38, 65, 97, 76, 13, 27, 49
//
//By Spacebody
//

#include <stdio.h>

typedef int ElemType;

void SelectionSort(ElemType A[], int N); //selection sort
void Swap(ElemType *Former, ElemType *Latter);
void Print(ElemType A[], int N);

int main(void)
{
	ElemType array[] = {49, 38, 65, 97, 76, 13, 27, 49};
	int N = sizeof(array)/sizeof(array[0]);
	SelectionSort(array, N);
	Print(array, N);
	return 0;
}

void SelectionSort(ElemType A[], int N)
{
	int i, j, MaxIndex;
	for(i = N-1; i >= 0; i--)
	{  //decrease the search range
		MaxIndex = 0; //initialize the index 
		for(j = 1; j <= i; j++)
		{
			if(A[MaxIndex] < A[j])
			{
				MaxIndex = j; //find the index of the  max element in the subarray 
			}
		}
		Swap(&A[MaxIndex], &A[i]); //swap the positions
	}
}

void Swap(ElemType *Former, ElemType *Latter)
{
	ElemType Tmp;

	Tmp = *Former;
	*Former = *Latter;
	*Latter = Tmp;
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