#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <cstring>

#define SIZE(s) ((int)((s).size()))
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)

using namespace std;

int R, C, N, T;

int main(void) {
  cin >> T;
  REP(t, T) {
    cin >> R >> C >> N;
    int best = 4*R*C;
    vector<vector<int> > V(R, vector<int>(C, 0));
    int M = R * C;
    REP(i, (1<<M)) {
      int p = 0;
      REP(j, M) {
        if (i & (1<<j)) V[j / C][j % C] = 1;
        else V[j / C][j % C] = 0;
      }

      REP(j,R) REP(k,C) p += V[j][k];
      if (p != N) continue;

      p = 0;
      REP(j,R) {
        REP(k, C-1) {
          if (V[j][k] == 1 && V[j][k+1] == 1) ++p;
        }
      }
      REP(j,C)
        REP(k, R-1) {
          if (V[k][j] == 1 && V[k+1][j] == 1) ++p;
        }
      best = min(best, p);
    }
    cout << "Case #" << (t+1) << ": " << best << endl;
  }
  return 0;
}
