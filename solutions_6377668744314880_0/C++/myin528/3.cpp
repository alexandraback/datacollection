#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

int x[3000], y[3000], ans[3000];

long long cross(int a, int b, int c) {
    return (long long)(x[b] - x[a]) * (y[c] - y[a]) - (long long)(x[c] - x[a]) * (y[b] - y[a]);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d ", x+i, y+i);
        }
        printf("Case #%d:\n", tt + 1);
        if (n == 1) {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; i++)
            ans[i] = 5000;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int pos = 0, neg = 0;
                for (int k = 0; k < n; k++) {
                    long long r = cross(i, j, k);
                    if (r > 0)
                        pos++;
                    else if (r < 0)
                        neg++;
                }
                ans[i] = min(ans[i], min(pos, neg));
                ans[j] = min(ans[j], min(pos, neg));
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}