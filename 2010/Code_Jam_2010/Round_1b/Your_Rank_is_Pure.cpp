#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

uint64_t cache[500][500];

uint64_t solve(uint64_t i, uint64_t j);
uint64_t compute(uint64_t n);
uint64_t choose(uint64_t n, uint64_t m);

int main(void)
{
	int TC;
	cin >> TC;
	for(int i = 0; i < 500; i++)
		for(int j = 0; j < 500; j++)
			cache[i][j] = 0;
	cache[2][1] = 1;
	for(int tc = 0; tc < TC; tc++)
	{
		uint64_t n;
		cin >> n;
		uint64_t y = compute(n);
		cout << "Case #" << (tc + 1) << ": " << y << endl;
	}
	return 0;
}

uint64_t solve(uint64_t i, uint64_t j)
{
	//i is the pure number, j is its rank
	//return value is the number of ways i can have rank j
	if(cache[i][j] != 0) return cache[i][j];
	uint64_t res = 0;
	if(j == 1) res = 1;
	else
	{
		for(int k = 1; k < j; k++)
		{
			res += solve(j, k)*choose(i - j - 1, j - k - 1);
		}
	}
	cache[i][j] = res;
	return res;
}

uint64_t compute(uint64_t n)
{
	uint64_t res = 0;
	for(uint64_t j = 1; j < n; j++)
		res += solve(n, j);
	return (res % 100003);
}

uint64_t choose(uint64_t n, uint64_t m)
{
	uint64_t numer, denom;
	if(m > n) return 0;
	if(n == 0) return 1;
	if(m == 0) return 1;
	numer = 1;
	denom = 1;
	if(m > n/2)
	{
		for(uint64_t i = m + 1; i <= n; i++)
			numer *= i;
		for(uint64_t i = 1; i <= n-m; i++)
			denom *= i;
	}
	else
	{
		for(uint64_t i = (n-m) + 1; i <= n; i++)
			numer *= i;
		for(uint64_t i = 1; i <= m; i++)
			denom *= i;
	}
	return numer/denom;
}


