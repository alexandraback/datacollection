#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = (ll)(-1E9);
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<bool> > ap;
vector<vector<bool> > vis;
ll r, c, n;

int problem(int i, int j) {
  int ans = 0;

  for (size_t k = 0; k < 4; k++) {
    int nx = i + dx[k];
    int ny = j + dy[k];

    if (nx >= 0 and nx < r and ny >= 0 and ny < c and !vis[nx][ny] and ap[i][j]==1 and ap[nx][ny]==1)
      ans++;
  }

  vis[i][j] = 1;
  return ans;
}

void solve() {
  cin >> r >> c >> n;

  ll ans = -inf;
  for (size_t bm = 0; bm < (1LL << r*c); bm++) {
    if(__builtin_popcountll(bm) != n)
      continue;


    ap.assign(r, vector<bool>(c, 0));
    for (size_t i = 0; i < r; i++) {
      for (size_t j = 0; j < c; j++) {
        ap[i][j] = ( (bm >> (c*i + j)) & 1LL );
      }
    }

    vis.assign(r, vector<bool>(c, 0));
    ll sum = 0;
    for (size_t i = 0; i < r; i++) {
      for (size_t j = 0; j < c; j++) {
        sum += problem(i, j);
      }
    }

    ans = min(ans, sum);
  }

  printf("%lld\n", ans);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    printf("Case #%d: ", i+1);
    solve();
  }

  return 0;
}
