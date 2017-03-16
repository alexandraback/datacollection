#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

#define FOR(i,l,r)  for(int i=(l); i<=(r); ++i)
#define REP(i,r)    for(int i=0; i<(r); ++i)
#define DWN(i,r,l)  for(int i=(r);i>=(l);--i)

#define pb push_back

typedef long long ll;
typedef pair<int, int>pii;


int main() {
    freopen("BBB", "r", stdin);
    freopen("out", "w", stdout);
    int casnum, casid = 0;
    cin >> casnum;
    while(casnum--) {
        int w, h, n;
        int ans = 1e9;
        cin >> w >> h >> n;
        REP(pos, 1<<(w * h)) {
            int num = 0;
            REP(i, w * h)   if(pos & (1<<i))    ++num;
            if(num != n)    continue;

            int ret = 0;
            FOR(i, 1, w - 1) {
                REP(j, h)
                    if((pos & (1 << (i*h + j))) && (pos&( 1 << ((i-1) * h + j ))) )   ++ret;
            }

            int tmp = pos;

            REP(i, w)
                FOR(j, 1, h-1)
                    if((pos & (1<<(i*h + j))) && (pos&(1<<(i*h + j - 1)))  )  ++ret;
            ans = min(ans, ret);
        }
        printf("Case #%d: %d\n", ++casid, ans);
    }
    return 0;
}

