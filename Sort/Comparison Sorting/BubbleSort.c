//
//Bubble sort
//
//Test array 49, 38, 65, 97, 76, 13, 27, 49
//
//
//By Spacebody
//


#include <stdio.h>

typedef int ElemType;

void BubbleSort(ElemType A[], int N); //bubble sort
void Print(ElemType A[], int N);

int main(void)
{
	ElemType array[] = {49, 38, 65, 97, 76, 13, 27, 49};
	int N = sizeof(array)/sizeof(array[0]);
	BubbleSort(array, N);
	Print(array, N);
	return 0;
}

void BubbleSort(ElemType A[], int N)
{
	int i, j;
	ElemType Tmp;

	for(j = N; j > 0; j--)   
	{   //for every traversal, decrease the count
		for(i = 0; i < j; i++)
		{
			if(A[i] > A[i + 1])
			{   //swap if former is bigger than latter
				Tmp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = Tmp;
			}	
		}
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