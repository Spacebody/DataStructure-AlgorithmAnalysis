/*
 * Brute Force
 * KMP
 * Horspool
 * Boyer-Moore
 * Sunday
 * RK
 */


#include <stdio.h>
#include <string.h>

int BF(char A[],char B[]);//Brute Force
int KMP(char A[], char B[],int next[]);//KMP
void FindK(char B[], int next[]); //find the max value of k
int Horspool(char A[], char B[]);//Horspool
int BM(char A[],char B[]);//Boyer-Moore
int Sunday(char A[],char B[]);//Sunday
int RK(char A[],char B[]);//RK

int main(void)
{
	// char string[]="abcdefghijklmnopqrstuvwxyz";
	// char match[]="uvwx";
	char string[]="ababababababb";
	char match[]="abababb";
	// char string[] = "abcdefg";
	// char match[]="def";
	int next[strlen(match)];
	FindK(match,next);
	printf("Match the string successfully. The position is %d.\n", BF(string, match)+1);
	printf("Match the string successfully. The position is %d.\n", KMP(string, match, next)+1);
	return 0;
}

int BF(char A[],char B[])
{
	int i,j;
	for(i = 0; i < (int)strlen(A)-(int)strlen(B); i++)
	{
		if(A[i] == B[0])
		{
			if(i == (int)strlen(A))
			{
				return i;
			}
			for(j = 1; j < (int)strlen(B); j++)
			{
				if(A[i+j] != B[j])
				{
					break;
				}
			}
			if(j == (int)strlen(B))
			{
				break;
			}
		}
	}
	return i;
}

int KMP(char A[], char B[],int next[])
{
	int i = 0,j = 0;
	while((i<(int)strlen(A)) && (j<(int)strlen(B)))
	{
		if( j == -1 || A[i] == B[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if(j >= (int)strlen(B))
	{
		return i-(int)strlen(B);
	}
	else
	{
		return -1;
	}	
}

void FindK(char B[], int next[])
{
    next[0] = -1;
    int k = -1,j = 0;
    while(j<(int)strlen(B))
    {
        while(k >= 0 && B[k]!= B[j])
        {
            k=next[k];
        }
       	j++;
        k++;
        next[j]=k;
    }
    //print out the value of next[]
    for(int i=0;i<j;i++)
    {
        printf("%d\t",next[i]);
    }
    printf("\n");
}


