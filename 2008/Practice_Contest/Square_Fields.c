#include <stdio.h>
#include <math.h>

int solve(int n, int k, int pts[][2]);
int fact(int n);
void permute(int arr[][2], int p);

void main(void)
{
	int i, T;
	scanf("%d\n", &T);
	for(i = 0; i < T; i++)
	{
		int n, k, j;
		int pts[15][2];
		scanf("%d %d\n", &n, &k);
		for(j = 0; j < n; j++)
		{
			scanf("%d %d\n", &pts[j][0], &pts[j][1]);
		}
		printf("Case #%d: %s\n", (i+1), solve(n,k,pts));
	}
}

int solve(int n, int k, int pts[][2])
{
	int m;
	int lim = fact(n);
	for(m = 0; m < lim; m++)
	{
		permute(pts, m);

	}
	return 0;
}

int fact(int n)
{
	if(n <= 1) return 1;
	else return n * fact(n - 1);
}

void permute(int arr[][2], int p)
{
	
}
