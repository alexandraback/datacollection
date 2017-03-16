#include <bits/stdc++.h>
 
using namespace std;
 
// TEMPLATE {{{
#ifndef LOCAL
#define OJ 1
#else
#define OJ 0
#endif
 
#define endl '\n'
#define TIMESTAMP merr << "Execution time: " << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& __m, const T& __s) { if (!OJ) cerr << "\E[91m" << __s << "\E[0m"; return __m; }
C_ merr;
 
struct __s { __s() { if (OJ) { ios_base::Init i; cin.sync_with_stdio(0); cin.tie(0); } } ~__s(){ TIMESTAMP; } } __S;
/// END OF TEMPLATE }}}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int r,c,n;
    int A[17][17] = {};
    int ans = 1000000000;
    cin >> r >> c >> n;
    for (int bit = 0; bit < (1<<(r*c)); bit++) {
      int cnt = 0;
      for (int i = 0; i < r*c; i++) {
        if (bit & (1<<i)) cnt++;
      }
      if (cnt != n) continue;
      cnt = 0;
      for (int i = 0; i < r*c; i++) {
        A[i/c][i%c] = (bit & (1<<i));
      }
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (A[i][j] && A[i+1][j]) cnt++;
          if (A[i][j] && A[i][j+1]) cnt++;
        }
      }
      ans = min(ans, cnt);
    }
    cout << "Case #" << tt+1 << ": " << ans << endl;
  }
  return 0;
}
