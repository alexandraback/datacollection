#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct Point {
    ll x, y;
    int id;
    Point() {}
    Point(ll _x, ll _y) : x(_x), y(_y) {};

    bool operator < (const Point& b) const {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
} p[100010], ch[100010];
typedef Point Vector;

Vector operator - (const Vector& A, const Vector& B) {
    return Vector(A.x - B.x, A.y - B.y);
}

ll Cross(Point A, Point B) { return A.x*B.y - A.y*B.x; }

bool vis[100010];

// 这个算法跑出来的凸包有可能包含相同的点多次，比如说所有点都共线的情况

int ConvexHull(Point *p, int n, Point *ch) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        // 如果希望边上有点，则把<=改成<
        while (m > 1 && Cross(ch[m-1] - ch[m-2], p[i] - ch[m-2]) < 0) m--;
        ch[m++] = p[i]; 
    }
    int k = m;
    for (int i = n-2; i >= 0; i--) {
        if (vis[i]) continue;
        while (m > k && Cross(ch[m-1] - ch[m-2], p[i] - ch[m-2]) < 0) m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
//    for (int i = 0; i < m; i++) vis[ch[i].id] = 1;
    return m;
}

int n;

int ans[20];

void dfs(int cur, int cnt) {
    if (cur == n) {
        int m = ConvexHull(p, n, ch);
        // printf("convex: n=%d, m=%d, del:%d\n", n, m, cnt);
        for (int i = 0; i < m; i++) {
//            printf("(%d, %d)\n", ch[i].x, ch[i].y);
            ans[ch[i].id] = min(ans[ch[i].id], cnt);
        }
    }
    else {
        vis[cur] = 1;
        dfs(cur+1, cnt+1);
        vis[cur] = 0;
        dfs(cur+1, cnt);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            p[i].id = i;
            scanf("%lld%lld", &p[i].x, &p[i].y);
            ans[i] = n-1;
        }
        sort(p, p+n); 

        dfs(0, 0);
        printf("Case #%d:\n", kase);
        for (int i = 0; i < n; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
