#include <stdio.h>
#include <math.h>

long M[1001], B, N;

long count(long m, int v) {
  long res = 0;
  for (int i = 0; i < B; i++) {
    res += m / M[i];
    if ((m % M[i] != 0)) res++;
  }
  return res;
}

int main(void) {
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    scanf("%ld %ld", &B, &N);
    for (int i = 0; i < B; i++) scanf("%ld", &M[i]);

    long a = 0, b = 1e15; // solution must be in [a,b)
    while (b - a > 1) {
      long mid = (a + b) / 2;
      long N_ = count(mid, 1);
      if (N < N_) {
        b = mid;
      } else if (N > N_) {
        a = mid;
      } else {
        b--;
      }
    }

    //*
    long cnt = count(a, 0);

    /*
    long count = 0;
    for (int i = 0; i < B; i++) {
      count += r / M[i];
      if (r != M[i]) count++;
    }
    */

    int res;
    for (res = 0; res < B; res++) {
      if (cnt + (res + 1) >= N && a % M[res] == 0) break;
    }
    res++;

    /*
    long res = (N - cnt) % B;
    if (res == 0) res = B;
    */

 // int res = (N - count) % B;
 // if (res == 0) res = B;
    //*/

    /*
    printf("[");
    for (int i = 0; i < B; i++) printf(" %ld", M[i]);
    printf(" ] %ld: ", N);
    printf("%ld %ld → %ld → %ld\n", a, b, cnt, res);
    */

    printf("Case #%d: %d\n", t, res);
  }
}
