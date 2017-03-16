#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>




const double eps = 1e-8;

bool eq(double a, double b) {
    return abs(a - b) < eps;
}
bool neq(double a, double b) { return !eq(a, b); }

using namespace std;

typedef long long ll;

template < typename T > T next() { T tmp; cin >> tmp; return tmp; }

struct pnt {
    ll x, y;
    
    pnt() : x(0), y(0){}
    pnt(ll x, ll y) : x(x), y(y) {}
    pnt(const pnt & p) : x(p.x), y(p.y) {}

    pnt operator-(const pnt & rhs) { return pnt(x - rhs.x, y - rhs.y); }
    
};

pnt read() {
    ll x = next< ll >();
    ll y = next< ll >();
    return pnt(x, y);
}


void solve() {
    int n = next< int >();
    vector< pnt > p(n);
    generate(p.begin(), p.end(), read);
    vector< int > ans(n, n);
    if (n == 1) {
        cout << "\n0\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        vector< pair< double, int > > ts;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                pnt v = p[j] - p[i];
                ts.push_back(make_pair(atan2(v.y, v.x), j));
                ts.push_back(make_pair(atan2(v.y, v.x) + 2 * M_PI, j));
                ts.push_back(make_pair(atan2(v.y, v.x) + 4 * M_PI, j));
            }
        }
        sort(ts.begin(), ts.end());
        for (int j = 0; j < n - 1; ++j) {
            int tsi = ts[j].second;
            auto f1 = lower_bound(ts.begin(), ts.end(), make_pair(ts[j].first - eps, -1));
            auto f2 = lower_bound(ts.begin(), ts.end(), make_pair(ts[j].first + eps, 2 * n));
            auto f3 = lower_bound(ts.begin(), ts.end(), make_pair(ts[j].first + M_PI - eps, -1));
            auto f4 = lower_bound(ts.begin(), ts.end(), make_pair(ts[j].first + M_PI + eps, 2 * n));
            int pos = f3 - f2;
            int neg = n - 1 - (f4 - f1);
            int nv = min(pos, neg);
            ans[i] = min(ans[i], nv);
            ans[tsi] = min(ans[tsi], nv);
        }
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }

    
    
}

int main() {
    int t = next< int >();
    for (int i = 1; i <= t; ++i) {
        cerr << i << endl;
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
