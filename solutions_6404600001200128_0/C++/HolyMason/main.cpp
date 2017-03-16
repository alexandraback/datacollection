#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long LL;
const int N = 1005;
int n, a[N];

int solve(int p) {
    int res = 0;
    for(int i = 2; i <= n; ++i) {
        res += min(p, a[i - 1]);
        int v = a[i - 1] - p;
        if(v > a[i]) return INF;
    }
    return res;
}

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        int ans1 = 0;
        for(int i = 2; i <= n; ++i) if(a[i] < a[i - 1]) ans1 += a[i - 1] - a[i];
        int ans2 = INF, mx = 0;
        for(int i = 1; i <= n; ++i) mx = max(mx, a[i]);
        for(int i = 0; i <= mx; ++i) ans2 = min(ans2, solve(i));
        printf("Case #%d: %d %d\n", ca, ans1, ans2);
    }
    return 0;
}
