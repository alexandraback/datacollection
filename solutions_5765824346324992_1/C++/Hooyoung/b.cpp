#include <cstdio>

int M[1000];

long nfree(long c, int B)
{
  if (c < 0)
    return 0;
  long out = 0;
  for (int i = 0; i < B; ++i) {
    out += 1 + c/M[i];
  }
  return out;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int B, N;
    scanf("%d%d", &B, &N);
    for (int i = 0; i < B; ++i)
      scanf("%d", &M[i]);
    long a = 0, b = 1000000000L * 100000L + 1;
    while (a < b) {
      long c = a + (b-a)/2;
      //fprintf(stderr, ">%ld\n", c);
      long n = nfree(c, B);
      if (n < N) {
        a = c + 1;
      } else {
        long m = nfree(c-1, B);
        if (m < N) {
          a = c;
          break;
        } else {
          b = c - 1;
        }
      }
    }
    long k = N - nfree(a - 1, B);
    //fprintf(stderr, "time is %ld\n", a);
    if (!k) {
      fprintf(stderr, "you dumb\n");
      return 1;
    }
    int i;
    for (i = 0; i < B; ++i)
      if (a % M[i] == 0) {
        --k;
        if (!k)
          break;
      }
    if (i == B) {
      fprintf(stderr, "idiot\n");
      return 1;
    }
    printf("Case #%d: %d\n", t, i+1);
  }
  return 0;
}

