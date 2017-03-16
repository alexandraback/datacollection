#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int zz = 1; zz <= t; ++zz) {
        int b, n;
        scanf("%d %d", &b, &n);
        int mm[b];
        for (int i = 0; i < b; ++i) scanf("%d", mm+i);

        long long int tr = (long long int) n * mm[0] + 1;
        long long int tl = 0;
        int idx = 0;
        while (tr >= tl) {
            bool f[b];
            for (int i = 0; i < b; ++i) f[i] = false;
            int ff = 0;
            long long int c = 0;
            long long int t = (tl + tr) / 2;
            for (int i = 0; i < b; ++i) {
                if (t % mm[i] == 0) {
                    f[i] = true;
                    ++ff;
                }
                c += (t+mm[i]-1) / mm[i];
            }
            //printf("> t%lld (%lld %lld) c%lld n%lld ff%d\n", t, tl, tr, c, n, ff);
            if (c >= n) {
                tr = t;
            }
            else if (c + ff >= n) { // found
                n -= c;
                for (int i = 0; i < b; ++i) {
                    if (!f[i]) continue;
                    if (n == 1) {
                        printf("Case #%d: %d\n", zz, i+1);
                        break;
                    }
                    --n;
                }
                break;
            } else {
                tl = t+1;
            }
        }
        assert(tr >= tl);
    }

    return 0;
}
