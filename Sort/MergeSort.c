//
//Merge sort
//
//Test array 24, 13, 26, 1, 2, 27, 38
//
//By Spacebody
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

void MSort(ElemType A[], ElemType TmpArray[], int Left, int Right);
void MergeSort(ElemType A[], int N); //merge sort 
void Merge(ElemType A[], ElemType TmpArray[], int Lops, int Rops, int RightEnd);
void Print(ElemType A[], int N);

int main(void)
{
	ElemType array[] = {24, 13, 26, 1, 2, 27, 38};
	int N = sizeof(array)/sizeof(array[0]);
	MergeSort(array, N);
	Print(array, N);
	return 0;
}

void MSort(ElemType A[], ElemType TmpArray[], int Left, int Right)
{
	int Center;

	if(Left < Right)
	{
		Center = (Left + Right)/2; //get the middle index
		MSort(A, TmpArray, Left, Center); //recurison for left part
		MSort(A, TmpArray, Center + 1, Right); //recursion for right part
		Merge(A, TmpArray, Left, Center + 1, Right); //merge to sort
	}
}

void MergeSort(ElemType A[], int N)
{
	ElemType *TmpArray;
	TmpArray = (ElemType *)malloc(sizeof(ElemType)*N); //new array to store the result
	
	if(TmpArray != NULL)
	{
		MSort(A, TmpArray, 0, N-1); //merge from both side 
		free(TmpArray); //free the memory
	}
	else
	{
		printf("Out of Space!\n");
		exit(0);
	}
}

void Merge(ElemType A[], ElemType TmpArray[], int LeftPos, int RightPos, int RightEnd)
{
	int i, LeftEnd, NumElem, TmpPos;

	LeftEnd = RightPos - 1;
	TmpPos = LeftPos;
	NumElem = RightEnd - LeftPos + 1; //number of elements

	while(LeftPos <= LeftEnd && RightPos <= RightEnd)
	{
		if(A[LeftPos] <= A[RightPos])
		{
			TmpArray[TmpPos++] = A[LeftPos++]; //if elemnent from left part is large, then put it into new array
		}
		else
		{
			TmpArray[TmpPos++] = A[RightPos++]; //otherwise put the element from right into new array
		}
	}
	while(LeftPos <= LeftEnd)
	{  //copy the rest int the first half
		TmpArray[TmpPos++] = A[LeftPos++];
	}
	while(RightPos <= RightEnd)
	{  //copy the rest part in the second half
		TmpArray[TmpPos++] = A[RightPos++];
	}

	for(i = 0; i < NumElem; i++, RightEnd--)
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
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
