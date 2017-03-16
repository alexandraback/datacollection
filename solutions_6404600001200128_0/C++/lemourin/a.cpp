#include <cstdio>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
const int MAXN = 1005;

int T[MAXN];

int main() {
    int test;
    scanf("%d", &test);

    for (int t=1; t<=test; t++) {
        int n;
        scanf("%d", &n);

        for (int i=0; i<n; i++)
            scanf("%d", &T[i]);

        int r1 = 0, r2 = 0, diff = 0;
        for (int i=0; i+1<n; i++) {
            if (T[i] > T[i+1])
                r1 += T[i]-T[i+1];
            diff = std::max(diff, T[i]-T[i+1]);
        }

        for (int i=0; i+1<n; i++) {
            if (T[i] > diff) {
                r2 += diff;
            }
            else
                r2 += T[i];
        }
        
        printf("Case #%d: %d %d\n", t, r1, r2);
        
    }
}
