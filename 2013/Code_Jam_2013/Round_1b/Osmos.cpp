#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int compute(int n); 

long int M[100];
int N;
long int A;

int main(void)
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int y;
		cin >> A >> N;
		for(int j = 0; j < N; j++)
		{
			cin >> M[j];
		}
		sort(M, M + N);
		y = N;
		if(A != 1)
		{
			for(int k = N; k >= 0; k--)
			{
				int penalty = k + compute(N - k);
				if(penalty < y) y = penalty;
			}
		}

		cout << "Case #" << (i + 1) << ": " << y << endl;
	}
	return 0;
}

int compute(int n)
{
	if(n == 0) return 0;
	int ops;
	long int size;
	size = A;
	ops = 0;
	for(int i = 0; i < n; i++)
	{
		while(size <= M[i])
		{
			size *= 2;
			size -= 1;
			ops++;
		}
		size += M[i];
	}
	return ops;
}

