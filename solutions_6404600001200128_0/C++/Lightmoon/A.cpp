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

using namespace std;

int n;
int a[MAXN];

PII solve() {
    int res1 = 0, res2 = 0;
    For(i,1,n-1) res1 += max(0, a[i]-a[i+1]);
    int maxx = 0;
    For(i,1,n-1) maxx = max(maxx, a[i]-a[i+1]);
    For(i,1,n-1) res2 += min(a[i], maxx);
    return PII(res1, res2);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    For(test,1,ntest) {
        cin >> n;
        For(i,1,n) cin >> a[i];
        PII res = solve();
        cout << "Case " << "#" << test << ": " << res.X << ' ' << res.Y << endl;
    }
    return 0;
}

