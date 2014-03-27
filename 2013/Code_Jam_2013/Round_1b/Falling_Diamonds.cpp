#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

float compute_probability(int diamonds, int level, int max);
int fact(int n);

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int N, X, Y;
		float p;
		cin >> N >> X >> Y;
		int b = floor((sqrt(1 + 8*N) + 1)/4) - 1;
		if((abs(X) + abs(Y)) <= (2*b)) p = 1;
		else if((abs(X) + abs(Y)) > (2*b + 2)) p = 0;
		else 
		{
			b = 2*b + 1;
			int top_y = b + 1;
			if(abs(Y) == top_y) p = 0;
			else p = compute_probability(N - b*(b + 1)/2, Y, top_y);
		}
		cout << "Case #" << (i + 1) << ": " << p << "\n";
	}
}

float compute_probability(int diamonds, int level, int max)
{
	int numer = 0;
	int denom = 0;
	int inc = 0;
	int l, r;
	int d = fact(diamonds);
	cout << "diamonds = " << diamonds << "\n";
	//cout << "diamonds = " << diamonds << ", " << "level = " << level << ", " << "max = " << max << "\n";
	for(l = 0, r = diamonds-l; (l <= max) && (l <= diamonds); l++, r--)
	{
		if(r <= max)
		{
			inc = d/(fact(l) * fact(r));
			//cout << "inc = " << inc << "\n";
			denom += inc;
			if(l > level) numer += inc;
		}
	}
	//cout << "fraction = " << numer << "/" << denom << "\n";
	return (float)numer/(float)denom;
}


int fact(int n)
{
	if(n <= 1) return 1;
	else return n * fact(n - 1);
}
