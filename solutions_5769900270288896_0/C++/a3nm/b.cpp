#include <stdio.h>
#include <vector>
#include <queue>

#define MAXN 1000002

using namespace std;

typedef pair<int, int> pii;

int odd(int R, int C, int N) {
  int total = 0;
  // fill the corners
  if (N <= R * C / 2 + 1)
    return 0;
  N -= R * C / 2 + 1;
  if (N <= C + R - 2)
    return 3*N; // borders (no corners)
  N -= C + R - 2;
  total += 3*(C + R - 2);
  return total + 4*N;
}

int even(int R, int C, int N) {
  int total = 0;
  // avoid the corners
  if (N <= R * C / 2)
    return 0;
  N -= R * C / 2;
  if (N <= 4)
    return 2*N; // corners
  N -= 4;
  total += 8;
  if (N <= C + R - 6)
    return total + 3*N; // borders (no corners)
  N -= C + R - 6;
  total += 3*(C + R - 6);
  return total + 4*N;
}

int ans(int R, int C, int N) {
  int total = 0;
  if (R == 1 && C == 1)
    return 0;
  if (C == 1 && R != 1)
    return ans(C, R, N);
  if (R == 1) {
    if (!(C % 2)) {
      if (N <= C/2)
        return 0;
      N -= C/2;
      if (N == 1)
        return 1;
      N -= 1;
      return 1 + 2*N;
    }
    if (N <= C/2 + 1)
      return 0;
    N -= C/2 + 1;
    // no trap
    return 2 * N;
  }
  if (!(R % 2) || !(C % 2)) {
    if (N <= R * C / 2)
      return 0;
    N -= R * C / 2;
    if (N <= 2)
      return total + 2*N; // corners
    N -= 2;
    total += 2*2;
    //printf("%d remaining, i have paid %d\n", N, total);
    if (N <= C + R - 4)
      return total + 3*N; // borders
    N -= C + R - 4;
    total += 3*(C + R - 4);
    return total + 4*N; // other
  }
  // ok, even is tricky
  return min(odd(R, C, N), even(R, C, N));
}

int main() {
  int T;
  scanf("%d", &T);
  for (int ncase = 0; ncase < T; ncase++) {
    int R, C, N;
    scanf("%d%d%d", &R, &C, &N);
    printf("Case #%d: %d\n", ncase + 1, ans(R, C, N));
  }
  return 0;
}
