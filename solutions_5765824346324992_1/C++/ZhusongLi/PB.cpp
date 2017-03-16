#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

ll N,B;
vector<ll> M;

ll serve(ll t) {
    ll i,j,k,n = 0;
    for (i = 0;i < B;i++) {
        n += t / M[i];
        if (t % M[i] != 0) n++;
    }
    return n;
}

ll solve() {
    if (N <= B) return N;
    ll ts = 0,tb = 1E15,tm,i,j,k,n;
    while (ts + 1 < tb) {
        tm = (ts + tb) / 2;
        n = serve(tm);
        if (n >= N) tb = tm;
        else ts = tm;
    }
    while (serve(ts) < n) ts++;
    ts--;
    n = serve(ts);
    ll m = N - n;
    for (i = 0;i < B;i++) {
        if (ts % M[i] == 0) {
            m--;
            if (m == 0) return i + 1;
        }
    }
    ts++;
    for (i = 0;i < B;i++) {
        if (ts % M[i] == 0) {
            m--;
            if (m == 0) return i + 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("B-small-attempt0.in.txt","r",stdin);
    freopen("B-large.in.txt","r",stdin);
    freopen("output","w",stdout);
    ll i,j,k,T,x,y,z,res;
    cin >> T;
    for (x = 1;x <= T;x++) {
        cin >> B >> N;
        M.resize(B,0);
        for (i = 0;i < B;i++) cin >> M[i];
        res = solve();
        cout << "Case #" << x << ": " << res << endl;
    }
    
    return 0;
}
