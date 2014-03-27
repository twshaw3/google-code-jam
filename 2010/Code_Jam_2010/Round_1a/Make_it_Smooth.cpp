#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>

#define ABS(x)    ((x) >= 0 ? (x) : -1*(x))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

int ai[100];
int mem[100][256];
int D, I, M, N;

int solve(int n, int final_value);


int main(void)
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> D >> I >> M >> N;
		for(int j = 0; j < N; j++)
		{
			cin >> ai[j];
			for(int k = 0; k < 256; k++)
				mem[j][k] = -1;
		}
		int opt = INT_MAX;
		for(int val = 0; val < 256; val++)
		{
			int current = solve(N - 1, val);
			if(current < opt) opt = current;
		}
		cout << "Case #" << (i + 1) << ": " << opt << endl;
	}
	return 0;
}


int solve(int n, int final_value)
{
	if(n == 0) return 0;
	if(mem[n][final_value] != -1) return mem[n][final_value];
	int best;
	//Try deleting the final element
	best = solve(n - 1, final_value) + D;
	//Try keeping the final element
	if(M > 0)
	{
		for(int prev_value = 0; prev_value < 256; prev_value++)
		{
			//Penalty for changing final_value
			int move_cost = ABS(final_value - ai[n]);
			//solution to sub-problem assuming that final pixel stays at prev_value
			int prev_cost = solve(n - 1, prev_value);
			//Penalty for insertions
			int insert_cost = final_value == prev_value ? 0 : I*(ABS(final_value - prev_value) - 1)/M;
			//Best is the minimum of the deletion cost and the retention cost for this iteration
			best = MIN(best, prev_cost + move_cost + insert_cost);
		}
	}
	else
	{
		int move_cost = ABS(final_value - ai[n]);
		int prev_cost = solve(n - 1, final_value);
		best = MIN(best, move_cost + prev_cost);
	}
	mem[n][final_value] = best;
	return best;
}
