/*
 * 
 * File:   pAMagicTrick.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Apr 11, 2014, 7:00:59 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

namespace pAMagicTrick {

void solve(int test_num) {
  int A, B, row[17][2];
  cin >> A;
  for (int r = 1; r <= 4; r++) {
    for (int c = 1, x; c <= 4; c++) {
      cin >> x;
      row[x][0] = r;
    }
  }
  cin >> B;
  for (int r = 1; r <= 4; r++) {
    for (int c = 1, x; c <= 4; c++) {
      cin >> x;
      row[x][1] = r;
    }
  }
  int res = -1, cnt = 0;
  for (int i = 1; i <= 16; i++) {
    if (row[i][0] == A && row[i][1] == B) {
      res = i;
      cnt++;
    }
  }
  printf("Case #%d: ", test_num);
  if (cnt == 0)
    puts("Volunteer cheated!");
  else if (cnt > 1)
    puts("Bad magician!");
  else
    printf("%d\n", res);
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  pAMagicTrick::solve();
  return 0;
}
