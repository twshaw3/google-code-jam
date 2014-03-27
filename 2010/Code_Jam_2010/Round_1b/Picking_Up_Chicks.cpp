#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;



int main(void)
{
  int TC;
  cin >> TC;
  for(int tc = 0; tc < TC; tc++)
  {
    int N, K, T;
    uint64_t B;
    int y = 0;
    int Xi[50];
    int Vi[50];
    double ATi[50];
    int swaps[50];
    cin >> N >> K >> B >> T;
    for(int i = 0; i < N; i++) cin >> Xi[i];
    for(int i = 0; i < N; i++) cin >> Vi[i];
    for(int i = 0; i < N; i++) ATi[i] = ((double)(B - Xi[i]))/Vi[i];
    for(int i = 0; i < N; i++) swaps[i] = 0;
    int accum = 0;
    cout << "Case #" << (tc + 1) << ": ";
    for(int i = 0; i < N; i++) {
      if(ATi[i] <=T) {
        accum++;
        for(int j = 0; j < N; j++) {
          if(ATi[j] > T && Xi[i] < Xi[j]) swaps[i]++;
        }
      } else {
        swaps[i] = 100;
      }
    }
    if(accum < K) {
      cout << "IMPOSSIBLE";
    } else {
      sort(swaps, swaps + N);
      accum = 0;
      for(int i = 0; i < N; i++) {
        if(accum >= K) break;
        else {
          y += swaps[i];
          accum++;
        }
      }
      cout << y;
    }
    cout << endl;
  }
  return 0;
}
