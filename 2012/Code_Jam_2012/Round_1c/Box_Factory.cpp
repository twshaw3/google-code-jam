#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int A[100];
int B[100];
uint64_t a[100];
uint64_t b[100];

int solve(int i, int j);

int main(void)
{
	int TC;
	cin >> TC;
	for(int tc = 0; tc < TC; tc++)
	{
		int N, M;
		cin >> N >> M;
		for(int i = 0; i < 2*N; i++) cin >> a[i] >> A[i];
		for(int i = 0; i < 2*N; i++) cin >> b[i] >> B[i];
		
			

		cout << "Case #" << (tc + 1) << ": " << y << endl;
	}
	return 0;
}
