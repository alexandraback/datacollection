#include <cstdio>

typedef long long Int64;

const int maxb = 10000;

int cost[maxb];
int b, n;

void solve() {
  scanf("%d %d", &b, &n);

  for (int i = 0; i < b; i++) {
    scanf("%d", &cost[i]);
  }

  Int64 lower = 0, upper = static_cast<Int64>(cost[0]) * n;

  while (lower < upper) {
    Int64 mid = (lower + upper + 1) / 2;

    Int64 sum = 0;
    for (int i = 0; i < b; i++) {
      sum += (mid - 1) / cost[i] + 1;
    }

    if (sum < n) {
      lower = mid;
    } else {
      upper = mid - 1;
    }
  }

  /// DEBUG ///
  // printf("lower = %lld\n", lower);

  Int64 curr_sum = 0;
  for (int i = 0; i < b; i++) {
    curr_sum += (lower - 1) / cost[i] + 1;
  }

  int count = n - curr_sum;

  for (int i = 0; i < b; i++) {
    if (lower % cost[i] == 0) {
      count--;
      if (count == 0) {
        printf("%d\n", i + 1);
        return;
      }
    }
  }
}

int main() {
  int tt, t;
  scanf("%d", &tt);
  for (t = 1; t <= tt; t++) {
    printf("Case #%d: ", t);
    solve();
  }

  return 0;
}

