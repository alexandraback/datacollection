#include <bits/stdc++.h>

#define F first
#define S second
#define llong long long
#define ullong unsigned long long
#define pb push_back
#define mp make_pair
#define y1 asdasd

using namespace std;

const int MXN = (int)2e6 + 10;
const int INF = (int)1e9 + 7;
const double EPS = (double)1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, k, ans;
bool b[16][16];
int T;

inline bool bit(int id, int mask){
  return ((1 << id) & mask) > 0;
}

inline bool check(int x, int y){
  return (x >= 0 && y >= 0 && x < n && y < m);
}

void solve(){
  ans = INF;
  int sum = 0;
  int tmp = n * m, nx, ny;
  for(int mask = 0; mask < (1 << tmp); ++mask){
    sum = 0;
    if((int)__builtin_popcount(mask) != k)
      continue;
    for(int i = 0; i < tmp; ++i){
      b[i / m][i % m] = bit(i, mask);
    }
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        if(!b[i][j])
          continue;
        for(int s = 0; s < 4; ++s){
          nx = i + dx[s], ny = j + dy[s];
          if(check(nx, ny) && b[nx][ny]){
            ++sum;
          }
        }
      }
    }
    ans = min(ans, sum / 2);
  }
}

int main(){
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  scanf("%d", &T);
  for(int test = 1; test <= T; ++test){
    scanf("%d%d%d", &n, &m, &k);
    solve();
    printf("Case #%d: %d\n", test, ans);
  }
  return 0;
}
