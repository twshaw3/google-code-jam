#include <stdio.h>
#include <math.h>


int solve(int A, int B);
int choose_2(int m);
int find_num_digits(int n);
int a[2000000];

void main(void)
{
	int i, T;
	scanf("%d\n", &T);
	for(i = 0; i < T; i++)
	{
		int A, B;
		scanf("%d %d\n", &A, &B);
		printf("Case #%d: %d\n", (i+1), solve(A,B));
	}
}

int solve(int A, int B)
{
	int k, j;
	int num_pairs, num_digits;
	num_pairs = 0;
	num_digits = find_num_digits(A);
	for(k = 0; k < 2000000; k++) a[k] = 0;
	for(k = A; k <= B; k++)
	{
		if(a[k] == 1) continue;
		int temp = 1;
		j = k;
		while(1)
		{
			j = (j/10) + (j%10)*pow(10,num_digits-1);
			if(j == k) break;
			else if((j < A) || (j > B)) continue;
			else if(find_num_digits(j) != num_digits) continue;
			else
			{
				a[j] = 1;
				temp++;
			}
		}
		num_pairs += choose_2(temp);
	}
	return num_pairs;
}

int choose_2(int m)
{
	if(m < 2) return 0;
	return m*(m-1)/2;
}

int find_num_digits(int n)
{
	return (int)log10((double)n) + 1;
}
