#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll x[3030], y[3030];
int n;
const double pi = acos(-1);
const double eps = 1e-9;
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
      vector<pair<double,int>> others;
      for (int j = 0; j < n; ++j) if (i != j) {
        int dx = x[j] - x[i], dy = y[j] - y[i];
        others.push_back(make_pair(atan2(dy, dx), j));
        others.push_back(make_pair(atan2(dy, dx)+2*pi, j));
        others.push_back(make_pair(atan2(dy, dx)+4*pi, j));
        others.push_back(make_pair(atan2(dy, dx)+6*pi, j));
      }
      sort(begin(others),end(others));
      int l = 0, r = 0;
      while (r + 1 < others.size() && others[r+1].first < others[l].first + pi - eps) {
        ++r;
      }
      int ans = r - l;
      while (r + 1 < others.size()) {
        ++r;
        while (others[r].first > others[l].first + pi - eps)
          l++;
        ans = min(ans, r-l);
      }
      cout << ans << endl;
    }
  }
}
