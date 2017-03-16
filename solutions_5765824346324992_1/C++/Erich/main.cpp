#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1020];
ll gb;
int n,cas,tt;
ll m;
int ans;
ll gcd(ll x,ll y){
    if (y == 0) return x;
    return gcd(y,x%y);
}
ll getsum(ll x){
    ll res = 0;
    for (int i = 0; i < n; i++){
        res += x/a[i];
    }
    return res;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>tt;

    for (cas = 1; cas <= tt; cas++){
        cin>>n;
        cin>>m;
        for (int i = 0; i < n; i++) cin>>a[i];
        if (m<=n){
            cout << "Case #" << cas << ": "<<m<<endl;
            continue;
        }
        m-=n;


        ll l = 0, r = 1LL<<60;
        while (l<r){
            if (l+1 == r) break;
            ll mid = (l+r)>>1;
            ll count = getsum(mid);
            if (count<m) l = mid;
            else r = mid;
        }
        ll now = getsum(l);
        m -= now;
        for (int i = 0; i < n; i++){
            if (r % a[i] ==0){
                m--;
                if (m == 0){
                    ans = i+1;
                    break;
                }
            }
        }
        cout << "Case #" << cas << ": "<<ans<<endl;
    }

    return 0;
}
