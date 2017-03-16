#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int rows, cols, n;
int mask[16][16];
int r[16];
int c[16];

int main() {
  int tests; cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    cin >> rows >> cols >> n;
    for (int i = 0, idx = 0; i < rows; i++) for (int j = 0; j < cols; j++, idx++) mask[i][j] = 1 << idx, r[idx] = i, c[idx] = j;

    int space = (rows*cols);
    int all = 1 << space;
    int best = 10000;
    for (int m = 0; m < all; m++) {
      int c = 0;
      for (int i = 0; i < space; i++) if (m & (1<<i)) c++;
      if (c != n) continue;

      int score = 0;
      for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) {
        if ((mask[i][j] & m) == 0) continue;
        for (int d = 0; d < 4; d++) {
          int ii = i + dy[d], jj = j + dx[d];
          if (ii < 0 || ii >= rows || jj < 0 || jj >= cols) continue;
          if (mask[ii][jj] & m) score++;
        }
      }
      best = min(best, score);
    }

    cout << "Case #" << tc << ": " << (best/2) << endl;

  }
  return 0;
}

