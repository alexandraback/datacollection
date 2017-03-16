#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define rep(i,n) FOR(i,0,n)
#define CL(a,v) memset((a),(v),sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;

/*** TEMPLATE CODE ENDS HERE */

typedef pair<char, int> pci;

string s[111];
vector<pci> stat[111];

void solve(int T) {
    
    int N;
    cin >> N;
    rep(i,N) cin >> s[i];
    
    rep(k,N) {
        
        vector<pci> &sa = stat[k];
        string &a = s[k];

        sa.clear();
        
        rep(i,(int)a.size()) {
            if(!i || sa.back().X != s[k][i]) {
                sa.pb(mp(a[i],0));
            }
            sa.back().Y ++;
        }
    }
    
    bool possible = true;
    
    FOR(i,1,N) {
        int n = (int)stat[0].size();
        int m = (int)stat[i].size();
        
        possible &= m==n;

        rep(j,min(n,m)) possible &= stat[0][j].X==stat[i][j].X;
    }
    
    if(!possible) {
        cout << "Case #" << T << ": Fegla Won" << endl;
        return;
    }
    
    int M = (int)stat[0].size();
    int cnt = 0;
    
    rep(j,M) {
        int best = INF;
        rep(v,111) {
            int need = 0;
            rep(i,N) need += abs(v - stat[i][j].Y);
            best = min(best, need);
        }
        cnt += best;
    }
    
    cout << "Case #" << T << ": " << cnt << endl;
}

int main() {
#ifdef LOCAL_HOST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    FOR(t,1,T+1) solve(t);
    
    return 0;
}
