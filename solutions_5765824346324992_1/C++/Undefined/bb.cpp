#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli barb[1000];

int main() {
    lli T, t, B, N, b, l, r, mid, passes;
    scanf("%lld", &T);
    for(t = 0; t < T; ++t) {
        scanf("%lld %lld", &B, &N);
        for(b = 0; b < B; ++b) {
            scanf("%lld", barb+b);
        }
        if(N < B) {
            b = N-1;
        } else {
            l = 0;
            r = 100000000000000;
            while(l < r) {
                mid = (l + r) / 2;
                passes = B;
                for(b = 0; b < B; ++b) {
                    passes += mid / barb[b];
                }
                if(passes >= N) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            mid = r - 1;
            passes = B;
            for(b = 0; b < B; ++b) {
                passes += mid / barb[b];
                if(passes == N) {
                    break;
                }
            }
            while(passes != N) {
                ++mid;
                for(b = 0; b < B; ++b) {
                    if(mid % barb[b] == 0) {
                        ++passes;
                        if(passes == N) {
                            break;
                        }
                    }
                }
            }
        }
        printf("Case #%lld: %lld\n", t+1, b+1);
    }
}
