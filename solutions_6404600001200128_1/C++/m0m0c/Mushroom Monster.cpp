#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
int main(){
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int TC, tc, n, m, ans, i;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++){
        scanf("%d", &n);
        ans = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(i = 2; i <= n; i++){
            if(a[i] < a[i-1]) ans += (a[i-1] - a[i]);
        }
        printf("Case #%d: %d ", tc, ans);
        int maxn = 0;
        for(i = 2; i <= n; i++){
            if(a[i] < a[i-1]) maxn = max(maxn, a[i-1]-a[i]);
        }
        ans = maxn *(n-1);
        for(i = 1; i < n; i++){
            if(maxn > a[i])  ans -= maxn-a[i];
        }
        printf("%d\n", ans);

    }
    return 0;
 }
