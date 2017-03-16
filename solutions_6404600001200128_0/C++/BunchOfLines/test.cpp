#include <bits/stdc++.h>

using namespace std;

int N, A[1005];
int main() {
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for (int cc = 1; cc <= T; cc++) {
        scanf("%d",&N);
        for (int i = 1; i <= N; i++)
            scanf("%d",&A[i]);

        int res1 = 0;
        for (int i = 2; i <= N; i++) {
            if (A[i] < A[i - 1])
                res1 += A[i - 1] - A[i];
        }

        int res2 = 0, best_rate = 0;
        for (int i = 2; i <= N; i++) {
            if (A[i] < A[i - 1]) {
                best_rate = max(best_rate, A[i - 1] - A[i]);
            }
        }
        for (int i = 2; i <= N; i++) {
            res2 += min(best_rate, A[i - 1]);
        }
        printf("Case #%d: %d %d\n", cc, res1, res2);
    }
    return 0;
}
