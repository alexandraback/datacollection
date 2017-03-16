#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
const int N = 1100;
const ll inf = 10000000000000000ll;
ll a[N];
int n, m;

bool check(ll t) {
    ll num = 0;
    for (int i = 1; i <= n; i++)
        num += t / a[i] + 1;
    //cout<<t<<' '<<num<<endl;
    if (num >= m) return true;
    else return false;
}

ll cal(ll t) {
    if (t < 0) return 0;
    ll num = 0;
    for (int i = 1; i <= n; i++)
        num += t / a[i] + 1;
    return num;
}

ll bs(ll l, ll r) {
    ll res = r;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            res = min(res, mid);
            r = mid -1;
        } else {
            l = mid +1;
        }
    }
    return res;
}

int main() {
    int o, cas = 0;
    scanf("%d", &o);
    while (o--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        ll res;
        ll t = bs(0, inf);
        ll p = cal(t - 1);
        ll now = 0;
        cout<<t<<' '<<p<<endl;
        for (int i = 1; i <= n; i++) {
            if (t % a[i] == 0) {
                now ++;
                if (now == m - p) res = i;
            }
        }
        printf("Case #%d: %lld\n", ++cas, res);
    }
    return 0;
}