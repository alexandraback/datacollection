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
int M[1500];
int t[1500];
const int MAX = 50 * 1000 * 1000;
int mem[26][26][26][26][26];
int dp[MAX];

int main() {
  //freopen("c.in", "r", stdin);
  int T; scanf("%d", &T);
  for(int casenum = 1; casenum <= T; casenum++) {
    printf("Case #%d: ", casenum);
    int B, N; scanf("%d%d", &B, &N);
    REP(i, B) {
      scanf("%d", &M[i]);
    }
    memset(t, 0, sizeof t);
    memset(mem, -1, sizeof mem);
    int mod = MAX;
    int start = 0;
    REP(i, N) {
      //      printf("(%d, %d, %d): ", t[0], t[1], t[2]);
      int &ref = mem[t[0]][t[1]][t[2]][t[3]][t[4]];
      if (ref != -1) {
	mod = i - ref;
	start = ref;
	//	printf("mod = %d, start = %d\n", mod, start);
	break;
      }
      ref = i;

      pii mm(1 << 30, -1);
      REP(j, B) mm = min(mm, pii(t[j], j));
      if (mm.first != 0) {
	REP(j, B) t[j] = max(0, t[j] - mm.first);
      }
      t[mm.second] += M[mm.second];

      dp[i] = mm.second + 1;

    }
    printf("%d\n", dp[(N - 1 - start) % mod + start]);

    //    printf("\nans: %d\n", ans);
  }
  return 0;
}
