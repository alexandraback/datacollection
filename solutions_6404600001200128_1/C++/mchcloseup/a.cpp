#include <iostream>
#include <cstdio>

using namespace std;

int T, m[1010], ans1, ans2, maxn, n;

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++){
        scanf("%d", &n);
        maxn = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &m[i]);
            if (i)
                maxn = max(maxn, m[i - 1] - m[i]);
        }
        ans1 = 0, ans2 = 0;
        for (int i = 0; i < n - 1; i++){
            if (m[i] - m[i + 1] > 0)
                ans1 += m[i] - m[i + 1];
            ans2 += min(maxn, m[i]);
        }
        printf("Case #%d: %d %d\n", ca, ans1, ans2);
    }

}

