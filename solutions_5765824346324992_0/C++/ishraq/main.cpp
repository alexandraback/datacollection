#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

vector<ll> get(vector<ll> t, ll md) {
    vector<ll> res(sz(t));
    FO(i,0,sz(t)) res[i] = (md+t[i]-1)/t[i];
    return res;
}

int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        ll n; int m;
        scanf("%d %lld", &m, &n);
        vector<ll> t(m);
        FO(i,0,m) scanf("%lld", &t[i]);
        ll s = 0, e = 1e15, best = 0;
        while (s <= e) {
            ll md = (s+e)/2;
            vector<ll> ng = get(t,md);
            if (accumulate(ng.begin(),ng.end(),0ll) >= n) {
                best = md;
                e = md-1;
            } else s = md+1;
        }

        vector<ll> x = get(t,best-1);
        n -= accumulate(x.begin(),x.end(),0ll);
        vector<ll> y = get(t,best);
        bool done = false;
        FO(i,0,sz(x)) if (y[i] > x[i]) {
            n--;
            if (n == 0) {
                printf("Case #%d: %d\n", Z, i+1);
                done = true;
            }
        }
        if (!done) printf("WTF\n");
    }
}

