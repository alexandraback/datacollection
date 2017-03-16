#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int m[100000];

int main() {
    freopen("mushroom.in", "r", stdin);
    freopen("mushroom.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        int N, ans1 = 0, ans2 = 0, gap = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &m[i]);
        for (int i = 1; i < N; ++i)
            if (m[i] < m[i - 1]) {
                gap = max(gap, m[i - 1] - m[i]);
                ans1 += m[i - 1] - m[i];
            }
        for (int i = 0; i < N - 1; ++i)
            if (m[i] >= gap)
                ans2 += gap;
            else
                ans2 += m[i];
        printf("Case #%d: %d %d\n", Case, ans1, ans2);
    }
    return 0;
}
