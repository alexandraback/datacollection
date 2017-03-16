
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

const int N = 1100;
const LL INF = 1LL << 50;

int b, n, cas = 1;
int a[N];

int solve (LL t) {
    LL all = 0, cnt = 0;
    for (int i = 1; i <= b; i++) {
        if (t) all += (t - 1) / a[i] + 1;
        cnt += (t % a[i] == 0);
    }
//    cout << mn << ' ' << mx << endl;
//    cout << t << ' ' << all << ' ' << cnt << endl;
    if (cnt && all < n && n <= all + cnt) {
//        cout <<t << ' ' << all << ' ' << cnt << endl;
        n -= all;
        for (int i = 1; i <= b; i++) if (t % a[i] == 0) {
            n--;
            if (n == 0) {
                printf ("%d", i);
                break;
            }
        }
        return 0;
    }
    if (n <= all) return -1;
    return 1;
}
int main () {
//    freopen ("in.txt", "r", stdin);
//    freopen ("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> b >> n;
        for (int i = 1; i <= b; i++) {
            scanf ("%d", &a[i]);
        }
        LL f = -1, e = INF;
        printf ("Case #%d: ", cas++);
        while (f + 1 < e) {
            LL m = (f + e) >> 1;
            int tmp = solve (m);
            if (tmp == 0) break;
            if (tmp == -1) e = m;
            else f = m;
        }
        cout << endl;
    }
}
