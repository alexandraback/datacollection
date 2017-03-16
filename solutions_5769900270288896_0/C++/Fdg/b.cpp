#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int ans = 1e+9;
  for (int mask = 0; mask < (1<< (n * m)); ++mask) {
    int arr[25][25] = {0}, cur = mask, cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        arr[i][j] = cur & 1, cur >>= 1, cnt += arr[i][j];
    }
    if (cnt != k) continue;
    cur = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j + 1 < m; ++j)
        if (arr[i][j] && arr[i][j + 1]) ++cur;
    for (int i = 0; i + 1 < n; ++i)
      for (int j = 0; j < m; ++j)
        if (arr[i][j] && arr[i + 1][j]) ++cur;
    ans = min(ans, cur);
  }
  printf("%d\n", ans);
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}