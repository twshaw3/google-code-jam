#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

vector<char> solve(vector<char> N);

int main(void)
{
	int TC;
	cin >> TC;
	for(int tc = 0; tc < TC; tc++)
	{
		string in;
		cin >> in;
		vector<char> N;
		for(int i = 0; i < in.length(); i++) N[i] = in[i];
		cout << "Case #" << (tc + 1) << ": ";
		vector<char> out = solve(N);
		for(int i = 0; i < out.size(); i++) cout << out[i];
		cout << endl;
	}
	return 0;
}

vector<char> solve(vector<char> N) {
	//check if sorted
	bool sorted = true;
	for(int i = 0; i < N.size()-1; i++)
		if(N[i] < N[i+1]) sorted = false;
	if(sorted) {
		
	} else {

	}
}
