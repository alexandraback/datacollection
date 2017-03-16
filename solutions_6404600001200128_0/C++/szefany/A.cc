#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1111;

int a[N], n;

int solve_1() {
  int result = 0;
  for (int i = 2; i <= n; ++ i) {
    if (a[i] < a[i - 1]) {
      result += a[i - 1] - a[i];
    }
  }
  return result;
}

int solve_2() {
  int result = 1e9;
  for (int i = 0; i < 10000; ++ i) {
    int current = 0;
    for (int j = 2; j <= n; ++ j) {
      if (a[j - 1] - i > a[j]) {
        current = -1;
        break;
      } else {
        current += std::min(a[j - 1], i);
      }
    }
    if (current == -1) {
      continue;
    }
    if (current < result) {
      result = current;
    }
  }
  return result;
}

int main() {
  int test;
  scanf("%d", &test);
  for (int t = 1; t <= test; ++ t) {
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
      scanf("%d", a + i);
    }
    printf("Case #%d: %d %d\n", t, solve_1(), solve_2());
  }
  return 0;
}
