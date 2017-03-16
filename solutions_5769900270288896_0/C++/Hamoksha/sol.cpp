#include <bits/stdc++.h>

using namespace std;

const int N = 20, inf = 1e9;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C, n;

char ad[N][N], vis[N][N];

int res;

char cnt[N][N][N * N];

void gen(int r, int c, int t) {
  for (int a = 0; a < (1 << R); a++) {
    for (int b = 0; b < (1 << C); b++) {
      int nt = t;
      memset(ad, 0, sizeof ad);
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          if ((a & (1 << i)) || (b & (1 << j))) {
            ad[i][j] = 1;
            nt--;
          }
        }
      }
//      cerr << nt << endl;
      if (nt == 0) {
        int tmp = 0;
        memset(vis, 0, sizeof vis);
        for (int x = 0; x < R; x++)
          for (int u = 0; u < C; u++) if (ad[x][u]) {
            for (int d = 0; d < 4; d++) {
              int nx = x + dx[d];
              int ny = u + dy[d];
              if (nx >= 0 && ny >= 0 && nx < R && ny < C && ad[nx][ny] && !vis[nx][ny]) {
                ++tmp;
              }
            }
            vis[x][u] = 1;
          }
        res = min(res, tmp);
      }
    }
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    printf("Case #%d: ", t);
    cin >> R >> C >> n;
    res = inf;
    gen(0, 0, n);
    cout << (res == inf ? 0 : res) << endl;
  }
  return 0;
}
