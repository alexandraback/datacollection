#include <stdio.h>

#include <algorithm>
#include <vector>


typedef long long lnt;


lnt Cut(const std::vector<int> &m, lnt t) {
  lnt ret = 0;
  for (int i = 0, i_end = m.size(); i < i_end; ++i) {
    ret += t / m[i] + 1;
  }
  return ret;
}


int main() {
  int zzz, z;
  for (scanf("%d", &zzz), z = 1; z <= zzz; ++z) {
    int b, q;
    scanf("%d %d", &b, &q);

    int mx = 0;
    std::vector<int> m(b);
    for (int i = 0; i < b; ++i) {
      scanf("%d", &(m[i]));
      mx = std::max(mx, m[i]);
    }

    if (q <= b) {
      printf("Case #%d: %d\n", z, q);
      continue;
    }

    lnt t_min = 0, t_max = static_cast<lnt>(mx) * q + 10;
    while (t_min < t_max) {
      lnt mid = (t_min + t_max) / 2;
      if (Cut(m, mid) < q) {
        t_min = mid + 1;
      } else {
        t_max = mid;
      }
    }
    lnt index = q - Cut(m, t_min - 1);
    for (int i = 0, id = 0; i < b; ++i) {
      if (t_min % m[i] != 0) {
        continue;
      }
      ++id;
      if (id == index) {
        printf("Case #%d: %d\n", z, i + 1);
        break;
      }
    }
  }
  return 0;
}
