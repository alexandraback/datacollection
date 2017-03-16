#include <cstdio>

#include <algorithm>

using namespace std;

const int maxn = 1000000;

int n;
int pieces[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &pieces[i]);
  }

  int ans1 = 0, ans2 = 0;

  int max_rate = 0;

  for (int i = 1; i < n; i++) {
    int last = pieces[i - 1];
    int curr = pieces[i];
    if (last > curr) {
      ans1 += last - curr;

      max_rate = max(max_rate, last - curr);
    }
  }

  for (int i = 1; i < n; i++) {
    int last = pieces[i - 1];
    ans2 += min(last, max_rate);
  }
  printf("%d %d\n", ans1, ans2);
}

int main() {
  int tt, t;
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    printf("Case #%d: ", t);

    solve();
  }

  return 0;
}

