#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N, B, A[1005];
int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for (int cc = 1; cc <= T; cc++) {
        scanf("%d %d",&B, &N);
        for (int i = 1; i <= B; i++)
            scanf("%d",&A[i]);

        ll l = 0, h = 1LL << 60;
        int res = -1;
        while (l <= h) {
            ll m = (l + h) / 2;
            ll num_processed = 0;
            for (int i = 1; i <= B; i++) {
                if (m == 0)
                    continue;
                num_processed += (m - 1) / A[i] + 1;
            }

            if (num_processed >= N) {
                h = m - 1;
                continue;
            }

            for (int i = 1; i <= B; i++) {
                if (m % A[i] == 0) {
                    num_processed++;
                }
                if (num_processed == (ll)N) {
                    res = i;
                    break;
                }
            }
            if (num_processed < N) {
                l = m + 1;
            } else {
                break;
            }
        }
        assert(res != -1);
        printf("Case #%d: %d\n", cc, res);
    }
    return 0;
}
