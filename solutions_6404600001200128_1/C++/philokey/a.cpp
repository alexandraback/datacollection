#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 100005;
int n;
int a[MAXN];
int main() {
    freopen("/home/qitaishui/practice/gcj2015/in.txt", "r", stdin);
    freopen("/home/qitaishui/practice/gcj2015/a.out", "w", stdout);
    int cas;
    int x, y;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ++ca) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        x = y = 0;
        int mp = 0;

        for (int i = 1; i < n; ++i) {
            mp = max(mp, a[i - 1] - a[i]);
            x += max(0, a[i -  1] - a[i]);
        }
        //cout<<mp<<endl;
        for (int i = 0; i < n - 1; ++i) {
            y += min(a[i], mp);
        }
        printf("Case #%d: %d %d\n",ca, x, y);

    }
    return 0;
}
