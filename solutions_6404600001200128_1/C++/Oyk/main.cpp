#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

int a[MAXN], maxr[MAXN];
int T, n;

int solve1() {
    int res = 0;
    for(int i = 0; i < n - 1; ++i)
        res += max(0, a[i] - a[i + 1]);
    return res;
}

int solve2() {
    int spd = 0;
    for(int i = 0; i < n - 1; ++i)
        spd = max(spd, a[i] - a[i + 1]);
    int res = 0;
    for(int i = 0; i < n - 1; ++i)
        res += min(a[i], spd);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        maxr[n] = 0;
        for(int i = n - 1; i >= 0; --i)
            maxr[i] = max(maxr[i + 1], a[i]);
        printf("Case #%d: %d %d\n", t, solve1(), solve2());
    }
}
