#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    //puts("");
    solve();
  }
}

void solve() {
  int nums[100];
  MEMSET(nums, 0);
  REP(i, 2) {
    int row;
    scanf("%d", &row);
    row--;
    REP(y, 4) {
      REP(x, 4) {
        int v;
        scanf("%d", &v);
        v--;
        if (y == row) { nums[v]++; }
      }
    }
  }
  vector<int> candidate;
  REP(i, 16) {
    if (nums[i] == 2) { candidate.push_back(i); }
  }
  if (candidate.size() == 0) {
    puts("Volunteer cheated!");
  } else if (candidate.size() == 1) {
    printf("%d\n", candidate[0] + 1);
  } else {
    puts("Bad magician!");
  }
}
