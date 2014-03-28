#include <iostream>
#include <cmath>
#include <algorithm>

#define MIN(i, j)   (i < j ? i : j)
#define MAX(i, j)   (i > j ? i : j)

using namespace std;

struct ranking {
  int value;
  int index;
};

bool compare(ranking a, ranking b) {return a.value >= b.value;}

int vi[10000];
ranking ranks[10000];
int must_have_at_least[10000];
int can_have_at_most[10000];
int will_spend[10000];

int main(void)
{
  int T;
  cin >> T;
  for(int i = 0; i < T; i++)
  {
    int E, R, N;
    cin >> E >> R >> N;
    for(int j = 0; j < N; j++)
    {
      cin >> vi[j];
      ranks[j].value = vi[j];
      ranks[j].index = j;
      must_have_at_least[j] = R;
      can_have_at_most[j] = E;
    }
    int y = 0;
    sort(ranks, ranks + N, compare);
    int maxind;
    int ind;
    for(int j = 0; j < N; j++)
    {
      maxind = ranks[j].index;
      int most_can_spend;
      if(maxind == N-1)
        most_can_spend = can_have_at_most[maxind];
      else
        most_can_spend = can_have_at_most[maxind] - must_have_at_least[maxind + 1] + R;
	  will_spend[maxind] = most_can_spend;
      int floor, ceil;
	  ind = maxind+1;
	  ceil = can_have_at_most[maxind] - most_can_spend;
      while(ind < N && (ind - maxind)*R < E) {
        can_have_at_most[ind] = MIN(ceil + (ind - maxind)*R, can_have_at_most[ind]);
        ind++;
      }
      ind = maxind;
	  floor = must_have_at_least[maxind] + most_can_spend - R;
      while(ind >= 0 && ((maxind - ind)*R) < E) {
        if(ind < N-1) must_have_at_least[ind] = MAX(must_have_at_least[ind + 1] + floor - (maxind - ind)*R, must_have_at_least[ind]);
        ind--;
      }
    for(int j = 0; j < N; j++) cout << "must_have_at_least[j] = " << must_have_at_least[j] << endl;
    }
    for(int j = 0; j < N; j++) y += vi[j]*will_spend[j];
    cout << "Case #" << (i + 1) << ": " << y << endl;
  }
  return 0;
}
