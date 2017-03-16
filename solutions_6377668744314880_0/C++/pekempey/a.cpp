#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

typedef long long ll;

struct P {
    ll x, y;
    P() {}
    P(ll x, ll y) : x(x), y(y) {}
    P operator+(P p) {
        return P(x + p.x, y + p.y);
    }
    P operator-(P p) {
        return P(x - p.x, y - p.y);
    }
    P operator*(ll k) {
        return P(x * k, y * k);
    }
    ll dot(P p) {
        return x * p.x + y * p.y;
    }
    ll det(P p) {
        return x * p.y - y * p.x;
    }
};

bool cmp_x(const P &p, const P &q) {
    if (p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

vector<P> convex_full(vector<P> ps) {
    sort(ps.begin(), ps.end(), cmp_x);
    int k = 0;
    int n = ps.size();
    vector<P> qs(n * 2);

    for (int i = 0; i < n; i++) {
        while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
        qs[k++] = ps[i];
    }

    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
        qs[k++] = ps[i];
    }

    qs.resize(k - 1);
    return qs;
}

bool onseg(P p1, P p2, P q) {
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

P PS[3000];
int N;
int mini[3000];

void solve() {
    for (int i = 0; i < N; i++) {
        mini[i] = N - 1;
    }
    for (int i = 1; i < 1 << N; i++) {
        int cnt = __builtin_popcount(i);
        int cut = N - cnt;
        vector<P> ps;

        for (int j = 0; j < N; j++) {
            if (i >> j & 1) {
                ps.push_back(PS[j]);
            }
        }

        vector<P> cf = convex_full(ps);
        int n = cf.size();

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < n; k++) {
                if (onseg(cf[k], cf[(k + 1) % n], PS[j])) {
                    mini[j] = min(mini[j], cut);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << mini[i] << endl;
    }
}

int main() {
    int T;
    cin >> T;

    for (int k = 1; k <= T; k++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            ll x, y;
            cin >> x >> y;
            PS[i] = P(x, y);
        }

        printf("Case #%d:\n", k);
        solve();
    }
}
