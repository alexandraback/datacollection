#include <cstdio>
#include <vector>

using namespace std;

int main() {
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int T = 0;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    vector<int> v;
    int N = 0;
    int ans1 = 0;
    int ans2 = 0;
    int rate = 0;
    scanf("%d", &N);
    v.resize(N);
    for (int j = 0; j < N; ++j) {
      int t = 0;
      scanf("%d", &t);
      v[j] = t;
    }
    for (int j = 1; j < N; ++j) {
      ans1 += max(0, v[j - 1] - v[j]);
      rate = max(rate, v[j - 1] - v[j]);
    }
    for (int j = 1; j < N; ++j) {
      ans2 += min(v[j - 1], rate);
    }
    printf("Case #%d: %d %d\n", i + 1, ans1, ans2);
  }


  return 0;
}
