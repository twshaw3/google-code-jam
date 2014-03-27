#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int N;
		int xs = 0;
		cin >> N;
		int Ai[1000];
		int Bi[1000];
		for(int j = 0; j < N; j++)
		{
			cin >> Ai[j] >> Bi[j];
		}
		for(int k = 0; k < (N - 1); k++)
		{
			for(int l = (k + 1); l < N; l++)
			{
				if((Ai[k] > Ai[l]) && (Bi[k] < Bi[l])) xs++;
				if((Ai[k] < Ai[l]) && (Bi[k] > Bi[l])) xs++;
			}
		}
		cout << "Case #" << (i + 1) << ": " << xs << "\n";
	}
}
