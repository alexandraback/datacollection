#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int b;
long long n;
long long m[1042];

long long started(long long x) {
  if (x < 0) return 0;

  long long st = 0;
  for (int i = 0; i < b; ++i) {
    st += x/m[i] + 1;
  }
  return st;
}

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cin >> b >> n;
    for (int i = 0; i < b; ++i) scanf("%Ld", &m[i]);

    long long maxSm = -1, minGteq = 100000LL * 1000000000LL + 42LL;

    while (maxSm + 1 < minGteq) {
      long long mid = maxSm + (minGteq - maxSm)/2;
      if (started(mid) >= n) minGteq = mid;
      else maxSm = mid;
    }

    //cout << minGteq << endl;

    long long beforeMe = n - started(minGteq-1);

    for (int i = 0; i < b; ++i) {
      if (minGteq % m[i] == 0) {
        if (--beforeMe == 0) {
          cout << "Case #" << tt << ": " << (i+1) << endl;
          break;
        }
      }
    }
  }
}
