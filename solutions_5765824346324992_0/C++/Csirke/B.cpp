#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

lglg started(const vector<int>& m, lglg time) {
  lglg ret = m.size();

  for(int sp : m) {
    ret += lglg(time) / lglg(sp);
  }

  return ret;
}

int main()
{
  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d: ", t+1);

    int b;
    lglg n;

    scanf("%d %I64d", &b, &n);

    vector<int> m(b);

    for(int i = 0; i < b; ++i) {
      scanf("%d", &m[i]);
    }

    if(b >= n) {
      printf("%I64d\n", n);
      continue;
    }

    lglg t_max = 1;
    while(started(m, t_max) < n) {
      t_max *= 2;
    }

    lglg t_min = max(t_max / 2, 1ll);
    while(t_min + 1 < t_max) {
      lglg t_mid = (t_min + t_max) / 2ll;
      if(started(m, t_mid) < n) {
        t_min = t_mid;
      } else {
        t_max = t_mid;
      }
    }

    lglg k = n - started(m, t_max-1);

    for(int i = 0; i < b; ++i) {
      if(t_max % lglg(m[i]) == 0) {
        --k;
        if(k == 0) {
          printf("%d\n", i+1);
          break;
        }
      }
    }
  }

  return 0;
}
