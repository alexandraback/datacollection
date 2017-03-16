#pragma  comment(linker, "/STACK:36777216")
#include <bits/stdc++.h>
#define  lc(x) (x << 1)
#define  rc(x) (lc(x) + 1)
#define  lowbit(x) (x & (-x))
#define  PI    (acos(-1))
#define  lowbit(x) (x & (-x))
#define  LL    long long
#define  DB    double
#define  ULL   unsigned long long
#define  PII   pair<int, int>
#define  PLL   pair<LL, LL>
#define  PB    push_back
#define  MP    make_pair

using namespace std;

const int N = 5555;
const DB  EPS = 1e-8;
const int INF = 0x3fffffff;

inline int sgn(DB x) {
    return x < -EPS ? -1 : x < EPS ? 0 : 1;
}

struct Point {
    LL x, y;
    Point() {}
    Point(int _x, int _y) {
        x = _x, y = _y;
    }
    inline bool operator == (const Point &A) const {
        return (sgn(x - A.x) == 0 && sgn(y - A.y) == 0);
    }
    inline bool operator < (const Point A) const {
        if(sgn(x - A.x) != 0) return sgn(x - A.x) < 0;
        return sgn(y - A.y) < 0;
    }
    inline Point operator + (const Point &A) const {
        return Point(x + A.x, y + A.y);
    }
    inline Point operator - (const Point &A) const {
        return Point(x - A.x, y - A.y);
    }
    inline Point operator * (const DB &A) const {
        return Point(x * A, y * A);
    }
    inline Point operator / (const DB &A) const {
        return Point(x / A, y / A);
    }
    inline LL operator * (const Point &A) const {
        return x * A.y - y * A.x;
    }
    inline int operator & (const Point &A) const {
        return x * A.x + y * A.y;
    }
};

inline DB Angle(Point A, Point B) {
    return atan2(B.y - A.y, B.x - A.x);
}

int T, cas, n, u, v, res[N];

Point p[N];

int main(){
//    freopen("in.txt", "r", stdin);
    freopen("C-large.in", "r", stdin);
    freopen("clarge.txt", "w", stdout);
    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; i ++) {
            scanf("%d%d", &u, &v);
            p[i] = Point(u, v);
        }
        vector <DB> vec;
        printf("Case #%d:\n", ++ cas);
        for (int i = 0; i < n; i ++) {
            vec.clear();
            for (int j = 0; j < n; j ++) {
                if (i != j) {
                    vec.PB(Angle(p[i], p[j]));
                    vec.PB(Angle(p[i], p[j]) + 2 * PI);
                    vec.PB(Angle(p[i], p[j]) + 4 * PI);
                }
            }
            sort(vec.begin(), vec.end());
            int mx = 0, r = 0;
            for (int l = 0; l < vec.size(); l ++) {
//                cout << vec[l] << endl;
                while (vec[r] - vec[l] < PI + EPS && r < vec.size()) r ++;
                mx = max(mx, r - l);
            }
            printf("%d\n", n - 1 - mx);
        }
    }
}
