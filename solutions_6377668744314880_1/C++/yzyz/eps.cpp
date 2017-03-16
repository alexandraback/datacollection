#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>
#define MAXN 3010
#define PI 3.14159265358979323846264338
#define EPS 1e-12

using namespace std;

struct pt {
    long long x,y;
    pt(long long x = 0, long long y = 0) : x(x), y(y) {}
};

struct event {
    double t;
    int delta;
    event() {}
    event(double t, int delta) : t(t), delta(delta) {}
    bool operator < (const event &e) const {
        if (abs(t - e.t) < EPS) return delta < e.delta;
        return t < e.t;
    }
};

int n;
pt p[MAXN];
vector<pair<double, int> > v;
vector<event> e;

double calc_angle(int a, int b) {
    long long dx = p[b].x - p[a].x;
    long long dy = p[b].y - p[a].y;
    double theta = atan2(dy, dx);
    if (theta < 0) theta += 2 * PI;
    return theta;
}

int solve(int a) {
    v.clear();
    e.clear();
    for (int i = 0; i < n; i++) {
        if (i == a) continue;
        v.push_back(make_pair(calc_angle(a,i), i));
    }
    sort(v.begin(),v.end());
    int ct = 0;
    for (auto pp : v) {
        if (pp.first < PI) {
            ct++;
            e.push_back(event(pp.first, -1));
            e.push_back(event(pp.first + PI, 1));
        }
        else {
            e.push_back(event(pp.first - PI, 1));
            e.push_back(event(pp.first, -1));
        }
    }
    sort(e.begin(),e.end());
    int res = ct;
    for (auto ee : e) {
        ct += ee.delta;
        res = min(res,ct);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cerr << "Testcase " << TC << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }
        cout << "Case #" << TC << ":\n";
        for (int i = 0; i < n; i++)
            cout << solve(i) << '\n';
    }
}
