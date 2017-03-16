#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10010;

int a[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int ans1 = 0, rate = 0;
        for (int i = 1; i < n; ++i) {
            int tmp = a[i - 1] - a[i];
            if (tmp > 0) {
                ans1 += tmp;
                rate = rate < tmp ? tmp : rate;
            }
        }
        int ans2 = 0;
        for (int i = 0; i < n - 1; ++i)
            if (a[i] < rate)
                ans2 += a[i];
            else {
                ans2 += rate;
            }
        printf("Case #%d: %d %d\n", t, ans1, ans2);
    }
    return 0;
}
