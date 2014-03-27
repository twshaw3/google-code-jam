#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int vels[500][3];
int poss[500][3];
double mupos[3];
double muvel[3];

int main(void)
{
	int TC;
	cin >> TC;
	for(int tc = 0; tc < TC; tc++)
	{
		double dmin, tmin;
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> poss[i][0] >> poss[i][1] >> poss[i][2];
			cin >> vels[i][0] >> vels[i][1] >> vels[i][2];
		}
		//Average positions and velocities
		mupos = {0.0, 0.0, 0.0};
		muvel = {0.0, 0.0, 0.0};
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < 3; j++) {
				mupos[j] += poss[i][j];
				muvel[j] += vels[i][j];
			}
		}
		for(int j = 0; j < 3; j++) {
			mupos[j] = mupos[j]/((double)N);
			muvel[j] = muvel[j]/((double)N);
		}
		//This defines a line in R3. Now need to find closest approach to origin
		//Need to find t that minimizes sum((mupos[j] + muvel[j]*t)^2)
		//We get sum((mupos[j] + t*muvel[j])*muvel[j]) = 0
		//We then have sum(mupos*muvel) + t*sum(muvel^2) = 0
		//or t = -sum(mupos*muvel)/sum(muvel^2)
		tmin = 0.0;
		double numer = 0.0;
		double denom = 0.0;
		for(int j = 0; j < 3; j++) {
			numer -= mupos[j]*muvel[j];
			denom += muvel[j]*muvel[j];
		}
		if(denom != 0) 
			tmin = numer / denom;
		//time cannot be negative
		if(tmin < 0.0) tmin = 0.0;
		//Now we need to find dmin
		//dmin = sqrt(sum((mupos[j] + muvel[j]*tmin)^2))
		double accum = 0.0;
		for(int j = 0; j < 3; j++)
			accum += pow(mupos[j] + muvel[j]*tmin,2);
		dmin = sqrt(accum);
		cout << "Case #" << (tc + 1) << ": " << dmin << " " << tmin << endl;
	}
	return 0;
}
