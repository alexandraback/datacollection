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

const int MAXN = (int) 5e3 + 7;
const int INF = (int) 1e9 + 7;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int n, m, put;
vector<vector<int>> a;

int solveB() {
  int rem = put;
  set<pair<int, pii>> all;
  map<pii, int> cost;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = 0;
      all.insert(mp(0, mp(i, j)));
      cost[mp(i, j)] = 0;  
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i + j) % 2 == 0 && rem) {
        --rem;
        a[i][j] = 1;
        all.erase(mp(cost[mp(i, j)], mp(i, j)));
        for (int d = 0; d < 4; d++) {
          int nx = i + dx[d];
          int ny = j + dy[d];
          if (nx > 0 && ny > 0 && nx <= n && ny <= m) {
            if (!a[nx][ny]) {
              all.erase(mp(cost[mp(nx, ny)], mp(nx, ny)));
              all.insert(mp(++cost[mp(nx, ny)], mp(nx, ny)));
            }
          }
        }
      }
    }
  }
  int res = 0;
  while (rem--) {
    pair<int, pii> w = *all.begin();
    pii pos = w.s;
    res += w.f;
    a[pos.f][pos.s] = 1;
    all.erase(mp(w.f, pos));
    for (int d = 0; d < 4; d++) {
      int nx = pos.f + dx[d];
      int ny = pos.s + dy[d];
      if (nx > 0 && ny > 0 && nx <= n && ny <= m) {
        if (!a[nx][ny]) {
          all.erase(mp(cost[mp(nx, ny)], mp(nx, ny)));
          all.insert(mp(++cost[mp(nx, ny)], mp(nx, ny)));
        }
      }
    }
  }
  return res;
}


int solveA() {
  int rem = put;
  set<pair<int, pii>> all;
  map<pii, int> cost;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = 0;
      all.insert(mp(0, mp(i, j)));
      cost[mp(i, j)] = 0;  
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i + j) % 2 && rem) {
        --rem;
        a[i][j] = 1;
        all.erase(mp(cost[mp(i, j)], mp(i, j)));
        for (int d = 0; d < 4; d++) {
          int nx = i + dx[d];
          int ny = j + dy[d];
          if (nx > 0 && ny > 0 && nx <= n && ny <= m) {
            if (!a[nx][ny]) {
              all.erase(mp(cost[mp(nx, ny)], mp(nx, ny)));
              all.insert(mp(++cost[mp(nx, ny)], mp(nx, ny)));
            }
          }
        }
      }
    }
  }
  int res = 0;
  while (rem--) {
    pair<int, pii> w = *all.begin();
    pii pos = w.s;
    res += w.f;
    a[pos.f][pos.s] = 1;
    all.erase(mp(w.f, pos));
    for (int d = 0; d < 4; d++) {
      int nx = pos.f + dx[d];
      int ny = pos.s + dy[d];
      if (nx > 0 && ny > 0 && nx <= n && ny <= m) {
        if (!a[nx][ny]) {
          all.erase(mp(cost[mp(nx, ny)], mp(nx, ny)));
          all.insert(mp(++cost[mp(nx, ny)], mp(nx, ny)));
        }
      }
    }
  }
  return res;
}

int main() {  
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  
   
  int t, cnt=0;
  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    scanf("%d%d%d", &n, &m, &put);
    a.resize(n+1);
    for(int i=1;i<=n;i++)a[i].resize(m+1);
    ++cnt;
    if(cnt%100==0)cerr<<"+";
    printf("Case #%d: %d\n", cases, min(solveA(), solveB()));
  }

  return 0;
}