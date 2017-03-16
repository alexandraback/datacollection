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
    int quad() const {
        if (x >= 0 && y >= 0) {
            return 0;
        } else if (y >= 0 && x < 0) {
            return 1;
        } else if (x <= 0 && y < 0) {
            return 2;
        } else {
            return 3;
        }
    }
};

bool cw(const Point& p1, const Point& p2, const Point& p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) < 0;
}

bool ccw(const Point& p1, const Point& p2, const Point& p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) > 0;
}

long long sgn(long long x) {
    return x > 0 ? 1 : (x < 0 ? -1 : 0);
}

Point p0 = {0, 0};

bool cmp(const Point& p1, const Point& p2) {
    if (p1.quad() != p2.quad()) {
        return p1.quad() < p2.quad();
    } else {
        return cw(p1, p0, p2);
    }
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
    if (n == 1) {
        puts("0");
        return;
    }
    for (int i = 0; i < n; ++i) {
        //cerr << i << "!:\n";
        vector<Point> vv;
        for (int j = 0; j < n; ++j) {
            if (j % n == i) {
                continue;
            }
            vv.push_back(v[j % n]);
            vv.back().x -= v[i].x;
            vv.back().y -= v[i].y;
        }
        sort(vv.begin(), vv.end(), cmp);
        int p = 0, nn = n - 1;
        for (int j = 0; j < nn; ++j) {
            vv.push_back(vv[j]);
        }
        while (!ccw(vv[0], p0, vv[p]) && p < nn) {
            ++p;
        }
        for (int j = 0; j < nn; ++j) {
            while (p < nn + j && !ccw(vv[j], p0, vv[p])) {
                ++p;
            }
            //cerr << "=============\n";
            //cerr << vv[j].x << " " << vv[j].y << endl;
            //cerr << vv[p].x << " " << vv[p].y << endl;
            answers[i] = min(answers[i], nn + j - p);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << answers[i] << '\n';
    }
}

int main() {
    freopen("c_hard.in", "r", stdin);
    freopen("c_hard.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d:\n", i + 1);
        Solve();
    }
    return 0;
}
