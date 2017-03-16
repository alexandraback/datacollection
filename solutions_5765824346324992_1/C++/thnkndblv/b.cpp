#include "cstdio"
#include "iostream"

using namespace std;

typedef long long Long;

int m[ 1003 ];

Long foo(Long tm, int B) {
  Long ret = 0LL;

  for (int i = 0; i < B; i++) {
    ret += tm / m[i] + 1;
  }

  return ret;
}

int main() {
  int ntc;

  cin >> ntc;
  for (int tc = 1; tc <= ntc; tc++) {
    int B, N;
    scanf("%d %d", &B, &N);

    for (int i = 0; i < B; i++) scanf("%d", m + i);

    Long lo = 0LL, hi = (Long)(1e14);
    while ( lo < hi ) {
      Long mid = (lo + hi) / 2;
      Long cc = foo( mid, B );
      if ( cc < N ) lo = mid + 1;
      else hi = mid;
    }

    Long x = foo(max(lo - 1LL, 0LL), B);
    int rem = N - x;

    int ans = 0;
    for (int i = 0; i < B; i++) {
      if ( lo % m[i] == 0LL ) {
        ans = i + 1;
        rem--;
        if (rem == 0) break;
      }
    }

    printf("Case #%d: %d\n", tc, ans);
  }

  return 0;
}