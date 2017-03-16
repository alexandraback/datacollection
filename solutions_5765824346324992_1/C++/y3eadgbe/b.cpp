#include <bits/stdc++.h>

#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define each(it,n) for(__typeof((n).begin()) it=(n).begin();it!=(n).end();++it)

using namespace std;

typedef long long ll;

ll B, N;
vector<ll> m;

ll calc(ll t) {
    if (t < 0) return 0;
    ll x = 0;
    rep(i, B) {
        x += t / m[i] + 1;
    }
    return x;
}

void solve() {
    cin >> B >> N;
    m = vector<ll>(B);
    rep(i, B) cin >> m[i];
    
    ll low = -1, hi = 1LL << 60LL;
    while (hi - low > 1) {
        ll mid = (low + hi) / 2;
        if (N <= calc(mid)) {
            hi = mid;
        } else {
            low = mid;
        }
    }
    N -= calc(hi - 1);

    ll ans = -1;
    rep(i, B) {
        if (hi % m[i] == 0) N--;
        if (N == 0) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    rep(i, T) {
        cout << "Case #" << i + 1 << ": "; 
        solve();
    }
    return 0;
}
