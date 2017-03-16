#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long
#define ULL unsigned long long
using namespace std;

const int N = 3010;
LL x[N], y[N], res[N];

int main () {
//    freopen ("in.txt", "r", stdin);
//    freopen ("out.txt", "w", stdout);
    int T, cas = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf ("%lld%lld", &x[i], &y[i]);
            if (n > 1) res[i] = n;
            else res[i] = 0;
        }
        printf ("Case #%d:\n", cas++);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                LL tx = y[j] - y[i];
                LL ty = x[i] - x[j];
                LL tz = x[j] * y[i] - x[i] * y[j];
                LL a = 0, b = 0;
                for (int k = 1; k <= n; k++) {
                    LL c = tx * x[k] + ty * y[k] + tz;
                    if (c > 0) a++;
                    else if (c < 0) b++;
                }
                LL mn = min (a, b);
                res[i] = min (res[i], mn);
                res[j] = min (res[j], mn);
            }
            printf ("%lld\n", res[i]);
        }
    }
    return 0;
}
