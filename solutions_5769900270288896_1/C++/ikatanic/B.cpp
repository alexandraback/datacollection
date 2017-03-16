#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

typedef pair<int, int> par;

vector<vector<int>> d;

struct cmp {
  bool operator () (const par &a, const par &b) {
    if (d[a.first][a.second] != d[b.first][b.second])
      return d[a.first][a.second] < d[b.first][b.second];
    return a < b;
  }
};

set<par, cmp> S;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int large(int n, int m, int k) {
  d.clear();
  d.resize(n, vector<int>(m, 0));
  S.clear();
  REP(i, n) REP(j, m) S.insert({i, j});
  
  int ans1 = 0;
  REP(i, k) {
    auto p = *S.begin();
    S.erase(S.begin());

    int x = p.first, y = p.second;
    ans1 += d[x][y];
    
    REP(k, 4) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      
      par np = make_pair(nx, ny);
      if (S.find(np) == S.end()) continue;

      S.erase(np);
      d[nx][ny]++;
      S.insert(np);
    }
  }

  d.clear();
  d.resize(n, vector<int>(m, 0));
  int ans2 = 0;
  REP(i, n) REP(j, m) {
    if (i > 0) d[i][j]--;
    if (i+1 < n) d[i][j]--;
    if (j > 0) d[i][j]--;
    if (j+1 < m) d[i][j]--;
    ans2 -= d[i][j];
  }
  ans2 /= 2;

  S.clear();
  REP(i, n) REP(j, m) S.insert({i, j});

  REP(i, n*m-k) {
    auto p = *S.begin();
    S.erase(S.begin());

    int x = p.first, y = p.second;
    ans2 += d[x][y];
    
    REP(k, 4) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      
      par np = make_pair(nx, ny);
      if (S.find(np) == S.end()) continue;

      S.erase(np);
      d[nx][ny]++;
      S.insert(np);
    }
  }

  return min(ans1, ans2);
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    printf("Case #%d: ", tp);
    printf("%d\n", large(n, m, k));
  }
  return 0;
}
