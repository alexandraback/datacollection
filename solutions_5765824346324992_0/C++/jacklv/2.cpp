#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n;
int a[1100];
typedef long long ll;
ll l,r,mid;
ll get(ll p){
    ll ans=0;
    for (int i=1;i<=m;i++)
    ans+=p/a[i]+1;
    return ans;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1;tt<=T;tt++){
        scanf("%d%d",&m,&n);
        for (int i=1;i<=m;i++) scanf("%d",&a[i]);
        l=0; r=1ll<<60;
        while (true){
            mid=(l+r)/2;
            if (get(mid)>=n) r=mid; else l=mid+1;
            if (l>=r) break;
        }
        int t=0;
        //for (int i=1;i<=m;i++) t+=l/a[i];
        t=n-get(l-1);
        //cout<<t<<' '<<n<<' '<<l<<endl;
        //if (tt==7) cout<<t<<' '<<n<<' '<<get(l)<<endl;
        //cout<<l<<' '<<r<<endl;
        for (int i=1;i<=m;i++)
        if (l%a[i]==0) {
                t--;
                if (t==0){
                    printf("Case #%d: %d\n",tt,i);
                    break;
                }
        }
    }
}
