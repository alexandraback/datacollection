/*
 *-
 * File: stuff.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Aug 23, 2014, 11:50:25 PM
 */

#include <bits/stdc++.h>

using namespace std;

namespace stuff {
typedef long long ll;

void solve(int test_num) {
  int B, N;
  cin >> B >> N;
  vector<int> take(B);
  for (int i = 0; i < B; i++)
    cin >> take[i];
  ll best = ll(1e15), res;
  for (int b = 0; b < B; b++) {
    ll low = 0, high = ll(1e10), now = high;
    while (low <= high) {
      const ll mid = (low + high) >> 1;
      ll sum = 0;
      for (int i = 0; i < B; i++) {
        if (i < b)
          sum += (mid * take[b] + take[i]) / take[i];
        else if (i == b)
          sum += mid * take[b] / take[i];
        else
          sum += (mid * take[b] + take[i] - 1) / take[i];
      }
      if (sum >= N - 1) {
        now = mid * take[b];
        high = mid - 1;
      } else
        low = mid + 1;
    }
    //pln(b, now);
    if (now < best) {
      res = b + 1;
      best = now;
    }
  }
  cout << "Case #" << test_num << ": " << res << endl;
}

void solve() {
#ifdef AZN
  double start_t = clock();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
//freopen("azn.txt", "w", stderr);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
//scanf("%d", &T);
  cin >> T;
  for (int t = 1; t <= T; t++)
    solve(t);
#ifdef AZN
  cerr << "Took: " << ((clock() - start_t) / CLOCKS_PER_SEC);
#endif
}
}

int main() {
  stuff::solve();
  return 0;
}
