#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 100010

using namespace std;

int T, B;
long long N, M[MaxN];

bool Check(long long now) {
    int i;
    long long ret = 0;
    for(i = 1; i <= B; ++i)
        ret += now / M[i] + 1;
    if(ret >= N) return true;
    return false;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int i, j, T0 = 0;
    scanf("%d", &T);
    for( ; T; --T) {
        scanf("%d%lld", &B, &N);
        for(i = 1; i <= B; ++i)
            scanf("%lld", &M[i]);

        if(Check(0)) {
            printf("Case #%d: %lld\n", ++T0, N);
            continue;
        }
        long long l = 0, r = 1000000000000000LL, mid;
        while(l < r - 1) {
            mid = l + r >> 1;
            if(Check(mid))
                r = mid;
            else
                l = mid;
        }
        for(i = 1; i <= B; ++i)
            N -= l / M[i] + 1LL;
        for(i = 1; i <= B; ++i)
            if(r % M[i] == 0) {
                --N;
                if(N == 0) {
                    printf("Case #%d: %d\n", ++T0, i);
                    break;
                }
            }
    }
    return 0;
}
