// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        int R, C, N; cin >> R >> C >> N;
        int best = 4*R*C;
        for (int ako=0; ako<(1<<(R*C)); ++ako) {
            if (__builtin_popcount(ako) != N) continue;
            vector< vector<int> > B(R, vector<int>(C,0));
            REP(r,R) REP(c,C) B[r][c] = (ako >> (r*C+c)) & 1;
            int toto = 0;
            REP(r,R) REP(c,C-1) if (B[r][c] && B[r][c+1]) ++toto;
            REP(r,R-1) REP(c,C) if (B[r][c] && B[r+1][c]) ++toto;
            best = min( best, toto );
        }
        cout << "Case #" << t << ": " << best << endl;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
