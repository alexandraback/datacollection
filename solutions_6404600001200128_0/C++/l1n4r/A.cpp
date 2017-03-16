
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

int m[10004];

int main() {
  int test_cases;
  scanf("%d", &test_cases);

  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", m + i);
    }

    int ans1 = 0, t = 0;
    for (int i = 1; i < n; i++) {
      ans1 += max(0, m[i - 1] - m[i]);
      t = max(t, m[i - 1] - m[i]);
    }

    int ans2 = 0;
    for (int i = 1; i < n; i++) {
      ans2 += min(m[i - 1], t);
    }

    printf("Case #%d: %d %d\n", test_case, ans1, ans2);
  }

  return 0;
}