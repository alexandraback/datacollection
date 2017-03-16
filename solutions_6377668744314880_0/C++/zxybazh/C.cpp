#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i <=n; i++)
#define N 1111
typedef long long LL;

struct P{
    LL x, y;
    P() {}
    P(LL _x, LL _y) {x = _x; y = _y;}
    friend bool operator < (const P &a, const P &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    friend P operator - (const P &a, const P &b) {
        return P(a.x-b.x, a.y-b.y);
    }
    friend P operator + (const P &a, const P &b) {
        return P(a.x+b.x, a.y+b.y);
    }
    LL delta(const P a) { return x*a.y-a.x*y; }
} a[N], b[N], c[N];

int T, n, m, ans[N], k;

void make_convex() {
    sort(b, b + m); k = 0;
    rep(i, m) {
        while (k >= 2 && (b[i]-c[k-1]).delta(c[k-1]-c[k-2]) <= 0) --k;
        c[k++] = b[i];
    }
    int tp = k;
    for (int i = m-1; i >=0; --i) {
        while (k >= 2 && k - tp >= 1 && (b[i]-c[k-1]).delta(c[k-1]-c[k-2]) <= 0) --k;
        c[k++] = b[i];

        //rep(i, k) cout << c[i].x <<" " <<c[i].y << endl;
        //cout << "----------------------\n";

    }
    --k;
}

bool onto(P x, P a, P b) {
    return ((a-x).delta(b-x) == 0 && ((x.x >= a.x && x.x <= b.x) || (x.x >= b.x && x.x <= a.x)));
}

bool check(int x) {
    rep(i, k) if (c[i].x == a[x].x && c[i].y == a[x].y) return true;
    if (k < 2) return false;
    rep(i, k-1) if (onto(a[x], c[i], c[i+1])) return true;
    return onto(a[x], c[k-1], c[0]);
}

void solve() {
    cin >> n;
    rep(i, n) {
        cin >> a[i].x >> a[i].y;
        ans[i] = n+1;
    }
    rep(mask, (1<<n)) if (mask) {
    //int mask = 27; {
        m = 0;
        rep(i, n) if ((1<<i) & mask) {
            b[m++] = a[i];
        }
        make_convex();
        /*
        rep(i, k) cout << c[i].x <<" " <<c[i].y << endl;
        cout << "----------------------\n";
        */
        rep(i, n) if (check(i)) ans[i] = min(ans[i], n-m);
    }
    rep(i, n) cout << ans[i] << endl;
}

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.ou", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> T;
	kep(_, T) {
		cout << "Case #" << _ << ": " << endl;
		solve();
	}
}
