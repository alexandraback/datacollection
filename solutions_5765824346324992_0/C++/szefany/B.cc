#include <cstdio>
#include <cstring>

const int N = 1111;

int a[N];

long long Solve(long long middle, int b) {
  long long sum = 0;
  for (int i = 1; i <= b; ++ i) {
    sum += (middle + a[i] - 1) / a[i];
  }
  return sum;
}

int main() {
  int test;
  scanf("%d", &test);
  for (int t = 1; t <= test; ++ t) {
    long long n;
    int b;
    scanf("%d %lld", &b, &n);
    for (int i = 1; i <= b; ++ i) {
      scanf("%d", a + i);
    }
    long long lower = 0, upper = n * 1e6;
    while (lower < upper) {
      long long middle = (lower + upper + 1) >> 1;
      long long sum = Solve(middle, b);
      if (sum < n) {
        lower = middle;
      } else {
        upper = middle - 1;
      }
    }

    printf("Case #%d: ", t);
    long long number = n - Solve(lower, b);
    for (int i = 1; i <= b; ++ i) {
      if (lower % a[i] == 0) {
        number --;
        if (number == 0) {
          printf("%d\n", i);
          break;
        }
      }
    }
  }
  return 0;
}
