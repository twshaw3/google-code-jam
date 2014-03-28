#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int H, W;
int alt_map[102][102];
char label_map[102][102];

char dfs(int r, int c, char label);

int main(void)
{
  int TC;
  cin >> TC;
  for(int tc = 0; tc < TC; tc++)
  {
    int y = 0;
    cin >> H >> W;
    for(int r = 0; r <= H+1; r++) {
      for(int c = 0; c <= W+1; c++) {
        if(r == 0 || r == H+1 || c == 0 || c == W+1)
          alt_map[r][c] = 10001;
        else
          cin >> alt_map[r][c];
        label_map[r][c] = 0;
      }
    }
    bool done = false;
    char label = 'a';
    while(!done) {
      done = true;
      for(int r = 1; r <= H; r++) {
        for(int c = 1; c <= W; c++) {
          if(label_map[r][c] == 0) {
            done = false;
            if(label == dfs(r, c, label)) label++;
          }
        }
      }
    }
    cout << "Case #" << (tc + 1) << ":" << endl;
    for(int r = 1; r <= H; r++) {
      for(int c = 1; c <= W; c++) {
        cout << label_map[r][c];
        if(c < W) cout << " ";
      }
      cout << endl;
    }
  }
  return 0;
}

char dfs(int r, int c, char label)
{
  int true_label;
  if(label_map[r][c] != 0) return label_map[r][c];
  int n, w, e, s;
  n = alt_map[r - 1][c];
  w = alt_map[r][c - 1];
  e = alt_map[r][c + 1];
  s = alt_map[r + 1][c];
  int low = min(min(n, w), min(e, s));
  if(low >= alt_map[r][c]) true_label = label;
  else if(n == low) true_label = dfs(r - 1, c, label);
  else if(w == low) true_label = dfs(r, c - 1, label);
  else if(e == low) true_label = dfs(r, c + 1, label);
  else true_label = dfs(r + 1, c, label);
  label_map[r][c] = true_label;
  return true_label;
}
