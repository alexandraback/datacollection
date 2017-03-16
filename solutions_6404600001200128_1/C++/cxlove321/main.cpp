#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1005;
const int MOD = 100007;
int n , a[N];

int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);  
    int t , cas = 0;scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++)
            scanf ("%d" , a + i);
        int ans = 0 , rate = 0 , ret = 0;
        for (int i = 1 ; i < n ; i ++) {
            if (a[i] < a[i - 1]) {                
                ans += a[i - 1] - a[i];
                rate = max (rate , a[i - 1] - a[i]);
            }
        }
        for (int i = 1 ; i < n ; i ++) {
            ret += min (rate , a[i - 1]);
        }
        printf ("Case #%d: %d %d\n" , ++ cas , ans , ret);
    }
    return 0;
}