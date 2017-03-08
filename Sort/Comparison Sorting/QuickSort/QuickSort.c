//
//Quick sort
//
//Test array 8, 1, 4, 9, 0, 3, 5, 2, 7, 6 
//
//By Spacebody
//

#include <stdio.h>

typedef int ElemType;
#define Cutoff 3

void QuickSort(ElemType A[], int N); //driver function
ElemType Media3(ElemType A[], int Left, int Right); //find the media value
void Qsort(ElemType A[], int Left, int Right); 
void Swap(ElemType *Former, ElemType *Latter);
void InsertionSort(ElemType A[], int N);
void Print(int A[], int N);

int main(void)
{
	ElemType array[] = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6};
	int N = sizeof(array)/sizeof(array[0]);
	QuickSort(array, N);
	Print(array, N);
	return 0;
}


void QuickSort(ElemType A[], int N)
{
	Qsort(A, 0, N-1);
}

ElemType Media3(ElemType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;

	if(A[Left] > A[Center])
	{
		Swap(&A[Left], &A[Center]); 
	}
	if(A[Left] > A[Right])
	{
		Swap(&A[Left], &A[Right]); 
	}
	if(A[Center] > A[Right])
	{
		Swap(&A[Center], &A[Right]);
	}

	Swap(&A[Center], &A[Right - 1]); //exchange the position to hide pivot
	return A[Right - 1]; //return pivot
}

void Qsort(ElemType A[], int Left, int Right)
{
	int i, j;
	ElemType Pivot;

	if(Left + Cutoff <= Right)
	{
		Pivot = Media3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for( ; ; )
		{
			while(A[++i] < Pivot);
			while(A[--j] > Pivot);
			if(i < j)
			{
				Swap(&A[i], &A[j]);
			}
			else
			{
				break;
			}
		}

		Swap(&A[i], &A[Right - 1]);  //restore pivot

		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else
	{   //do insertion sort on the subarray
		InsertionSort(A + Left, Right - Left + 1);
	}
}

void Swap(ElemType *Former, ElemType *Latter)
{
	ElemType Tmp;
	Tmp = *Former;
	*Former = *Latter;
	*Latter = Tmp;
}

void InsertionSort(ElemType A[], int N)
{
	int i, j;
	ElemType Tmp;
	for( j = 1 ;j < N;j++)
    {
        Tmp = A[j];
        //find the position
        for(i = j - 1; i >= 0 && A[i] > Tmp; i--)
        {
            A[i+1] = A[i]; //move the other elements
        }
        A[i+1] = Tmp;
    }
}

void Print(int A[], int N)
{
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n");
}