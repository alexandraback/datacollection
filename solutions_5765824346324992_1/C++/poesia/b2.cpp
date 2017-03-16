#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long count_it(vector<int>& m, long long t) {
  if (t < 0)
    return 0;

  long long total = 0;

  for (int i = 0; i < m.size(); i++) {
    total += t / m[i] + 1;
  }  

  return total;
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int b, n;
    cin >> b >> n;

    vector<int> m(b);

    for (int i = 0; i < b; i++) {
      cin >> m[i];
    }

    long long lo = -1, hi = (1LL << 60);

    while (hi - lo > 1) {
      long long mid = (hi + lo) / 2;

      if (count_it(m, mid) >= n) {
        hi = mid;
      } else {
        lo = mid;
      }
    }

    int ans = -1;
    int rank = n - count_it(m, hi - 1);

    for (int i = 0; i < b; i++) {
      if (hi % m[i] == 0) {
        if (--rank == 0) {
          ans = i+1;
          break;
        }
      }
    }

    cout << "Case #" << t << ": " << ans << '\n';
  }

  return 0;
}
