// TEMPLATE {{{
#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#define OJ 1
#else
#define OJ 0
#endif

#define endl '\n'
#define TIMESTAMP merr << "Execution time: " << fixed << setprecision(3) << (double)clock()/CLOCKS_PER_SEC << " s.\n"
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
    int n;
    int A[55] = {};
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      cnt += A[i];
    }
    vector<pair<int,int> > R;
    int sum;
    for (int t = 0; t < cnt-1; t++) {
      int mx = -1;
      sum = 0;
      for (int i = 0; i < n; i++) {
        if (A[i] == 0) continue;
        if (mx == -1 || A[mx] < A[i]) {
          mx = i;
        }
        sum += A[i];
      }
      if (sum == 2) break;
      assert(mx != -1);
      if (A[mx] == 1) {
        R.push_back(make_pair(-1, mx));
        A[mx]--;
      } else {
        int mx2 = -1;
        for (int i = 0; i < n; i++) {
          if (i == mx) continue;
          if (A[i] == A[mx]) {
            mx2 = i;
          }
        }
        if (mx2 == -1) {
          R.push_back(make_pair(-1, mx));
          A[mx]--;
        } else {
          R.push_back(make_pair(mx2, mx));
          A[mx]--;
          A[mx2]--;
        }
      }
    }
    assert(sum == 2);
    int a = -1, b = -1;
    for (int i = 0; i < n; i++) {
      if (A[i] == 0) continue;
      if (a == -1) a = i;
      else b = i;
    }
    R.push_back(make_pair(a,b));
    cout << "Case #" << tt+1 << ": ";
    for (int i = 0; i < (int)R.size(); i++) {
      string s;
      if (R[i].first != -1) s += (char)('A' + R[i].first);
      if (R[i].second != -1) s += (char)('A' + R[i].second);
      cout << s << " ";
    }
    cout << endl;
  }
  return 0;
}
