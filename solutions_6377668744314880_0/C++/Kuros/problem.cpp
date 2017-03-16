#include <stdio.h>
#include <set>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef long long LL;

#define MAXN 100100
#define INF 20000000
#define tl(x) (x << 1)
#define tr(x) (x << 1 | 1)
#define mod 100007

int T, n;

struct Point {
    long long x, y;
    long long operator * (const Point & b) const {
        return x * b.y - y * b.x;
    }
    Point operator - (const Point & b) const {
        Point res;
        res.x = x - b.x;
        res.y = y - b.y;
        return res;
    }
}bx[3010], ax[3010];

int quad(Point a) {
    if(a.y >= 0 && a.x > 0) return 1;
    else if(a.y > 0 && a.x <= 0) return 2;
    else if(a.y <= 0 && a.x < 0) return 3;
    else if(a.y < 0 && a.x >= 0) return 4;
}

int cmp(Point a, Point b) {
    int qd1 = quad(a); int qd2 = quad(b);
    if(qd1 != qd2) {
        if(qd1 < qd2) return 1;
        else return 0;
    }
    if(a * b > 0) return 1;
    else return 0;
}

int main() {
    //freopen("pro.in","r",stdin);
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    scanf("%d", &T);
    int cas = 1;
    while(T--) {
        printf("Case #%d:\n", cas++);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%lld%lld", &bx[i].x, &bx[i].y);
        }
        int o = 0;
        
        for(int i = 1; i <= n; i++) {
            int ans = n - 1;
            o = 0;
            for(int j = 1; j <= n; j++) if(i != j) {
                ax[++o] = bx[j] - bx[i];
            }
            sort(ax + 1, ax + 1 + o, cmp);
            for(int j = 1; j < n; j++) ax[++o] = ax[j];

            int r = 1;
            for(int j = 2; j < n; j++) {
                if(ax[1] * ax[j] >= 0) r = j;
                else break;
            }
            for(int j = 1; j < n; j++) {
               int lim = j + n - 2;
               while(r < lim && ax[j] * ax[r + 1] >= 0) r++;
               ans = min(ans, (n - 1) - (r - j + 1));
            }
            printf("%d\n", ans);
        }
    }

    return 0;
} 

