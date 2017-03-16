#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;

const int MAXN = 3010;

struct Point {
    int x, y, id;
    Point() {}
    Point(int x, int y): x(x), y(y) {}
    void read(int i) {
        id = i;
        scanf("%d%d", &x, &y);
    }
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    bool operator < (const Point &rhs) const {
        if(y != rhs.y) return y < rhs.y;
        return x < rhs.x;
    }
};

LL cross(const Point &a, const Point &b) {
    return (LL)a.x * b.y - (LL)a.y * b.x;
}
//ret >= 0 means turn right
LL cross(const Point &op, const Point &sp, const Point &ed) {
    return cross(sp - op, ed - op);
}

Point p[MAXN];
int ans[MAXN];
int n, top, T;

void update_min(int &a, int b) {
    if(a > b) a = b;
}

void solve() {
    for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) {
        int lsum = 0, rsum = 0;
        for(int k = 0; k < n; ++k) {
            LL t = cross(p[i], p[j], p[k]);
            if(t > 0) lsum++;
            if(t < 0) rsum++;
        }
        update_min(ans[i], min(lsum, rsum));
        update_min(ans[j], min(lsum, rsum));
    }
}

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            p[i].read(i), ans[i] = n - 1;
        solve();
        printf("Case #%d:\n", t);
        for(int i = 0; i < n; ++i)
            printf("%d\n", ans[i]);
    }
}

