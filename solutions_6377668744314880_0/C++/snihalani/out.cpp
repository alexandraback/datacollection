#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
typedef long double ld;

const ld eps = 1e-9;

struct P { ll x, y; };

ll cross(P a, P b, P c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<P> a, b;
vector<pair<double, int> > p;
int n;

bool f(P A, P B, int x) {
    P C = a[p[x].second];
    return cross(A, B, C) <= 0;
}

int solve(int pos) {
    if (n <= 3) return 0;
    p.clear();
    for (int i = 0; i < n; ++i) {
        if (i == pos) continue;
        ld ang = atan2(a[i].y - a[pos].y, a[i].x - a[pos].x);
        p.push_back(make_pair(ang, i));
    }
    sort(p.begin(), p.end());
    //for (int i = 0; i < n-1; ++i) cout << p[i].first << " " << p[i].second << endl;
    for (int i = 0; i < n-1; ++i) p.push_back(p[i]);
    int res = 100000;
    P A = a[pos];
    //cout << "pos " << pos << endl;
    for (int i = 0; i < n-1; ++i) {
        int l = i, r = i+n-1-1;
        P B = a[p[i].second];
        //cout << "start " << p[i].second << endl;
        while(r-l > 1) {
            int mid = (l+r)>>1;
            if (f(A, B, mid)) r  = mid;
            else l = mid;
        }
        if (f(A, B, l)) {
            //cout << "ll " << l << " " << (l - i -1) << endl;
            res = min(res, l - i - 1);
        }
        else if (f(A, B, r)) {
            //cout << "rr " << r << " " << (r - i -1) << endl;
            res = min(res, r - i - 1);
        }
    }
    res = max(0, res);
    //cout << "ASSSSSSSS " << res << endl;
    return max(0, res);
}

int main() {
    int T; cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cout << "Case #" << tt << ":" << "\n";
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
        for (int i = 0; i < n; ++i) cout << solve(i) << "\n";
        
    }
    return 0;
}