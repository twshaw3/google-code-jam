#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <climits>

using namespace std;

int release[100];
int dp[100][100];

int P, Q;

int solve(int f, int l);

int main(void)
{
	int TC;
	cin >> TC;
	for(int tc = 0; tc < TC; tc++)
	{
		cin >> P >> Q;
		for(int i = 0; i < Q; i++)
			cin >> release[i];
		int y = 0;
		for(int i = 0; i < 100; i++)
			for(int j = 0; j < 100; j++)
				dp[i][j] = -1;
		y = solve(1, Q);
		cout << "Case #" << (tc + 1) << ": " << y << endl;
	}
	return 0;
}

int solve(int i, int j)
{
	if(i > j) return 0;
	if(dp[i - 1][j - 1] != -1) return dp[i - 1][j - 1];
	int min = INT_MAX;
	for(int q = i; q <= j; q++)
	{
		int current;
		int lowerp = i == 1 ? 1 : release[i - 2] + 1;
		int upperp = j == Q ? P : release[j] - 1;
		int p = release[q - 1];
		if(p == 1) current = upperp - lowerp + solve(q + 1, j);
		else if(p == P) current = upperp - lowerp + solve(i, q - 1);
		else current = upperp - lowerp + solve(i, q - 1) + solve(q + 1, j);
		if(current < min) min = current;
	}
	if(min == INT_MAX) min = 0;
	dp[i - 1][j - 1] = min;
	return min;
}
