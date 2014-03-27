#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int N;
		int ht[1001];
		cin >> N;
		for(int j = 0; j < N; j++)
			cin >> ht[j];
		ht[N] = 2000;
		int opt[1001];
		opt[0] = 0;
		for(int j = 1; j <= N; j++)
			opt[j] = j;
		int l;
		for(l = 1; l <= N; l++)
		{
			for(int k = 0; k < l; k++)
			{
				if((ht[l] > ht[k]) && (opt[k] + (l - k - 1) < opt[l])) opt[l] = opt[k] + (l - k - 1);
			}
		}
		cout << "Case #" << (i + 1) << ": " << opt[N] << "\n";
	}
	return 0;
}
