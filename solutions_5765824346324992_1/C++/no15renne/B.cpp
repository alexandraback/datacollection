
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
        ll b, n;
        cin >> b >> n;
        vector<ll> m(b);
        REP(i, b) cin >> m[i];
        ll l = -1, r = (1LL<<60);
        while(r - l  > 1LL){
            ll med = (r + l) / 2;
            ll k = 0;
            REP(i, b){
                k += med / m[i] + 1;
            }
            if(k >= n) r = med;
            else l = med; 
        }
        ll k = 0;
        vector<ll> rm(b);
        REP(i, b){
            rm[i] = (r-1) / m[i] + 1;
            k += (r - 1) / m[i] + 1;
        }
        //cout  << r << endl;
        //cout << k << endl;
        k = n - k;
        int ans = 1;
        REP(i, b){
            if(rm[i] != (r / m[i]) + 1) k--;
            if(!k){
                ans = i + 1;
                break;
            }
        }


        cout << "Case #" << tt + 1 << ": ";
        cout << ans << endl;
    }
	
	return 0;
}

