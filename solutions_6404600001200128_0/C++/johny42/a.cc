#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    long long m[10042];

    long long res1 = 0, rate = -1;

    for (int i = 0; i < n; ++i) {
      scanf("%Ld", &m[i]);
      if (i) {

        if (m[i] < m[i-1]) {
          int d = m[i-1] - m[i];
          res1 += d;
          if (d > rate) rate = d;
        }

      }
    }

    long long res2 = 0;

    if (rate != -1) {
      for (int i = 0; i < n-1; ++i) {
        res2 += min(m[i], rate);
      }
    }

    cout << "Case #" << tt << ": " << res1 << " " << res2 << endl;
  }
}
