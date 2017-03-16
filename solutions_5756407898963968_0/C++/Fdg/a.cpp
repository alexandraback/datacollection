/* 
  2014.03.26 15:10
  http://codeforces.ru/gym/100289/
*/


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
  printf("Case #%d:", CS);
  int x, a;
  set<int> f[2];
  for (int it = 0; it < 2; ++it) {
    scanf("%d", &x);
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j) {
        scanf("%d", &a);
        if (i == x - 1) {
          if (it == 0) f[0].insert(a);
          else if (f[0].count(a)) f[1].insert(a);
        }
      }
  }
  if (f[1].size() == 1) printf(" %d\n", *f[1].begin());
  else if (f[1].size() > 1) printf(" Bad magician!\n");
  else printf(" Volunteer cheated!\n");
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