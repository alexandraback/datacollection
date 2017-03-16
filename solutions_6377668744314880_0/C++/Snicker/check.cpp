#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;
struct Point  {
    long long x, y;
    Point() {
    }
    Point (long long _x, long long _y) {
        x = _x;
        y = _y;
    }
    Point operator - (const Point & pt) const {
        return Point(x - pt.x, y - pt.y);
    }
    long long operator * (const Point & pt) const {
        return x * pt.y - y * pt.x;
    }
}p[4001];
int main() {
    freopen("E:\\NutStore\\Workspace\\ClionProjects\\ClionP\\input.txt", "r", stdin);
    freopen("E:\\NutStore\\Workspace\\ClionProjects\\ClionP\\output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    int cas = 0;
    while(T--) {
        printf("Case #%d:\n", ++cas);
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            long long x, y;
            scanf("%lld%lld", &x, &y);
            p[i] = Point(x, y);
        }
        Point v1, v2;
        if(n == 1) {
            puts("0");
            continue;
        }
        for(int i = 0; i < n; i++) {
            int ans = 0;
            for(int j = 0; j < n; j++){
                if(i == j) {
                    continue;
                }
                v1 = p[j] - p[i];
                int cnt = 0;
                for(int k = 0; k < n; k++) {
                    v2 = p[k] - p[i];
                    if(v1 * v2 >= 0) {
                        cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
            printf("%d\n", n - ans);
        }
    }
    //SYSTEM("Pause");
    return 0;
}
