#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50;

int T, n;

struct point {

    int x;
    int y;

    bool operator < (const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
} p[N];

bool check(point a, point b, point c) {
    long long ccw = 1LL * (c.y - a.y) * (b.x - a.x) - 1LL * (c.x - a.x) * (b.y - a.y);
    long long dot = 1LL * (c.x - a.x) * (b.x - a.x) + 1LL * (c.y - a.y) * (b.y - a.y);
    if (ccw != 0 || dot < 0) {
        return false;
    }
    long long sqr = 1LL * (b.x - a.x) * (b.x - a.x) + 1LL * (b.y - a.y) * (b.y - a.y);
    if (dot > sqr) {
        return false;
    }
    return true;
}

long long cross(point a, point b, point c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

vector <point> hull(vector <point> pts) {
    int m = pts.size();
    if (m <= 2) {
        return pts;
    }
    vector <point> ret;
    sort(pts.begin(), pts.end());
    for (int i = 0; i < m; i++) {
        while (ret.size() >= 2 && cross(ret[ret.size() - 2], ret[ret.size() - 1], pts[i]) <= 0) {
            ret.pop_back();
        }
        ret.push_back(pts[i]);
    }
    for (int i = m - 2, j = ret.size() + 1; i >= 0; i--) {
        while (ret.size() >= j && cross(ret[ret.size() - 2], ret[ret.size() - 1], pts[i]) <= 0) {
            ret.pop_back();
        }
        ret.push_back(pts[i]);
    }
    return ret;
}

int ans[N];

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
            ans[i] = n - 1;
        }
        for (int i = 0; i < (1 << n); i++) {
            int cut = n - __builtin_popcount(i);
            vector <point> pts;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) == 0) {
                    continue;
                }
                pts.push_back(p[j]);
            }
            vector <point> poly = hull(pts);
            for (int j = 0; j + 1 < poly.size(); j++) {
                for (int k = 0; k < n; k++) {
                    if (check(poly[j], poly[(j + 1) % poly.size()], p[k])) {
                        ans[k] = min(ans[k], cut);
                    }
                }
            }
        }
        printf("Case #%d:\n", t);
        for (int i = 0; i < n; i++) {
            printf("%d\n", ans[i]);
        }
    }

    return 0;

}
