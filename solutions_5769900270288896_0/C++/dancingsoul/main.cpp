#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int r , c , n;
int a[1 << 16] , f[16][16];
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
    int t , cas = 0;
    scanf ("%d" , &t);
    for (int i = 1 ; i < 1 << 16 ; i ++) {
        a[i] = a[i >> 1] + (i & 1);
    }
    while (t --) {
        scanf ("%d %d %d" , &r , &c , &n);
        int m = r * c;
        int ans = 1 << 20;
        for (int i = 0 ; i < 1 << m ; i ++) {
            if (a[i] != n) continue;
            memset (f , 0 , sizeof (f));
            for (int j = 0 ; j < m ; j ++) {
                if (i & (1 << j)) {
                    f[j / c][j % c] = 1;
                }
            }
            int ret = 0;
            for (int j = 0 ; j < r ; j ++) {
                for (int k = 0 ; k < c - 1 ; k ++) {
                    if (f[j][k] && f[j][k + 1])
                        ret ++;
                }
            }
            for (int k = 0 ; k < c ; k ++) {
                for (int j = 0 ; j < r - 1 ; j ++) {
                    if (f[j][k] && f[j + 1][k])
                        ret ++;
                }
            }
            ans = min (ans , ret);
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);

    }
    return 0;
}