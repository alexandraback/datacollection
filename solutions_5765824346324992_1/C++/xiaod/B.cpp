#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 1e3 + 5;

int a[N], B, n;

long long cnt(long long t) {
    long long res = B;
    for(int i = 0; i < B; i++) {
        //printf("#%lld\n", res);
        res += t / a[i];
    }
    return res;
}

int get_id(long long t) {
    long long cur = t == 0 ? 0 : cnt(t - 1);
    for(int i = 0; i < B; ++i) {
        if(t % a[i] == 0) {
            if(++cur == n) {
                return i + 1;
            }
        }
    }
    return -1;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("out.ads", "w", stdout);
    int T, ncase = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &B, &n);
        for(int i = 0; i < B; ++i) {
            scanf("%d", &a[i]);
        }
        long long l = 0, r = 1LL << 52;
        //long long l = 0, r = 62;
        while(l < r) {
            long long mid = (l + r) / 2;
            //printf("%lld\n", cnt(mid));
            if(cnt(mid) < n) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        //printf("t ==> ##%lld\n", r);
        printf("Case #%d: %d\n", ++ncase, get_id(r));
    }
    return 0;
}
