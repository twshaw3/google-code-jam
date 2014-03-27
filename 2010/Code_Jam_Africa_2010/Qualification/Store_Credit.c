#include <stdio.h>
#include <math.h>

void solve(int* P, int C, int I, int* indices);

void main(void)
{
	int i, T;
	scanf("%d\n", &T);
	for(i = 0; i < T; i++)
	{
		int C,I;
		int k;
		char temp;
		int P[2000];
		int result[2];
		scanf("%d\n%d\n", &C, &I);
		for(k = 0; k < I; k++)
		{
			scanf("%d",&P[k]);
			if(k != (I-1)) scanf(" ", &temp);
		}
		scanf("\n", &temp);
		solve(P,C,I,result);
		printf("Case #%d: %d %d\n", (i+1), result[0], result[1]);
	}
}

void solve(int* P, int C, int I, int* indices)
{
	
	int l, m;
	for(l = 0; l < (I-1); l++)
	{
		for(m = (l + 1); m < I; m++)
		{
			if((P[m] + P[l]) == C)
			{
				indices[0] = (l + 1);
				indices[1] = (m + 1);
				return;
			}
		}
	}
}
