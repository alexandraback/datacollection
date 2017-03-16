#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define debug(x) cerr << #x << "=" << x << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

void solve(int testcase) {
  debug(testcase);
  printf("Case #%d: ", testcase);
  int r1;
  int a[4][4];
  scanf("%d", &r1);
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      scanf("%d", &a[i][j]);
  int r2;
  int b[4][4];
  scanf("%d", &r2);
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      scanf("%d", &b[i][j]);
  set<int> res;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (a[r1 - 1][i] == b[r2 - 1][j])
        res.insert(a[r1 - 1][i]);
  if (res.empty())
    printf("Volunteer cheated!\n");
  else if (sz(res) > 1)
    printf("Bad magician!\n");
  else
    printf("%d\n", *res.begin());
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
    solve(t);
  return 0;
}
