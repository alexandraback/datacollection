#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
ll mpow(ll a, ll n,ll mod)
{ll ret=1;ll b=a;while(n) {if(n&1)
    ret=(ret*b)%mod;b=(b*b)%mod;n>>=1;}
return (ll)ret;
}
using namespace std;
#define sd(x) scanf("%d",&x)
#define pd(x) printf("%d",x)
#define mem(x,a) memset(x,a,sizeof(x))
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define N (int)5e3+5
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<pair<int,char> > v;
    int tot=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(mp(x,i+'A'));
        tot+=x;
    }
    sort(v.begin(),v.end());
    while(tot){
        int x=v[n-1].fi;
        char p=v[n-1].se;
        int y=v[n-2].fi;
        char q=v[n-2].se;
        int z=(n-3>=0?v[n-3].fi:0);
        vector<char> evac;
        if(max(max(x-1,y-1),z)<=(tot-2)/2){
            evac.pb(p);
            evac.pb(q);
            tot-=2;
            v[n-1].fi--;
            v[n-2].fi--;
        }
        else if(max(y,x-1)<=(tot-1)/2){
            if(max(y,x-2)<=(tot-2)/2){
               evac.pb(p);
               v[n-1].fi--;
               tot--;
            }
            v[n-1].fi--;
            tot--;
            evac.pb(p);
        }
        else{
            printf("bitch");
        }
        sort(v.begin(),v.end());
        for(int i=0;i<evac.size();i++)
            cout<<evac[i];
        printf(" ");
    }
    printf("\n");
}
int main(){
   freopen("input.IN","r",stdin);
   freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   for(int i=1;i<=t;i++){
       printf("Case #%d: ",i);
       solve();
   }
   return 0;
}
