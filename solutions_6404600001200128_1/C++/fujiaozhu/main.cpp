#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using  namespace std;

typedef long long ll;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int t, n, a[1005];
    scanf("%d", &t);

    for(int i = 1; i <= t; i ++) {
        scanf("%d", &n);
        for(int j = 0; j < n; j ++)
            scanf("%d", &a[j]);
        int res1 = 0, res2 = 0, mx = -1;
        for(int j = 0; j < n - 1; j ++) {
            if(a[j] - a[j + 1] > 0)
                res1 += (a[j] - a[j + 1]);
            mx = max(mx, a[j] - a[j + 1]);
        }
        for(int j = 0; j < n - 1; j ++) {
            res2 += min(mx, a[j]);
        }
        printf("Case #%d: %d %d\n", i, res1, res2);
    }
    return 0;
}
