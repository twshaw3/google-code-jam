#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;


int main(void)
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int N,M;
		cin >> N >> M;
		string existing[100];
		string create[100];
		set<string> dirs;
		int y = 0;
		for(int j = 0; j < N; j++) cin >> existing[j];
		for(int j = 0; j < M; j++) cin >> create[j];
		for(int j = 0; j < N; j++) dirs.insert(existing[j]);
		for(int j = 0; j < M; j++)
		{
			string s = create[j];
			while(true)
			{
				if(dirs.count(s) != 0) break;
				y++;
				dirs.insert(s);
				int idx = s.find_last_of("/");
				if(idx == 0) break;
				s = s.substr(0,idx);
			}
				
		}
		cout << "Case #" << (i + 1) << ": " << y << endl;
	}
	return 0;
}
