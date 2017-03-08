/**
 * By 郑艺林 
 *
 * Quicksort with array 
 */
#include <stdio.h>

//declaration of functions
void swap(int *p, int *q); //swap two elements
void Qsort(int A[], int left, int right); //quick sort
void Print(int A[], int n); //print out

int main(void)
{
	int array[]= {6 ,10, 13, 5, 8, 3, 2, 11};
	int N = (int)sizeof(array)/sizeof(array[0]); //get the size
	Qsort(array, 0, N-1);  //call to sort
	Print(array, N); //print out the result
	
	return 0;
}

void Qsort(int A[], int left, int right)
{
	int i = left,j = 0; //initialize the index
	for(j = left+1; j <= right ; ++j)
	{
		if(A[j] <= A[left])
		{   //increase the index of i, then swap the elements
			++i;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i],&A[left]); //swap the position with the pivot element
	if(left<right)
	{
		Qsort(A, left, i-1); //recursion for left part
		Qsort(A, i+1, right); //recursion for right part
	}
}

void swap(int *p, int *q)
{
	int tmp = *p; 
	*p = *q;
	*q = tmp;
}

void Print(int A[], int n)
{
	int i = 0;
	for(i = 0;i<n; ++i)
	{
		printf("%d\t", A[i]);
	}
	printf("\n");
}
