#include<stdio.h>
#include<cstdlib>
#include<algorithm>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> par;
ll mm[1002];
ll b,n;
par givemen(ll t)
{
    //if(t==0) return par(0,0);
    par ret;
    ret.f=0;
    ret.s=b;
    for(ll i=0;i<b;i++){
        ret.f+= (t-1)/mm[i] +1;
        if(t%mm[i]==0&&i<ret.s){
            ret.s=i;
        }
    }
    return ret;
}
int main()
{
    freopen("b.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll t;
    scanf("%I64d",&t);
    for(ll kase=1;kase<=t;kase++){
        scanf("%I64d%I64d",&b,&n);
        for(ll i=0;i<b;i++){
            scanf("%I64d",&mm[i]);
        }
        ll l,r,mid;
        l=0;r=1;
        while(givemen(r).f<n) r*=2;
        par p;
        while(l+1<r){
            mid=l+r>>1;
            p=givemen(mid);
            if(p.f<=n-1){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        
        
        while(1){
        p=givemen(l);
    for(ll i=0;i<b;i++){
        if(p.f==n) break;
        if(l%mm[i]==0){
            p.s=i;
            p.f++;
        }
    }
        if(p.f==n) break;
        l++;
        }
        
        printf("Case #%I64d: %I64d\n",kase,p.s+1);
    }
}
