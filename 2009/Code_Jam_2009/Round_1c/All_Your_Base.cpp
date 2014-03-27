#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

uint64_t mypow(int base, int exp);

int main(void)
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		long long y = 0;
		set<char> unique_chars;
		map<char, long long> dict;
		string input;
		cin >> input;
		for(int j = 0; j < input.size(); j++)
			unique_chars.insert(input[j]);
		int base = unique_chars.size();
		if(base == 1) base = 2;
		int assignment = 1;
		for(int j = 0; j < input.size(); j++)
		{
			if(dict.count(input[j]) == 0)
			{
				dict[input[j]] = assignment;
				if(assignment == 1) assignment = 0;
				else if(assignment == 0) assignment = 2;
				else assignment++;
			}
			y += dict[input[j]]*mypow(base,(input.size() - j - 1));
		}
		cout << "Case #" << (i + 1) << ": " << y << endl;
	}
	return 0;
}

uint64_t mypow(int base, int exp)
{
	uint64_t result = 1;
	for(int i = 0; i < exp; i++) result *= base;
	return result;
}
