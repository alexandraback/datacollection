#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

struct Point {
    int x, y;

    Point(int x, int y): x(x), y(y) {}
    Point(): x(0), y(0) {}

    Point operator +(const Point &o) const {
        return Point(x + o.x, y + o.y);
    }

    Point operator -(const Point &o) const {
        return Point(x - o.x, y - o.y);
    }

    bool operator <(const Point &o) const {
        return atan2(y + 0.0, x + 0.0) < atan2(o.y + 0.0, o.x + 0.0);
    }
};

long long det(const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

void solve() {
    int N, x, y;
    scanf("%d", &N);
    vector<Point> points;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &x, &y);
        points.push_back(Point(x, y));
    }
    if (N <= 2) {
        for (int i = 0; i < N; ++i) {
            printf("0\n");
        }
        return;
    }
    for (int i = 0; i < N; ++i) {
        int ans = N;
        Point center = points[i];
        vector<Point> v;
        for (int j = 0; j < N; ++j) {
            if (j != i) {
                v.push_back(points[j] - center);
            }
        }
        sort(v.begin(), v.end());
        int k = 0;
        for (int j = 0; j < v.size(); ++j) {
            while (k < v.size()) {
                int at = (j + k) % v.size();
                if (det(v[j], v[at]) < 0) {
                    break;
                }
                k += 1;
            }            
            ans = min(ans, (int)v.size() - k);
            assert(k > 0);
            k -= 1;
        }
        reverse(v.begin(), v.end());
        k = 0;
        for (int j = 0; j < v.size(); ++j) {
            while (k < v.size()) {
                int at = (j + k) % v.size();
                if (det(v[j], v[at]) > 0) {
                    break;
                }
                k += 1;
            }            
            ans = min(ans, (int)v.size() - k);
            assert(k > 0);
            k -= 1;
        }
        printf("%d\n", ans);
    }
}

int main() {
    //freopen("C.in", "r", stdin);
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int testCount;
    scanf("%d", &testCount);
    for (int testId = 1; testId <= testCount; ++testId) {
        printf("Case #%d:\n", testId);
        solve();
    }
}
