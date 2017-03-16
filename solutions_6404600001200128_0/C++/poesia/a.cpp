#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    int m1 = 0, maxDiff = 0, last, x;
    vector<int> v(n);
    cin >> v[0];

    for (int i = 1; i < n; i++) {
      cin >> v[i];
      if (v[i] < v[i-1]) {
        m1 += v[i-1] - v[i];
        maxDiff = max(maxDiff, v[i-1] - v[i]);
      }
    }

    int m2 = 0;

    for (int i = 1; i < n; i++) {
      m2 += min(maxDiff, v[i-1]);
    }

    cout << "Case #" << t << ": " << m1 << " " << m2 << '\n';
  }

  return 0;
}
