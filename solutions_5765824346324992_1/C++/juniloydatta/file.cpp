#include<bits/stdc++.h>

#define xx first
#define yy second
#define LL long long
#define inf 100000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define MP make_pair
#define MX 10000000

using namespace std;
LL ar[1111];
vector<int>V;

int main(){
    freopen("fileIN.in","r",stdin);
    freopen("fileOUT.out","w",stdout);
    int test;
    cin>>test;
    for(int kase=1;kase<=test;kase++){
        LL b,n;
        cin>>b>>n;
        for(int i=0;i<b;i++) cin>>ar[i];
        LL lo=0ll,hi=1000000000ll*1000000ll;
        int ans;
        while(lo<=hi){
            LL mid=(lo+hi)/2ll;
            V.clear();
            LL tot=0ll;
            int free=0;
            for(int i=0;i<b;i++){
                tot+=(mid/ar[i]);
                if(mid%ar[i]==0) free++,V.pb(i+1);
                else tot++;
            }
            if(tot<n && tot+free>=n){
                LL rem=n-tot;
                ans=V[rem-1];
            }
            if(tot<n) lo=mid+1;
            else hi=mid-1;
        }
        cout<<"Case #"<<kase<<": "<<ans<<endl;
    }
    return 0;
}
