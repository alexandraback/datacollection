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

const int N = 55;
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

bool vis[N];

int ConvexHull(vector <pair <Point, int> > p){
    sort(p.begin(), p.end());
    pair <Point, int> ch[55];
    int m = 0, t = 0;
    for(int i = 0; i < p.size(); i ++){
        while(m > 1 && (ch[m - 1].first - ch[m - 2].first) * (p[i].first - ch[m - 2].first) < 0) m --; // Must be <= , so that there are no 3 points 1 line
        ch[m ++] = p[i];
    }
    int k = m;
    for(int i = p.size() - 2; i >= 0; i --){
        while(m > k && (ch[m - 1].first - ch[m - 2].first) * (p[i].first - ch[m - 2].first) < 0) m --;
        ch[m ++] = p[i];
    }
    if(p.size() > 1) m --;
//    for (int i = 0; i < p.size(); i ++)
//        cout << p[i].x << ' ' << p[i].y << endl;
//    cout << endl;
    for (int i = 0; i < m; i ++) {
//        cout << ch[i].x << ' ' << ch[i].y << ' ' << stk[i] << endl;
        vis[ch[i].second] = true;
    }
    return m;
}

int T, cas, n, u, v, res[N];

Point p[N];

int main(){
//    freopen("in.txt", "r", stdin);
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; i ++) {
            scanf("%d%d", &u, &v);
            p[i] = Point(u, v);
        }
        memset(res, 0x3f, sizeof(res));
        vector <pair <Point, int> > vecp;
        for (int i = 1; i < (1 << n); i ++) {
            int cnt = 0;
            vecp.clear();
            memset(vis, 0, sizeof(vis));
            for (int j = 0; j < n; j ++) {
                if (i >> j & 1) {
                    cnt ++;
                    vecp.PB(MP(p[j], j));
//                    cout << j << ' ';
                }
            }
//            cout << " # ";
            ConvexHull(vecp);
            for (int j = 0; j < n; j ++) {
                if (vis[j]) {
//                    cout << j << ' ';
                    res[j] = min(res[j], n - cnt);
                }
            }
//            cout << endl;
        }
        printf("Case #%d:\n", ++ cas);
        for (int i = 0; i < n; i ++)
            printf("%d\n", res[i]);
    }
}
