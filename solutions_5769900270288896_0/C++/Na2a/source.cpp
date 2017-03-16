#include <bits/stdc++.h>

#define llong unsigned long long

#define pii pair<int, int>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef vector<int> big;

const double eps = 1e-11;

const int MAXN = (int) 20 + 7;
const int INF = (int) 1e9 + 7;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int ans = INF;

int n, m, put;
int b[MAXN][MAXN], a[MAXN * MAXN];

void rec(int pos, int p = 0) {
  if (pos == n * m) {
    if (p != put)
      return;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        b[i][j] = a[i * m + j];
      }
    }
    int bad = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int d = 0; d < 4; d++) {
          int nx = i + dx[d];
          int ny = j + dy[d];
          if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (b[i][j] && b[nx][ny]) ++bad;
          }
        }
      }
    }  
    ans = min(ans, bad);
  }
  else {
    a[pos] = 0;
    rec(pos + 1, p);
    a[pos] = 1;
    rec(pos + 1, p + 1);
  }
}

int main() {  
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  
   
  int t;
  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    scanf("%d%d%d", &n, &m, &put);
    ans = INF;
    rec(0);
    printf("Case #%d: %d\n", cases, ans/2);
  }

  return 0;
}