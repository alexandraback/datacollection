#include <bits/stdc++.h>
#define ll long long
#define pll  pair<ll,ll>

using namespace std;

ll b,m[1005],n;

priority_queue<pll> pq;
ll r[10000005];

ll lcm(ll x,ll y){

    ll g=__gcd(x,y);

    return (x/g)*y;

}

int main()
{
    ll i,j,k,t,T,ret=0,l;

    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.txt","w",stdout);

    cin>>T;

    for(t=1;t<=T;t++)
    {

        cin>>b>>n;

        n--;

        for(i=1;i<=b;i++) cin>>m[i];

        for(i=l=1;i<=b;i++) l=lcm(l,m[i]);

        while(!pq.empty()) pq.pop();

        for(i=1;i<=b;i++) pq.push(make_pair(0,-i));


        ll current=0;
        pll tmp;

        while(!pq.empty() && current<=n){

            tmp=pq.top();

            pq.pop();

            k=tmp.first*-1;
            i=tmp.second*-1;

            r[current]=i;
            current++;

            if(k+m[i] < l){
                pq.push(make_pair( -(k+m[i]) , -i  ) );
            }
        }

        printf("Case #%d: ",t);
        cout<<r[n%current]<<endl;

    }

    return 0;
}
