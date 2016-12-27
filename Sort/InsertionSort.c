//
//Insertion sort
//
//Test array: 34, 8, 64, 51, 32, 31
//
//By Spacebody
//

#include <stdio.h>

typedef int ElemType;

void Insertion(ElemType A[], int N); //insertion sort
void Print(int A[], int N);

int main(void)
{
	ElemType array[] = {34, 8, 64, 51, 32, 31};
	int N = sizeof(array)/sizeof(array[0]);
	Insertion(array, N);
	Print(array, N);
}

void Insertion(ElemType A[], int N)
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