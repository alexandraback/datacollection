#include <cstdio>
#include <cassert>

const int MAXN = 1111;

int n;
int m[MAXN];

void Init() {
  assert(scanf("%d", &n) == 1);
  for (int i = 0; i < n; ++i) {
    assert(scanf("%d", m + i) == 1);
  }
}

void Work() {
  int ans1 = 0;
  for (int i = 1; i < n; ++i) {
    if (m[i] < m[i - 1]) {
      ans1 += m[i - 1] - m[i];
    }
  }

  int rate = 0;
  for (int i = 1; i < n; ++i)
    if (m[i - 1] - m[i] > rate)
      rate = m[i - 1] - m[i];
  int ans2 = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (rate >= m[i])
      ans2 += m[i];
    else
      ans2 += rate;
  }
  printf("%d %d\n", ans1, ans2);
}

int main() {
  int cases;
  assert(scanf("%d", &cases) == 1);
  for (int i = 1; i <= cases; ++i) {
    printf("Case #%d: ", i);
    Init();
    Work();
  }
  return 0;
}
