#define NDEBUG
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
#define ALL(x) (x).begin(), (x).end()

int solve(int R, int C, int N) {
  if (N <= (R*C+1) / 2) {
    return 0;
  }

  struct Alternative {
    int free = 0;
    vector<int> costs;
  };
  Alternative alts[2];

  static const int dy[] = { -1, 0, 1, 0 };
  static const int dx[] = { 0, 1, 0, -1 };
  for (int y=0; y<R; ++y) {
    for (int x=0; x<C; ++x) {
      int cost = 0;
      for (int dir=0; dir<4; ++dir) {
        int ny = y + dy[dir], nx = x + dx[dir];
        if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
          ++cost;
        }
      }
      alts[(y+x)%2].costs.push_back(cost);
      alts[(y+x+1)%2].free++;
    }
  }

  int ans = INT_MAX;
  for (Alternative& alt : alts) {
    sort(ALL(alt.costs));
    int cost = accumulate(alt.costs.begin(), alt.costs.begin() + (N - alt.free), 0);
    makemin(ans, cost);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int R, C, N;
    cin >> R >> C >> N;
    printf("Case #%d: %d\n", tt, solve(R, C, N));
  }
}
