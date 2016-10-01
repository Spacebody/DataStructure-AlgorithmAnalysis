//
//  TestofMaxSubSequence.c
//  Test of three algorithm in max subsequence
//
//  Created by Spacebody on 16/9/30.
//  Copyright © 2016年 Spacebody. All rights reserved.
//

#include <stdio.h>
#include <time.h> //use the header

//Declaration of functions.
int MaxSubSequence1(const int A[], int N);
int MaxSubSequence2(const int A[], int N);
int MaxSubSequence3(const int A[], int N);


int main(void)
{
    const int A[]={-2, 11, -4, 13, -5, 2, -5, -3, 12, -9};
    const int B[]={-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9};
    const int C[]={-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9,-2, 11, -4, 13, -5, 2, -5, -3, 12, -9};
   	int N=10,P=100,Q=1000; //the length
    clock_t start1, finish1, start2, finish2, start3, finish3,
    start4, finish4, start5,finish5, start6, finish6,
    start7, finish7, start8,finish8, start9, finish9;
    //test of O(N^3)
    start1 = clock();
    int maxSum1 = MaxSubSequence1(A,N);
    finish1 = clock();
    start2 = clock();
    int maxSum2 = MaxSubSequence1(B,P);
    finish2 = clock();
    start3 = clock();
    int maxSum3 = MaxSubSequence1(C,Q);
    finish3 = clock();
    
    //test of O(N^2)
    start4 = clock();
    int maxSum4 = MaxSubSequence2(A,N);
    finish4 = clock();
    start5 = clock();
    int maxSum5 = MaxSubSequence2(B,P);
    finish5 = clock();
    start6 = clock();
    int maxSum6 = MaxSubSequence2(C,Q);
    finish6 = clock();
    
    //test of O(N)
    start7 = clock();
    int maxSum7 = MaxSubSequence3(A,N);
    finish7 = clock();
    start8 = clock();
    int maxSum8 = MaxSubSequence3(B,P);
    finish8 = clock();
    start9 = clock();
    int maxSum9 = MaxSubSequence3(C,Q);
    finish9 = clock();
    
    printf("%13d\t%10d\t%10d\n%13d\t%10d\t%10d\n%13d\t%10d\t%10d\n",maxSum1,maxSum2,maxSum3,
           maxSum4,maxSum5,maxSum6,maxSum7,maxSum8,maxSum9);
    double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
    double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
    double duration3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;
    double duration4 = (double)(finish4 - start4) / CLOCKS_PER_SEC;
    double duration5 = (double)(finish5 - start5) / CLOCKS_PER_SEC;
    double duration6 = (double)(finish6 - start6) / CLOCKS_PER_SEC;
    double duration7 = (double)(finish7 - start7) / CLOCKS_PER_SEC;
    double duration8 = (double)(finish8 - start8) / CLOCKS_PER_SEC;
    double duration9 = (double)(finish9 - start9) / CLOCKS_PER_SEC;
    printf( "O(N^3): %f s\t%f s\t%f s\nO(N^2): %f s\t%f s\t%f "
           "s\nO(N):   %f s\t%f s\t%f s\n",duration1, duration2,
           duration3, duration4, duration5, duration6, duration7, duration8, duration9);
    return 0;
    
}

// O(N^3)
int MaxSubSequence1(const int A[], int N){
    int ThisSum,MaxSum,i,j,k;
    MaxSum = 0;
    for(i=0;i<N;i++)
    {
        for(j=i;j<N;j++)
        {
            ThisSum = 0;
            for(k=i;k<=j;k++)
            {
                ThisSum += A[k];
            }
            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

//O(N^2)
int MaxSubSequence2(const int A[], int N){
    int ThisSum,MaxSum,i,j;
    MaxSum = 0;
    for(i=0;i<N;i++)
    {
        ThisSum = 0;
        for(j=i;j<N;j++)
        {
            ThisSum += A[j];
            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

//O(N)
int MaxSubSequence3(const int A[], int N)
{
    int ThisSum,MaxSum,j;
    ThisSum = MaxSum =0;
    for(j = 0;j < N;j++)
    {
        ThisSum += A[j];
        
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}
