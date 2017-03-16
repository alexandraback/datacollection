#include <cstdio>
#include <iostream>
using namespace std;

long long m, n;
long long a[1024];

const long long MAX = 100000LL * 1000000000LL * 2LL;

void read() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> a[i];
}

long long get(long long mid) {
    long long cnt = 0;

    for (int i = 0; i < m; i++) {
        cnt += (mid + a[i]) / a[i];
        if (cnt > MAX) cnt = MAX;
    }

    return cnt;
}

void solve() {
    long long l, r, mid;

    l = 0;
    r = MAX;

    while (l < r) {
        mid = l + (r - l) / 2;

        if (get(mid) >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    for (int i = 0; i < m; i++) {
        n -= (l + a[i] - 1) / a[i];
    }

    for (int i = 0; i < m; i++) {
        if (l % a[i] == 0) {
            if (n == 1) {
                printf ("%d\n", i + 1);
                return ;
            }
            -- n;
        }
    }
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
    }
    
    return 0;
}
