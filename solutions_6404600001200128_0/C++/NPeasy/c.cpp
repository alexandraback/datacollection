#include <bits/stdc++.h>
using LL = long long ;

const int N = 1000 + 5;
int n;
int A[N];

int work1() {
    int ret = 0;
    for (int i = 0; i < n - 1; ++ i) {
        if (A[i] > A[i + 1]) {
            ret += A[i] - A[i + 1];
        }
    }
    return ret;
}

int work2() {
    int mx = 0;
    for (int i = 0; i < n - 1; ++ i) {
        mx = std::max(A[i] - A[i + 1],mx);
    }
    int ret = 0;
    for (int i = 1; i < n; ++ i) {
        ret += std::min(mx,A[i - 1]);
    }
    return ret;
}

int main(int argc,char **args) {
    if (argc > 1) {
        freopen(args[1],"r",stdin);
        freopen("data.txt","w",stdout);
    }
    int cas,ca = 0;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",A+i);
        }
        printf("Case #%d: %d %d\n",++ca,work1(),work2());
    }
}
