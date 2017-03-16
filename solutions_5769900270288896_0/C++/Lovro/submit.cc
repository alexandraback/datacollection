#define NDEBUG
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
template <typename T> inline int get_bit(const T &x, int index) {
  return int((x >> index) & 1);
}

int solve(int R, int C, int N) {
  vector<int> enemy_masks(R*C, 0);
  static const int dy[] = { -1, 0, 1, 0 };
  static const int dx[] = { 0, 1, 0, -1 };
  for (int y=0; y<R; ++y) {
    for (int x=0; x<C; ++x) {
      for (int dir=0; dir<4; ++dir) {
        int ny = y + dy[dir], nx = x + dx[dir];
        if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
          enemy_masks[y*C + x] |= 1 << (ny*C + nx);
        }
      }
    }
  }

  int ans = INT_MAX;
  for (int mask=0; mask < (1<<(R*C)); ++mask) {
    if (__builtin_popcount(mask) == N) {
      int cost = 0;
      for (int i=0; i<R*C; ++i) {
        if (get_bit(mask, i)) {
          cost += __builtin_popcount(mask & enemy_masks[i]);
        }
      }
      makemin(ans, cost);
    }
  }
  return ans / 2;
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
