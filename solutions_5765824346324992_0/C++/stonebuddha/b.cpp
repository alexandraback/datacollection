#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int kMaxM = 1010;
int m, n, t[kMaxM];

bool check(ll tim) {
    ll cnt = 0;
    for (int i = 0; i < m; ++ i) {
        cnt += tim / t[i];
        if (tim % t[i]) ++ cnt;
    }
    return (cnt < n);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++ kase) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; ++ i) {
            scanf("%d", &t[i]);
        }
        ll lb = 0, rb = 1000000000000000LL;
        while (lb + 1 < rb) {
            ll mid = (lb + rb) >> 1;
            if (check(mid)) {
                lb = mid;
            } else {
                rb = mid;
            }
        }
        ll cnt = 0;
        for (int i = 0; i < m; ++ i) {
            cnt += lb / t[i];
            if (lb % t[i]) ++ cnt;
        }
        ll rest = n - cnt;
        for (int i = 0; i < m; ++ i) {
            if (lb % t[i] == 0) {
                -- rest;
                if (rest == 0) {
                    printf("Case #%d: %d\n", kase, i + 1);
                    break;
                }
            }
        }
    }
    return 0;
}
