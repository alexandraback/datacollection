#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 1000+10

ll a[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        ll k, n;
        scanf("%lld %lld", &k, &n);

        for (int i = 0; i < k; i++) {
            scanf("%lld", &a[i]);
        }

        ll lo = 1;
        ll hi = 1e14;
        ll ans;
        ll that;

        while (lo <= hi) {
            ll mid = (lo + hi) >> 1LL;
            ll tmp = 0;
            for (int i = 0; i < k; i++) {
                tmp += (mid / a[i]) + (bool) (mid % a[i]);
            }
            if (tmp >= n) {
                that = tmp;
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
////
//        printf(">> ans = %lld that = %lld\n", ans, that);

        priority_queue <pll> pq;

        for (int i = 0; i < k; i++) {
            pq.push({((ans-1) / a[i]) * a[i], i});
        }

        while (that > n) {
            that--;
//            printf("yes %lld %lld\n", pq.top().X, pq.top().Y);
            pll p = pq.top(); pq.pop();
            pq.push({p.X - a[p.Y], p.Y});
        }

        printf("Case #%d: %lld\n", cs + 1, pq.top().Y + 1LL);
    }


    return 0;
}







