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

const int N = 1010;
int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
//    freopen ("out.txt", "w", stdout);
    int T, cas = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        LL res1 = 0, res2 = 0;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &a[i]);
            if (i > 1) {
                res1 += max (0, a[i - 1] - a[i]);
                mx = max (mx, a[i - 1] - a[i]);
            }
        }
        for (int i = 1; i < n; i++) {
            if (mx < a[i]) {
                res2 += mx;
            } else {
                res2 += a[i];
            }
        }
        printf ("Case #%d: ", cas++);
        cout << res1 << ' ' << res2 << endl;
    }
}
