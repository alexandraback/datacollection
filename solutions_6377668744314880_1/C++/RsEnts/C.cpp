#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 3010

using namespace std;

int T, N;
int Ans[MaxN];

struct Point {
    long long x, y;
}Poi[MaxN];

Point operator -(Point a, Point b) {
    Point r;
    r.x = a.x - b.x; r.y = a.y - b.y;
    return r;
}

long long operator *(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int i, j, k, T0 = 0;
    scanf("%d", &T);
    for( ; T; --T) {
        cerr << T << endl;
        scanf("%d", &N);
        for(i = 1; i <= N; ++i)
            scanf("%lld%lld", &Poi[i].x, &Poi[i].y);
        memset(Ans, 63, sizeof(Ans));
        for(i = 1; i <= N; ++i)
            for(j = i + 1; j <= N; ++j) {
                int ans1 = 0, ans2 = 0;
                for(k = 1; k <= N; ++k) {
                    long long t = (Poi[k] - Poi[i]) * (Poi[j] - Poi[i]);
                    if(t > 0)
                        ++ans1;
                    if(t < 0)
                        ++ans2;
                    if(min(ans1, ans2) >= max(Ans[i], Ans[j]))
                        break;
                }
                ans1 = min(ans1, ans2);
                Ans[i] = min(Ans[i], ans1);
                Ans[j] = min(Ans[j], ans1);
            }
        printf("Case #%d:\n", ++T0);
        if(N == 1) Ans[1] = 0;
        for(i = 1; i <= N; ++i)
            printf("%d\n", Ans[i]);
    }
    return 0;
}
