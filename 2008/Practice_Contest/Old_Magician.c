#include <stdio.h>
#include <math.h>

char* solve(int W, int B);

void main(void)
{
	int i, T;
	scanf("%d\n", &T);
	for(i = 0; i < T; i++)
	{
		int W, B;
		scanf("%d %d\n", &W, &B);
		printf("Case #%d: %s\n", (i+1), solve(W,B));
	}
}

char* solve(int W, int B)
{
	if(B % 2 == 0) return "WHITE";
	else return "BLACK";
}
