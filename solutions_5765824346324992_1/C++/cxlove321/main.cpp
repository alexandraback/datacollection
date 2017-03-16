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
int n , a[N] , m;

bool check (LL t) {
    LL cut = 0;
    for (int i = 0 ; i < n ; i ++) {
        cut += (t + a[i] - 1) / a[i];
    }
    return cut >= m;
}
vector <pair <LL , int> > v;
int gao (LL t) {
    v.clear ();
    LL cut = m;
    for (int i = 0 ; i < n ; i ++) {
        cut -= (t - 1) / a[i];
        v.push_back (make_pair ((t - 1) / a[i] * a[i] , i + 1));
    }
    sort (v.begin () , v.end ());
    for (int i = 0 ; i < n ; i ++) {
        cut --;
        if (cut == 0) {
            return v[i].second;
        }
    }
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);  
    int t , cas = 0;scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &m);
        for (int i = 0 ; i < n ; i ++)
            scanf ("%d" , a + i);
        LL low = 0 , high = (LL)1e15 , mid , ans;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (check (mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        printf ("Case #%d: %d\n" , ++ cas , gao (ans));
    }
    return 0;
}