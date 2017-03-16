#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define FORIT(it, obj) for(__typeof(obj.begin()) it=obj.begin();it!=obj.end();++it)
#define REP(i, N) for(int i = 0; i < N; i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define mp make_pair
#define pb push_back
#define bpc __builtin_popcount
typedef pair<int,int> pii;
typedef long long ll;
int m[1500];

int main() {
  //freopen("c.in", "r", stdin);
  int T; scanf("%d", &T);
  for(int casenum = 1; casenum <= T; casenum++) {
    printf("Case #%d: ", casenum);
    int N; scanf("%d", &N);
    REP(i, N) scanf("%d", &m[i]);
    int ans1 = 0;
    FOR(i, 1, N-1) ans1 += max(0, m[i-1] - m[i]);
    printf("%d ", ans1);
    int rate = 0;
    FOR(i, 1, N-1) rate = max(rate, m[i-1] - m[i]);

    int ans2 = 0;
    FOR(i, 1, N-1) {
      ans2 += min(m[i-1], rate);
    }
    printf("%d\n", ans2);
  }


  return 0;
}
