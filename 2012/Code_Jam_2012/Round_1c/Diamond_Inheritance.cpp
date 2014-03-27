#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool gsearch(int classnum);

int inherits_from[1000][10];
int visited[1000];

int main(void)
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		for(int j = 0; j < 1000; j++)
			for(int k = 0; k < 10; k++)
				inherits_from[j][k] = -1;
		int N;
		cin >> N;
		for(int j = 0; j < N; j++)
		{
			int M;
			cin >> M;
			for(int k = 0; k < M; k++)
			{
				cin >> inherits_from[j][k];
			}
		}
		
		string y = "No";
		for(int j = 0; j < N; j++)
		{
			for(int k = 0; k < 1000; k++)
				visited[k] = 0;
			if(gsearch(j))
			{
				y = "Yes";
				break;
			}
		}

		cout << "Case #" << (i + 1) << ": " << y << endl;
	}
	return 0;
}

bool gsearch(int classnum)
{
	bool retval = false;
	for(int parent_ind = 0; inherits_from[classnum][parent_ind] != -1; parent_ind++)
	{
		int parent = inherits_from[classnum][parent_ind];
		if(visited[parent] > 0)
			return true;
		visited[parent]++;
		retval = retval || gsearch(parent);
	}
	return retval;
}
