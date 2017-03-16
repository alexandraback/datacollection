#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[1024];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void solve() {
    int ans1 = 0, ans2 = 0;
    int maxdif = 0;

    for (int i = 0; i + 1 < n; i++) {
        if (a[i + 1] < a[i]) {
            ans1 += a[i] - a[i + 1];
        }

        int dif = a[i] - a[i + 1];
        if (dif > maxdif) {
            maxdif = dif;
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        ans2 += min(a[i], maxdif);
    }

    printf ("%d %d\n", ans1, ans2);
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
