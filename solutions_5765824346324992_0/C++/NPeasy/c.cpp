#include <bits/stdc++.h>
using LL = long long ;

const int N = 1000 + 5;
int n,m;
int A[N];

LL calc(LL t) {
    LL ret = 0;
    for (int i = 0; i < m; ++ i) {
        ret += (t + A[i] - 1) / A[i];
    }
    return ret;
}

LL work() {
    if (n == 1) return 1;
    LL l = 0,r = (LL) 1e9 * 100000;
    while (l <= r) {
        LL mid = l + r >> 1;
        if (calc(mid) >= n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    LL ret = r;
    n -= calc(r);
    int pos;
    for (pos = 0; pos < m && n; ++ pos) {
        if (r % A[pos] == 0) {
            if (-- n == 0) {
                break;
            }
        }
    }
    return pos + 1;
}

int main(int argc,char **args) {
    if (argc > 1) {
        freopen(args[1],"r",stdin);
        freopen("data.txt","w",stdout);
    }

    int cas,ca = 0;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d%d",&m,&n);
        for (int i = 0; i < m; ++ i) {
            scanf("%d",A+i);
        }
        printf("Case #%d: %lld\n",++ca,work());
    }
}
