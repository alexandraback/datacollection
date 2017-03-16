#include <cstdio>
#include <algorithm>
#include <cilk/cilk.h>
using namespace std;

struct el {
    long long x, y;

    void read() {
        scanf("%lld%lld", &x, &y);
    }
};

int n;
el a[3005];
int ans[3005][3005]; 
int ans2[3005];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].read();
    }
}

long long cross(el a, el b, el c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void foo(int i) {
int j;
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            int cnt = 0;

            for (int k = 0; k < n; k++) {
                if (cross(a[i], a[j], a[k]) > 0) {
                    ++ cnt;
                }
            }

            ans[i][j] = cnt; 
        }
}

void solve() {
    int i, j;
    for (i = 0; i < n; i++) {
        ans2[i] = 1 << 30;

        for (j = 0; j < n; j++) {
            ans[i][j] = 1 << 30;
        }
    }

    for (i = 0; i < n; i++) {
	cilk_spawn foo(i);
    }
cilk_sync;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans2[i] = min(ans2[i], ans[i][j]);
        }
    }
    if (n == 1) ans2[0] = 0;
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d:\n", i);
        solve();
    for (int j = 0; j < n; j++) {
        printf ("%d\n", ans2[j]);
    }
    }
    
    return 0;
}
