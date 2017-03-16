#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int T, Test, n;
struct Point {
    int x, y, no, ans;
    double ang;
} P[10010];

bool cmp_ang (const Point &a, const Point &b) {
    return a.ang < b.ang;
}

bool cmp_no (const Point &a, const Point &b) {
    return a.no < b.no;
}

inline int cross(const Point &a, const Point &b, const Point &c) {
    long long t = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
    return t > 0 ? 1 : (t < 0 ? -1 : 0);
}

int main() {
    scanf("%d", &Test);
    for (int T = 1; T <= Test; ++T) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &P[i].x, &P[i].y);
            P[i].no = i;
        }
        printf("Case #%d:\n", T);
        if (n == 1) {
            printf("0\n");
            continue;
        }
        for (int c = 0; c < n; ++c) {
            for (int i = 0; i < n; ++i) 
                if (P[i].no == c) {
                    P[i].ang = 1e9;
                    swap(P[i], P[n - 1]);
                    break;
                }
            for (int i = 0; i < n - 1; ++i)
                P[i].ang = atan2(P[i].y - P[n - 1].y, P[i].x - P[n - 1].x);
            sort(P, P + n, cmp_ang);

            P[n - 1].ans = 1e9;
            for (int k = 0; k < n - 1; ++k) {
                int l = 0, r = 0;
                for (int i = 0; i < n - 1; ++i) {
                    if (i == k) continue;
                    int s = cross(P[n - 1], P[k], P[i]);
                    if (s < 0) ++l;
                    if (s > 0) ++r;
                }
                P[n - 1].ans = min(P[n - 1].ans, min(l, r));
            }
        }

        sort(P, P + n, cmp_no);
        for (int i = 0; i < n; ++i) printf("%d\n", P[i].ans);
    }
}
