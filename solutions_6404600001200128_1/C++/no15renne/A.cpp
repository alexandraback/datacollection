
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

const int INF = 1e9;
const int MOD = 1e9+7;

int main(void){
	int t;
    cin >> t;
    REP(tt, t){
        int n;
        cin >> n;
        vector<ll> m(n);
        REP(i, n) cin >> m[i];
        ll ans = 0, ans2 = 0;
        for(int i = 1; i < n; i++){
            if(m[i-1] > m[i]) ans += m[i-1] - m[i];
        }
        ll a = 0;
        for(int i = 1; i < n; i++){
            a = max(a, m[i-1] - m[i]);
        }
        for(int i = 1; i < n; i++){
            if(m[i-1] - a < 0) ans2 += m[i-1];
            else ans2 += a; 
        }
        cout << "Case #" << tt + 1 << ": " << ans << " " << ans2 << endl;
    }
	
	return 0;
}

