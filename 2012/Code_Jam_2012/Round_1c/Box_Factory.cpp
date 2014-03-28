#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

uint64_t a[100];
uint64_t b[100];
int A[100];
int B[100];

class Memo {
    map<pair<uint64_t, uint64_t>, uint64_t> record;
  public:
    void add(uint64_t si, uint64_t sj, uint64_t res);
    bool exists(uint64_t si, uint64_t sj);
    uint64_t lookup(uint64_t si, uint64_t sj);
};

bool Memo :: exists(uint64_t si, uint64_t sj) {
  return record.count(make_pair(si, sj)) != 0;
}

uint64_t Memo :: lookup(uint64_t si, uint64_t sj) {
  return record[make_pair(si, sj)];
}

void Memo :: add(uint64_t si, uint64_t sj, uint64_t res) {
  record[make_pair(si, sj)] = res;
}


class Cache {
    Memo dp[100][100];
  public:
    bool check_cache(int i, int j, uint64_t shippedi, uint64_t shippedj);
    uint64_t get_from_cache(int i, int j, uint64_t shippedi, uint64_t shippedj);
    void update_cache(int i, int j, uint64_t shippedi, uint64_t shippedj, uint64_t res);
};

bool Cache :: check_cache(int i, int j, uint64_t shippedi, uint64_t shippedj) {
  return dp[i][j].exists(shippedi, shippedj);
}

void Cache :: update_cache(int i, int j, uint64_t shippedi, uint64_t shippedj, uint64_t res) {
  dp[i][j].add(shippedi, shippedj, res);
}

uint64_t Cache :: get_from_cache(int i, int j, uint64_t shippedi, uint64_t shippedj) {
  return dp[i][j].lookup(shippedi, shippedj);
}

uint64_t solve(int i, int j, uint64_t shippedi, uint64_t shippedj);
Cache cache;

int main(void)
{
  int TC;
  cin >> TC;
  for(int tc = 0; tc < TC; tc++)
  {
    int N, M;
    cin >> N >> M;
    cache = Cache();
    for(int i = 0; i < N; i++) cin >> a[i] >> A[i];
    for(int i = 0; i < M; i++) cin >> b[i] >> B[i];
    uint64_t y = solve(N-1, M-1, 0, 0);
    cout << "Case #" << (tc + 1) << ": " << y << endl;
  }
  return 0;
}

uint64_t solve(int i, int j, uint64_t shippedi, uint64_t shippedj)
{
  uint64_t ret = 0;
  uint64_t ai, bj;
  ai = a[i] - shippedi;
  bj = b[j] - shippedj;
  if(i == -1 || j == -1) return 0;
  else if(cache.check_cache(i, j, shippedi, shippedj)) {
    return cache.get_from_cache(i, j, shippedi, shippedj);
  }
  else if(A[i] == B[j]) { //Types are the same
    uint64_t shipped = min(ai, bj);
    if(ai < bj)
      ret = shipped + solve(i - 1, j, 0, shipped + shippedj);
    else if(ai > bj)
      ret = shipped + solve(i, j - 1, shipped + shippedi, 0);
    else  //ai == bj
      ret = shipped + solve(i - 1, j - 1, 0, 0);
  }
  else ret = max(solve(i - 1, j, 0, shippedj), solve(i, j - 1, shippedi, 0));
  cache.update_cache(i, j, shippedi, shippedj, ret);
  return ret;
}
