#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define ll long long

struct P {
    ll x, y;
    bool operator<(P p) const {
        if (x == p.x) return y < p.y;
        return x <p.x;
    }
    bool operator==(P p) const {
        return x == p.x && y == p.y;
    }
};

int n;
vector<P> u;
vector<P> p, a;

ll ccw(P p1, P p2, P p3) {
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

void andrew() {
    a.clear();
    sort(p.begin(), p.end());
    for (int z = 0; z < 2; z++) {
        for (int i = 0; i < p.size(); i++) {
            int c = a.size();
            while (c >= 2 && ccw(a[c-2], a[c-1], p[i]) > 0) {
                a.pop_back();
                c--;
            }
            a.push_back(p[i]);
        }
        if (a.size() > 0) a.pop_back();
        reverse(p.begin(), p.end());
    }
}

int z[20];

void solve(int x) {
    cin >> n;
    u.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i].x >> u[i].y;
        z[i] = n;
    }
    if (n == 1) z[0] = 0;
    for (int i = 0; i < (1<<n); i++) {
        int uz = n;
        p.clear();
        for (int j = 0; j < n; j++) {
            if ((i&(1<<j)) == 0) continue;
            uz--;
            p.push_back(u[j]);
        }
        andrew();
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < a.size(); k++) {
                if (u[j] == a[k]) z[j] = min(z[j], uz);
            }
        }
    }
    cout << "Case #" << x << ":\n";
    for (int i = 0; i < n; i++) cout << z[i] << "\n";
}

int t;

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
