
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;

int d[1003];

int main() {
  int test_cases;
  scanf("%d", &test_cases);

  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int b, n;
    scanf("%d %d", &b, &n);
    for (int i = 0; i < b; i++) {
      scanf("%d", d + i);
    }

    int ans = -1;
    for (int i = 0; i < b; i++) {
      long long l = 0, r = 2000000000000ll / d[i];
      while (l <= r) {
        const long long m = (l + r) >> 1;
        const long long t = m * d[i];
        long long c = 0;
        for (int j = 0; j < i; j++) {
          c += (t + d[j]) / d[j];
        }
        c += m + 1;
        for (int j = i + 1; j < b; j++) {
          c += (t + d[j] - 1) / d[j];
        }

        if (c == n) {
          ans = i;
          break;
        } else if (c < n) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      if (ans >= 0) {
        break;
      }
    }

    printf("Case #%d: %d\n", test_case, ans + 1);
  }

  return 0;
}