#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

string charset = "welcomthdja ";
string target = "welcome to code jam";
int dp[19];
bool predicate(char c);

int main(void)
{
	int T;
	string temp;
	cin >> T;
	getline(cin, temp);
	for(int i = 0; i < T; i++)
	{
		string input;
		getline(cin, input);
		int y = 1;
		//PREPROCESSING BEGIN
		input.erase(remove_if(input.begin(), input.end(), &predicate), input.end());
		if(input.find_first_of("w") == string::npos || input.find_first_of("m") == string::npos)
		{
			y = 0;
			input.clear();
		}
		else
		{
			input = input.substr(input.find_first_of("w"));
			input = input.substr(0, input.find_last_of("m") + 1);
		}
		//PREPROCESSING END
		if(y != 0)
		{
			for(int j = 0; j < input.length(); j++)
			{
				int last = 0;
				while(true)
				{
					last = target.find_first_of(input.at(j), last);
					if(last == string::npos) break;
					if(last != 0) 
						dp[last] += dp[last - 1];
					else
						dp[last]++;
					if(++last >= target.length()) break;

				}
			}
			y = dp[dp.length() - 1];
		}
		cout << "Case #" << (i + 1) << ": " << y << endl;
	}
	return 0;
}

bool predicate(char c) { return charset.find(c) == string::npos; }
