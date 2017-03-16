#include <cstdio>
#include <algorithm>
using namespace std;

struct el {
    long long x, y;

    void read() {
        scanf("%lld%lld", &x, &y);
    }
};

int n;
el a[3005];
int ans[3005];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].read();
    }
}

long long cross(el a, el b, el c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void solve() {
    for (int i = 0; i < n; i++) ans[i] = 1 << 30;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int cnt = 0;

            for (int k = 0; k < n; k++) {
                if (cross(a[i], a[j], a[k]) > 0) {
                    ++ cnt;
                }
            }

            ans[i] = min(ans[i], cnt);
            ans[j] = min(ans[j], cnt);
        }
    }
    if (n == 1) ans[0] = 0;

    for (int i = 0; i < n; i++) {
        printf ("%d\n", ans[i]);
    }
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d:\n", i);
        solve();
    }
    
    return 0;
}
