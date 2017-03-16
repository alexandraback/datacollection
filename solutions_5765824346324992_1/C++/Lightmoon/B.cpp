#include <bits/stdc++.h>

#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Ford(i,a,b) for (int i = (a); i >= (b); i--)
#define Rep(i,a) for (int i = 0; i < (a); i++)
#define Repd(i,a) for (int i = (int)(a) - 1; i >=0; i--)
#define PI (acos(0.0) * 2)
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define PII pair<int, int>
#define PIII pair<PII, int>
#define VI vector<int>
#define sz(a) ((int)a.size())
#define oo 1000000000
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(a,u,v) {cout << #a << " = "; For(_,u,v) cout << a[_] << ' '; cout << endl;}
#define MAXN 100111
#define LL long long

using namespace std;

int a[MAXN], n, b;

bool ok(LL t) {
    LL total = 0;
    For(i,1,b) total += t/a[i] + 1;
    return total >=n;
}
int solve() {
    LL l = 0, r = 1000000000000LL, lm = 0;
    while (l <= r) {
        LL m = (l+r)/2;
        if (ok(m)) {
            lm = m;
            r = m-1;
        } else {
            l=m+1;
        }
    }
    LL total = 0;
    For(i,1,b) total += lm/a[i];
    vector<PII> v;
    For(i,1,b) {
        int x = lm%a[i];
        if (x==0) {
            x = 1000000;
        }
        v.PB(MP(x, i));
    }
    sort(v.begin(), v.end());
    return v[n-total-1].Y;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    For(test,1,ntest) {
        cin >> b >> n;
        For(i,1,b) cin >> a[i];
        int res = solve();
        cout << "Case " << "#" << test << ": " << res << endl;
    }
    return 0;
}
