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
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
typedef pair<int, pair<int,int> > TRI;
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

int rataj(const vector< vector<int> > &tenants, int r, int c) {
    int R = tenants.size(), C = tenants[0].size();
    int pocet = 0;
    REP(d,4) {
        int nr = r+dr[d], nc = c+dc[d];
        if (nr<0 || nr>=R || nc<0 || nc>=C) continue;
        pocet += tenants[nr][nc];
    }
    return pocet;
}

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        int R, C, N; cin >> R >> C >> N;
        int maxzero = (R*C + 1) / 2;
        if (N <= maxzero) {
            cout << "Case #" << t << ": 0" << endl;
            continue;
        }
        vector< vector<int> > tenants(R, vector<int>(C,1));
        set<TRI> candidates;
        REP(r,R) REP(c,C) candidates.insert( TRI( rataj(tenants,r,c), PII(r,c) ) );
        int answer = R*(C-1) + (R-1)*C;

        bool is_magic = (R >= 3) && (C >= 3) && (R%2 == 1) && (C%2 == 1) && (maxzero+1 == N);

        while (N < R*C) {
            ++N;
            auto kto = *candidates.rbegin();
            answer -= kto.first;
            int r = kto.second.first, c = kto.second.second;
            REP(d,4) {
                int nr = r+dr[d], nc = c+dc[d];
                if (nr<0 || nr>=R || nc<0 || nc>=C) continue;
                if (tenants[nr][nc]) candidates.erase( TRI( rataj(tenants,nr,nc), PII(nr,nc) ) );
            }
            candidates.erase(kto);
            tenants[r][c] = 0;
            REP(d,4) {
                int nr = r+dr[d], nc = c+dc[d];
                if (nr<0 || nr>=R || nc<0 || nc>=C) continue;
                if (tenants[nr][nc]) candidates.insert( TRI( rataj(tenants,nr,nc), PII(nr,nc) ) );
            }
        }
       
        if (is_magic) --answer;

        cout << "Case #" << t << ": " << answer << endl;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
