#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <climits>

#define pb push_back
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)
#define FORD(i,a,b) for(ll i=ll(b)-1; i>=(a); --i)
#define all(c) begin(c),end(c)

using namespace std;
using ll = long long;

int main() {
    ll tc;
    cin >> tc;
    FOR(i,0,tc) {
        ll R, C; cin >> R >> C;
        ll N; cin >> N;
        ll opt = LLONG_MAX;
        FOR(i,0,1<<(R*C)) {
            if(__builtin_popcount(i) != N) continue;
            ll count = 0;
            FOR(y,0,R) FOR(x,0,C) {
                ll cur = 1<<(y*C+x);
                if(y != R-1 && (cur & i) && ((cur << C) & i)) ++ count;
                if(x != C-1 && (cur & i) && ((cur << 1) & i)) ++ count;
            }
            opt = min(opt,count);
        }
        cout << "Case #" << i+1 << ": " << opt << endl;
    }
}
