#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		long long r, t;
		cin >> r >> t;
		long long area, j;
		double j_hat;
		j_hat = -(2.0*r - 1)/4 + sqrt(pow(2.0*r - 1,2) + 8.0*t)/4.0;
		j = (long long)j_hat;
		area = 2*j*j + j*(2*r - 1);
		while(area < t)
		{
			j++;
			area = 2*j*j + j*(2*r - 1);
		}
		if(area > t) j--;
		cout << "Case #" << (i+1) << ": " << j << endl;
	}
	return 0;
}
