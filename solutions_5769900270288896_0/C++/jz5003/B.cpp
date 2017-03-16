/*
ID: jeffrey31
LANG: C++
TASK: B
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

const int N = 17;

int t, r, c, n, dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0}, ans = 1 << 25;
bool b[N][N];
inline bool inb(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}
int main() {
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  cin >> t;
  for(int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    cin >> r >> c >> n;
    ans = 1 << 25;
    for(int j = 0; j < (1 << (r * c)); j++) {
      if(__builtin_popcount(j) != n) continue;
      memset(b, 0, sizeof(b));
      for(int k = 0; k < N; k++) {
        if( (j >> k) & 1 ) {
          b[k / c][k % c] = 1;
        }
      }
      int cnt = 0;
      for(int p = 0; p < r; p++) {
        for(int q = 0; q < c; q++) {
          if(!b[p][q]) continue;
          for(int z = 0; z < 4; z++) {
            int p2 = p + dx[z];
            int q2 = q + dy[z];
            if(inb(p2,q2) && b[p2][q2]) {
              cnt++;
            }
          }
        }
      }
      cnt/=2;
      ans = min(ans, cnt);
    }
    cout << ans << endl;
  }
  return 0;
}