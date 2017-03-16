#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 1000010

using namespace std;

int T, N, ans1, ans2;
int a[MaxN];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int i, j, T0 = 0;
    scanf("%d", &T);
    for( ; T; --T) {
        scanf("%d", &N);
        for(i = 1; i <= N; ++i)
            scanf("%d", &a[i]);
        ans1 = 0; ans2 = 0;
        for(i = 2; i <= N; ++i)
            ans1 += max(a[i - 1] - a[i], 0);
        for(i = 0; i < 10000; ++i) {
            int flag = 0, nowans2 = 0;
            int nowcnt = 0;
            for(j = 1; j <= N; ++j) {
                if(nowcnt > a[j]) {
                    flag = 1;
                    break;
                }
                if(j == N) break;
                nowcnt = max(nowcnt, a[j]);
                nowans2 += min(i, nowcnt);
                nowcnt -= i;
                nowcnt = max(nowcnt, 0);
            }
            if(flag) continue;
            ans2 = nowans2; break;
        }
        printf("Case #%d: %d %d\n", ++T0, ans1, ans2);

    }
    return 0;
}
