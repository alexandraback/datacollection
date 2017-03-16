#include <cstdio>
#include <vector>

using namespace std;

int main() {
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int T = 0;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    vector<int> v;
    int B = 0;
    int N = 0;
    long long l = 0;
    long long r = 1000000000000000ll;
    long long c = 0;
    scanf("%d %d", &B, &N);
    v.resize(B);
    for (int j = 0; j < B; ++j) {
      int t = 0;
      scanf("%d", &t);
      v[j] = t;
    }
    while (l + 1 < r) {
      long long m = (l + r) >> 1;
      c = 0;
      for (int j = 0; j < B; ++j) {
        c += (m + v[j] - 1) / v[j];
      }
      if (c >= N) {
        r = m;
      } else {
        l = m;
      }
    }
    c = 0;
    for (int j = 0; j < B; ++j) {
      c += (l + v[j] - 1) / v[j];
    }
    c = N - c;
    for (int j = 0; j < B; ++j) {
      if (l % v[j] == 0) {
        c--;
      }
      if (c == 0) {
        printf("Case #%d: %d\n", i + 1, j + 1);
        break;
      }
    }
  }


  return 0;
}
