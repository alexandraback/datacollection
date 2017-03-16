#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int bc(int l) {
  int res = 0;
  while(l) {
    res += (l&1);
    l/=2;
  }
  return res;
}

int doitsmall(int N, int R, int C) {
  int result = 100000;
  for (int i = 0; i <= 1<<(R*C); ++i) {
    if (bc(i) == N) {
      vector<vector<bool> > a(C, vector<bool>(R, false));
      for (int k = 0; k < R*C; ++k) {
        if (1 & (i >> k)) {
          a[k/C][k%C] = true;
        }
      }
      
      int tmp = 0;

      for (int k = 0; k < R; ++k) {
        for (int p = 0; p < C; ++p) {
          if (a[k][p]) {
            if (p < C-1) tmp += a[k][p+1];
            if (k < R-1) tmp += a[k+1][p];
          }
        }
      }
      result = min(tmp, result);
    }
  }
  return result;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N, R, C;
    cin >> R >> C >> N;
    printf("Case #%d: %d\n", t, doitsmall(N, min(R, C), max(R, C)));
  }
}
