#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>


using namespace std;

int gi[1000];

int main(void)
{
  int TC;
  cin >> TC;
  for(int tc = 0; tc < TC; tc++)
  {
    int R, k, N;
    cin >> R >> k >> N;
    for(int i = 0; i < N; i++) cin >> gi[i];
    uint64_t y = 0;
    int ride_num = 1;
    int i = 0;
    bool flag = false;
    while(ride_num <= R) {
      uint64_t current_ride = 0;
      int g = 0;
      while(true) {
        if(current_ride + gi[i] > k) break;
        current_ride += gi[i];
        i = (i + 1) % N;
        if(g < N-1) g++;
        else {
          break;
        }
      }
      y += current_ride;
      ride_num++;
      if(i == 0 && g < N-1 && flag == false) {
        flag = true;
        y += y*(R - ride_num)/ride_num;
        ride_num += ((R - ride_num)/ride_num)*ride_num;
      }
    }
    cout << "Case #" << (tc + 1) << ": " << y << endl;
  }
  return 0;
}
