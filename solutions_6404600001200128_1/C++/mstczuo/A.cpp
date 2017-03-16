# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int a[1200], n;
long long getans() {
    int t = 0;
    long long ans = 0;
    for(int i = 1; i < n; ++i) 
        if(a[i] < a[i-1]) t = max(t, a[i-1] - a[i]);
    int cur = a[0];
    for(int i = 1; i < n; ++i) {
        ans += min(cur, t);
        cur = a[i];
    }
    return ans;
}

int main() {
    freopen("A.in","r",stdin);
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int x = 0;
        for(int i = 1; i < n; ++i)
            if(a[i] < a[i-1]) x += a[i-1] - a[i];
        printf("Case #%d: %d %lld\n", cas, x, getans());
    }
}

