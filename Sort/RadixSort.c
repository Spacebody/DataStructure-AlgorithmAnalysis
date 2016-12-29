//
//Radix sort
//
//Test array 49, 38, 65, 97, 76, 13, 27, 49
//
//LSD & MSD
//By Spacebody
//

#include <stdio.h>
#include <math.h>

typedef int ElemType;

int FindTopDigital(ElemType A[], int N); //find the top digital
void LSD_Sort(ElemType A[], int N, int TopDigital); //sort by Least significant digital
void InitNum(int num[], int TopDigital); //initialize the divisors
void InitDigital(int Digital[], int N); //initialize the number of the digital
void CountDigital(int Digital[], int N, int num[], int j, ElemType A[]); //count the number of digital
void CollectDigital(int Digital[], int N); //collect messages in the array of the digital


void MSD_Sort(ElemType A[], int N, int TopDigital); //use recursion
void MSD(int Digital[], int N, int num[], int j, ElemType A[], ElemType TmpArray[]);

void Print(ElemType A[], int N);

int main(void)
{
	ElemType array[] = {49, 38, 65, 97, 76, 13, 27, 49};
	int N = sizeof(array)/sizeof(array[0]);
	int TopDigital;
	TopDigital = FindTopDigital(array, N);
	LSD_Sort(array, N, TopDigital);
	// MSD_Sort(array, N, TopDigital);
	Print(array, N);
	return 0;

}

int FindTopDigital(ElemType A[], int N)
{
	int i;
	ElemType Tmp = A[0];

	for(i = 1; i < N; i++)
	{
		if(Tmp < A[i])
		{
			Tmp = A[i];
		}
	}
	i = 0;
	while(Tmp)
	{
		i++;
		Tmp /= 10;
	}
	return i;
}

void LSD_Sort(ElemType A[], int N, int TopDigital)
{
	ElemType Digital[10], TmpArray[N], num[TopDigital];
	int i, j;
	
	InitNum(num, TopDigital);
	for(j = 0; j < TopDigital; j++)
	{

		InitDigital(Digital, 10);
		CountDigital(Digital, N, num, j, A);
		CollectDigital(Digital, 10);
		for(i = N-1; i >=0; i--)
		{
			TmpArray[Digital[(A[i]%num[j])/(num[j]/10)]-1] = A[i];
			Digital[(A[i]%num[j])/(num[j]/10)]--;
		}
		for(i = 0; i < N; i++)
		{
			A[i] = TmpArray[i]; //copy the array to original array
		}
	}

}


// void MSD_Sort(ElemType A[], int N, int TopDigital)
// {
// 	ElemType Digital[10], TmpArray[N];
// 	int i;
// 	ElemType num[TopDigital];
	
// 	InitNum(num, TopDigital);
// 	// InitDigital(Digital, 10);
// 	// CountDigital(Digital, N, num, TopDigital-1, A);
// 	// Print(Digital, 10);
// 	MSD(Digital, N, num, TopDigital, A, TmpArray);
// 	// for(i = 0; i < N; i++)
// 	// {
// 	// 	if(Digital[i] > 1)
// 	// 	{
		
// 	// 	}
// 	// }
	

// }

// void MSD(int Digital[], int N, int num[], int j, ElemType A[], ElemType TmpArray[])
// {
// 	int i, k;
// 	if(j == 0)
// 	{
// 		return;
// 	}
// 	InitDigital(Digital, 10);
// 	CountDigital(Digital, N, num, j-1, A);
// 	printf("After counting:\n");
// 	Print(Digital, 10);
// 	for(i = 0; i < 10 ; i++)
// 	{
// 		for( ; Digital[i] > 1; Digital[i]-- )
// 		{
// 			for(k = 0; k < N; k++)
// 			{
// 				if((A[k]%num[j-1])/(num[j-1]/10) == i)
// 				{
// 					MSD(Digital, N, num, j-1, A, TmpArray);
// 				}
// 			}
// 		}
// 	} 
// 	printf("After dividing:\n");
// 	Print(Digital, 10);

// }

void InitNum(int num[], int TopDigital)
{
	int i;
	for(i = 0; i < TopDigital; i++)
	{
		num[i] = (ElemType)pow(10,i+1);
	}
}


void InitDigital(int Digital[], int N)
{
	int i;

	for(i = 0; i < N; i++)
	{
		Digital[i] = 0;
	}
}

void CountDigital(int Digital[], int N, int num[], int j, ElemType A[])
{
	int i;

	for(i = 0; i < N; i++)
	{
		Digital[(A[i]%num[j])/(num[j]/10)]++;
	}
}

void CollectDigital(int Digital[], int N)
{
	int i;
	for(i = 1; i < N; i++)
	{
		Digital[i] = Digital[i-1] + Digital[i];
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