#include <stdio.h>
#include <string.h>


int solve(int N, int S, int p, int* ti);
void printArray(int* arr, int N);
int min(int a, int b);

void main(void)
{
	int i, T;
	char temp;
	scanf("%d\n", &T);
	for(i = 0; i < T; i++)
	{
		int N, S, p;
		int ti[100];
		int j;
		scanf("%d %d %d", &N, &S, &p);
		for(j = 0; j < N; j++)
		{
			scanf(" %d", &ti[j]);
		}
		scanf("\n",&temp);
		printf("Case #%d: %d\n", (i+1), solve(N,S,p,ti));
	}
}

int solve(int N, int S, int p, int* ti)
{
	int k;
	int solvable_without_surprise = 0;
	int solvable_with_surprise = 0;
	if(p == 0)
	{
		return N;
	}
	else if(p == 1)
	{
		for(k = 0; k < N; k++)
		{
			if(ti[k] > 0) solvable_without_surprise++;
		}
	}
	else
	{
		for(k = 0; k < N; k++)
		{
			if(ti[k] >= (3*p - 2))
			{
				solvable_without_surprise++;
			}
			else if(ti[k] >= (3*p - 4))
			{
				solvable_with_surprise++;
			}
		}
	}
	return solvable_without_surprise + min(solvable_with_surprise, S);
}

int min(int a, int b)
{
	if(a > b) return b;
	return a;
}

void printArray(int* arr, int N)
{
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
}
