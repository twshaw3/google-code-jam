#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int>& solve(vector<int> &N);

int main(void)
{
  int TC;
  cin >> TC;
  for(int tc = 0; tc < TC; tc++)
  {
    string in;
    cin >> in;
    vector<int> N(in.length());
    for(int i = 0; i < in.length(); i++) {
      stringstream str;
       str << in[i];
       str >> N[i];
    }
    cout << "Case #" << (tc + 1) << ": ";
    vector<int> out = solve(N);
    for(int i = 0; i < out.size(); i++) cout << out[i];
    cout << endl;
  }
  return 0;
}

vector<int>& solve(vector<int> &N) {
  //check if sorted
  bool sorted = true;
  for(int i = 0; i < N.size()-1; i++)
    if(N[i] < N[i+1]) sorted = false;
  if(sorted) {
    //sort the other way
    sort(N.begin(), N.end());
    //add a zero
    N.insert(N.begin()+1, 0);
    //if leading digit is zero, swap with next smallest
    if(N[0] == 0) {
      int j;
      while(N[j] == 0) j++;
      N[0] = N[j];
      N[j] = 0;
    }
    return N;
  } else {
    for(int i = N.size() - 2; i >= 0; i--) {
      for(int j = N.size() - 1; j > i; j--) {
        if(N[j] > N[i]) {
          int temp = N[j];
          N.erase(N.begin() + j);
          N.insert(N.begin() + i, temp);
          sort(N.begin() + i + 1, N.end());
          return N;
        }
      }
    }
  }
}
