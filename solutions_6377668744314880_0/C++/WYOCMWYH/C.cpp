#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;

    Point () {}

    Point (long long x, long long y): x(x), y(y) {}

    Point operator - (const Point &other) const {
        return Point(x - other.x, y - other.y);
    }

    long long operator ^ (const Point &other) const {
        return x * other.y - y * other.x;
    }
};

void Solve (int test_num) {
    int n;
    scanf("%d", &n);
    vector<Point> p(n);
    for (auto& i : p) {
        cin >> i.x >> i.y;
    }
    printf("Case #%d:\n", test_num);
    if (n == 1) {
        printf("0\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        int ans = n - 1;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            int cnt[2] = {};
            for (int t = 0; t < n; ++t) {
                long long m = (p[j] - p[i]) ^ (p[t] - p[i]);
                if (m > 0) {
                    ++cnt[0];
                } else if (m < 0) {
                    ++cnt[1];
                }
            }
            ans = min(ans, min(cnt[0], cnt[1]));
        }
        printf("%d\n", ans); 
    }
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        Solve(i + 1);
    }
}
