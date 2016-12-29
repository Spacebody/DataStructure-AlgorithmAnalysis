//
//Counting sort
//
//Test array 49, 38, 65, 97, 76, 13, 27, 49
//
//By Spacebody
//

#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;


void CountingSort(ElemType A[], int N); //counting sort
int Count(ElemType A[], int N, int i); //count the weight
void Swap(ElemType *Former, ElemType *Latter); //swap two elements
void Print(ElemType A[], int N);

int main(void)
{
	ElemType array[] = {49, 38, 65, 97, 76, 13, 27, 49};
	int N = sizeof(array)/sizeof(array[0]);
	CountingSort(array, N);
	Print(array, N);
	return 0;
}	

void CountingSort(ElemType A[], int N)
{
	int i, j, count = 0;
	ElemType CountRecord[N], TmpArray[N];

	for(i = 0; i < N; i++)
	{
		CountRecord[i] = Count(A, N, i); //get the weight
		while(TmpArray[CountRecord[i]] == A[i])
		{
			CountRecord[i]++; //for the same value, increase the weight
		}	
		TmpArray[CountRecord[i]] = A[i]; //sort the value
	}

	for(i = 0; i < N; i++)
	{
		A[i] = TmpArray[i]; //copy the array to orginal array
	}
}

int Count(ElemType A[], int N, int i)
{
	int j, count = 0;
	for(j = 0; j < N; j++)
	{
		if(i == j)
		{
			continue; //skip itself
		}
		if(A[i] > A[j])
		{
			count++;
		}
	}	
	return count;	
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