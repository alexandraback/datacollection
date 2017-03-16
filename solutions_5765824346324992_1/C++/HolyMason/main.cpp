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
int a[N], m, n;

bool check(LL t) {
    LL cnt = 0;
    for(int i = 1; i <= m; ++i) cnt += t / a[i] + 1;
    return cnt >= n;
}

LL get_time() {
    LL l = 0, r = 1LL << 50, res;
    while(l <= r) {
        LL mid = (l + r) >> 1;
        if(check(mid)) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &m, &n);
        for(int i = 1; i <= m; ++i) scanf("%d", a + i);
        printf("Case #%d: ", ca);
        if(m >= n) {
            printf("%d\n", n);
            continue;
        }
        LL t = get_time();
        LL cnt = 0;
        for(int i = 1; i <= m; ++i) cnt += (t - 1) / a[i] + 1;
        LL last = n - cnt;
        for(int i = 1; i <= m; ++i) if(t % a[i] == 0) {
            if(last == 1) {
                printf("%d\n", i);
                break;
            }
            --last;
        }
    }
    return 0;
}
