#include <cstdio>
#include <algorithm>

int mush[10002];

void tcase(int t) {
  int N; scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", &mush[i]);

  int first = 0;
  for (int i = 1; i < N; i++) {
    if (mush[i] < mush[i - 1]) {
      first += mush[i-1] - mush[i];
    }
  }

  int max = 0;
  for (int i = 1; i < N; i++) {
    max = std::max(max, mush[i-1] - mush[i]);
  }

  int second = 0;
  double rate = max / 10.0;
  int cur = mush[0];
  for (int i = 1; i < N; i++) {
    if (cur <= 10 * rate) {
      second += cur;
    } else {
      second += (int)(10 * rate);
    }
    cur = mush[i];
  }

  printf("Case #%d: %d %d\n", t, first, second);
}

int main() {
  int T; scanf("%d", &T);
  for (int t = 1; t <= T; t++)
    tcase(t);
}
