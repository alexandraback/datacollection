#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int m[n];
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
  }
  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (m[i] > m[i + 1]) res += m[i] - m[i + 1];
  }
  cout << res << " ";
  int rate = 0;
  for (int i = 0; i < n - 1; ++i) {
    rate = max(rate, m[i] - m[i + 1]);
  }
  res = 0;
  for (int i = 0; i < n - 1; ++i) {
    res += min(rate, m[i]);
  }
  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
