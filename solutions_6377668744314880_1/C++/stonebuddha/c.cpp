#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int kMaxN = 3010;
int n;

struct Point {
    int x, y;
    Point() {}
    Point(int x_, int y_) : x(x_), y(y_) {}
};

typedef Point Vector;

inline Vector operator-(const Vector &a, const Vector &b) {
    return Vector(a.x - b.x, a.y - b.y);
}

inline ll det(const Vector &a, const Vector &b) {
    return (ll)a.x * b.y - (ll)b.x * a.y;
}

inline ll dot(const Vector &a, const Vector &b) {
    return (ll)a.x * b.x + (ll)a.y * b.y;
}

bool cmp(const Vector &a, const Vector &b) {
    return (det(a, b) > 0 || (det(a, b) == 0 && dot(a, a) < dot(b, b)));
}

Point pnts[kMaxN];

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++ kase) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d", &pnts[i].x, &pnts[i].y);
        }
        printf("Case #%d:\n", kase);
        for (int i = 0; i < n; ++ i) {
            vector<Vector> v1, v2;
            for (int j = 0; j < n; ++ j) if (j != i) {
                Vector v = pnts[j] - pnts[i];
                if (v.y > 0 || (v.y == 0 && v.x > 0)) {
                    v1.push_back(v);
                } else {
                    v2.push_back(v);
                }
            }
            sort(v1.begin(), v1.end(), cmp);
            sort(v2.begin(), v2.end(), cmp);
            for (auto &p : v2) v1.push_back(p);
            int sz = v1.size();
            for (int _ = 0; _ < sz; ++ _) v1.push_back(v1[_]);
            int r = 0;
            int res = n - 1;
            for (int l = 0; l < sz; ++ l) {
                while (l + 1 < sz && det(v1[l], v1[l + 1]) == 0 && dot(v1[l], v1[l + 1]) > 0) ++ l;
                if (r < l) r = l;
                while (r - l < sz - 1 && det(v1[l], v1[r + 1]) > 0) ++ r;
                res = min(res, r - l);
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
