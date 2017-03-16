#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int m[1111];
int main() {
  freopen("t.in", "r", stdin);
  freopen("t.out", "w", stdout);
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> m[i];
    ll ans1 = 0;
    for (int i = 0; i < n - 1; i++)
      if (m[i+1] < m[i])
        ans1 += m[i] - m[i+1];
    cout << "Case #" << tc << ": " << ans1 << " ";
    int maxRate = 0;
    for (int i = 0; i < n-1; i++)
      if (m[i + 1] < m[i])
        maxRate = max(maxRate, m[i] - m[i+1]);
    ll ans2 = 0;
    for (int i = 0; i < n-1; i++) {
      ans2 += min(m[i], maxRate);
    }
    cout << ans2 << endl;
  }
}
