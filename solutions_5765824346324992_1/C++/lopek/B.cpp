#include <cstdio>
#include <algorithm>
#include <assert.h>
using namespace std;

long long foo(const vector<int>& B, int n) {
  int b = B.size();
  long long tlo = 0, thi = 100000000000000ll;
  while (tlo < thi) {
    long long ts = (tlo + thi) / 2ll;
    long long curn = 0;
    for (int i = 0; i < b; i++) {
      curn += ts / B[i] + 1ll;
    }

    if (curn < n) {
      tlo = ts + 1;
    } else {
      thi = ts;
    }
  }
  
  return tlo;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int b, n;
    scanf("%d %d", &b, &n);
    vector<int> B(b);
    for (int i = 0; i < b; i++) {
      scanf("%d", &B[i]);
    }

    long long nt = foo(B, n);

    int mlo = max(1, n - 1000), mhi = n;
    while (mlo < mhi) {
      int ms = (mlo + mhi) / 2;
      long long mt = foo(B, ms);
      if (mt < nt) {
        mlo = ms + 1;
      } else {
        mhi = ms;
      }
    }

    int bef = n - mhi;
    for (int i = 0; i < b; i++) {
      if (nt % B[i] == 0) {
        if (bef == 0) {
          printf("Case #%d: %d\n", t, i + 1);
          break;
        }
        bef--;
      }
    }
  }
  return 0;
}
