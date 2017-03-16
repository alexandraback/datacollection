#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <vector>
using namespace std;

bool field[16][16];

int Calc(int R, int C) {
  int result = 0;

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C - 1; ++j) {
      if (field[i][j] && field[i][j + 1]) {
        ++result;
      }
    }
  }

  for (int i = 0; i < R - 1; ++i) {
    for (int j = 0; j < C; ++j) {
      if (field[i][j] && field[i + 1][j]) {
        ++result;
      }
    }
  }

  return result;
}


void Solve() {
  int R, C, N;
  cin >> R >> C >> N;

  int RC = R * C;
  int lim = 1 << RC;

  int result = numeric_limits<int>::max();

  for (int mask = 0; mask < lim; ++mask) {
    int cnt = __builtin_popcount(mask);
    if (cnt != N) {
      continue;
    }

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        field[i][j] = false;
      }
    }

    for (int idx = 0; idx < RC; ++idx) {
      if ((1 << idx) & mask) {
        int x = idx / C;
        int y = idx % C;
        field[x][y] = true;
      }
    }

    result = min(result, Calc(R, C));
  }

  cout << result;
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/B-small-attempt0.in", "rb", stdin);
  freopen("../Console/B-small-attempt0.out", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    cout << "Case #" << tc + 1 << ": ";
    Solve();
    cout << endl;
  }

  return 0;
}
