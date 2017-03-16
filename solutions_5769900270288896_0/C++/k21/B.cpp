#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int eval(int R, int C, const vector<bool>& occ) {
  int sc = 0;
  REP(y,R) REP(x,C) {
    if (!occ[y*C+x]) continue;
    if (y && occ[(y-1)*C+x]) ++sc;
    if (x && occ[y*C+x-1]) ++sc;
  }
  return sc;
}

int solve(int R, int C, int N) {
  vector<bool> occ;
  REP(i,R*C-N) occ.push_back(false);
  REP(i,N) occ.push_back(true);
  int best = INF;
  do {
    best = min(best, eval(R, C, occ));
  } while (next_permutation(occ.begin(), occ.end()));
  return best;
}

int main() {
  int T;
  scanf("%d", &T);
  REP(t,T) {
    int R, C, N;
    scanf("%d%d%d", &R, &C, &N);
    printf("Case #%d: %d\n", t+1, solve(R, C, N));
  }
  return 0;
}
