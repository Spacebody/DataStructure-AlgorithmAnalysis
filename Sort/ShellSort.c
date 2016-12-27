//
//Shell sort
//
//Test array 81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15
//Use the increment [N/2]
//
//By Spacebody
//

#include <stdio.h>

typedef int ElemType;

void ShellSort(int A[], int N);  //shell sort
void Print(int A[], int N);

int main(void)
{
	ElemType array[]= {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
	int N = sizeof(array)/sizeof(array[0]);
	ShellSort(array, N);
	Print(array, N);
}

void ShellSort(int A[], int N)
{
	int i, j, increment;
	ElemType Tmp;
	for(increment = N/2; increment > 0; increment /= 2)
	{
		for( i = increment; i < N; i++)
		{  //for every increment, keep hk-sort
			Tmp = A[i];
			for( j = i; j >= increment; j-= increment)
			{
				if(Tmp < A[j - increment])
				{
					A[j] = A[j - increment]; //exchage the position
				}
				else
				{
					break;
				}
			}
			A[j] = Tmp;
		}
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
