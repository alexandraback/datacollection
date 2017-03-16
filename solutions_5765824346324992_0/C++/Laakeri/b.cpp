#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int b;
ll m[10101];

ll inf=1e9;

ll serv(ll t){
    ll r=0;
    for (int i=0;i<b;i++){
        r+=t/m[i]+1ll;
        if (r>inf) return r;
    }
    return r;
}

int main(){
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout<<"Case #"<<tc<<": ";
        ll n;
        cin>>b>>n;
        for (int i=0;i<b;i++){
            cin>>m[i];
        }
        ll mi=0;
        ll ma=1e16;
        while (mi<=ma){
            ll mid=(mi+ma)/2ll;
            if (serv(mid)>=n){
                ma=mid-1ll;
            }
            else{
                mi=mid+1ll;
            }
        }
        ll k=mi;
        n-=serv(k-1ll);
        for (int i=0;i<b;i++){
            if (k%m[i]==0ll){
                n--;
            }
            if (n==0){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}
