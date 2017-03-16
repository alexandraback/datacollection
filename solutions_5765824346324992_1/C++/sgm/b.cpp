#include <cstdio>

using namespace std;

int T, B;
long long N, M[1005];

long long nth(long long m) {
  long long x = 0;
  for(int i = 0; i < B; i++) {
    x += (m - 1) / M[i] + 1;
  }
  return x;
}

int search(long long l, long long r) {
  long long m = (l + r) / 2;
  long long th0 = nth(m), th1 = nth(m + 1);
  if(th0 < N && N <= th1) {
    int th = N - th0;
    int t = 0;
    for(int i = 0; i < B; i++) {
      if(m % M[i] == 0) {
        t++;
        if(t == th) return i;
      }
    }
    return -1;
  }else if(th1 < N) {
    return search(m + 1, r);
  }else {
    return search(l, m);
  }
}

int main(void) {
  scanf("%d", &T);
  for(int t = 1; t <= T; t++) {
    scanf("%d%lld", &B, &N);
    long long MM = 0;
    for(int i = 0; i < B; i++) {
      scanf("%lld", &M[i]);
      if(M[i] > MM) MM = M[i];
    }
    int x = search(0, N * MM);
    printf("Case #%d: %d\n", t, x + 1);
  }
  return 0;
}
