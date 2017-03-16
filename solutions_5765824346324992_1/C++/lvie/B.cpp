#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define foru(i, a, b) for(int i=(a); i<=(b); i++)
const int N = 1010;


int n, m, p;
ll a[N];

ll cal(ll t, int x){
    ll tim = t * a[x];
    ll sum = t + 1;
    foru(i, 1, x-1){
        if (tim % a[i] == 0) sum += tim/a[i] + 1ll;
            else sum += (tim/a[i]) + 1;
    }
    foru(i, x+1, n)
        if (tim % a[i] == 0) sum += tim/a[i];
            else sum += (tim/a[i]) + 1;
    return sum;
}

bool get(int x){
    ll l = 0, r = m, sum, tmp;
    while (l <= r){
        ll mid = (l + r) >> 1;
        sum = cal(mid, x);
        if (sum <= m){
            tmp = sum;
            l = mid+1;
        }else r = mid-1;
    }
    return (tmp == m);
}

int main(){
    freopen("B.txt", "r", stdin);
    freopen("B2.txt", "w", stdout);
    int T, cas = 0; scanf("%d", &T);
    while (T--){
        scanf("%d %d", &n, &m);
        foru(i, 1, n) scanf("%lld", &a[i]);
        foru(i, 1, n)
            if (get(i)) {p = i; break;}
        printf("Case #%d: %d\n", ++cas, p);
    }
    return 0;
}
