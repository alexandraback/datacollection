#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

struct Point {
    long long x, y;
    bool operator==(const Point& second) const {
        return x == second.x && y == second.y;
    }
    bool operator<(const Point& second) const {
        return x == second.x ? y < second.y : x < second.x;
    }
};

bool cw(const Point& p1, const Point& p2, const Point& p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) < 0;
}

bool ccw(const Point& p1, const Point& p2, const Point& p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) > 0;
}

int count(int x) {
    int ret = 0;
    while (x) {
        if (x & 1) {
            ++ret;
        }
        x >>= 1;
    }
    return ret;
}

vector<Point> buildConvexHull(vector<Point> v) {
    if (v.size() <= 1) {
        return v;
    }
    sort(v.begin(), v.end());
    vector<Point> up, down;
    const auto& p1 = v[0], p2 = v.back();
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < v.size(); ++i) {
        const auto& p = v[i];
        if (i + 1 == v.size() || cw(p1, p, p2)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], p)) {
                up.pop_back();
            }
            up.push_back(p);
        }
        if (i + 1 == v.size() || ccw(p1, p, p2)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], p)) {
                down.pop_back();
            }
            down.push_back(p);
        }
    }
    for (int i = (int)down.size() - 2; i; --i) {
        up.push_back(down[i]);
    }
    return up;
}

void Solve() {
    int n;
    cin >> n;
    vector<Point> v;
    for (int i = 0; i < n; ++i) {
        Point p;
        cin >> p.x >> p.y;
        v.push_back(p);
    }
    vector<int> answers(n, 1 << 30);
    vector<Point> vv;
    for (int j = 0; j < (1 << n); ++j) {
        vv.clear();
        for (int k = 0; k < n; ++k) {
            if (j & (1 << k)) {
                vv.push_back(v[k]);
            }
        }
        int cnt = n - count(j);
        vector<Point> convexHull = buildConvexHull(vv);
        for (int i = 0; i < n; ++i) {
            if (!(j & (1 << i))) {
                continue;
            }
            for (int k = 0; k < convexHull.size(); ++k) {
                const auto& point = convexHull[k], point2 = convexHull[(k + 1) % convexHull.size()];
                long long dx = point2.x - point.x, dy = point2.y - point.y;
                long long dx2 = point2.x - v[i].x, dy2 = point2.y - v[i].y;
                if (v[i] == point || dx * dy2 == dy * dx2) {
                    answers[i] = std::min(answers[i], cnt);
                }
            }
        }
        if (j == ((1 << n) - 1)) {
            for (const auto& point : convexHull) {
//                cerr << point.x << " " << point.y << endl;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << answers[i] << "\n";
    }
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d:\n", i + 1);
        Solve();
    }
    return 0;
}
