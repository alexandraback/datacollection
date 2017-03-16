#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll x[3030], y[3030];
int n;
ll cross(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
  return (bx-ax)*(cy-ay) - (by-ay)*(cx-ax);
}
int count(ll ax, ll ay, ll bx, ll by) {
  int cnt=0;
  for (int i = 0; i < n; ++i) {
    if (cross(ax, ay, bx, by, x[i], y[i]) < 0)
      cnt++;
  }
  return cnt;
}
int main() {
  int T; cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    cout << "Case #" << tc << ":" << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }
    if (n == 1) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < n; ++i) {
      int ans = 1<<29;
      for (int j = 0; j < n; ++j) if (i != j) {
        int a = count(x[i], y[i], x[j], y[j]);
        int b = count(x[j], y[j], x[i], y[i]);
        //if (i == 4) {
          //cout << x[i] << " " << y[i] << " " << j << " " << a << " "<< b << endl;
        //}
        ans = min(ans, a);
        ans = min(ans, b);
      }
      cout << ans << endl;
    }
  }
}
