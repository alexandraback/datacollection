#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-12
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int t,n,st[17][17],r,c,cur,ans;

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    For(cas,1,1+t)
    {
        cout<<"Case #"<<cas<<": ";
        cin>>r>>c>>n;
        ans=mod;
        For(mask,0,1<<(r*c)) if(__builtin_popcount(mask)==n)
        {
            //cout<<mask<<endl;
            reset(st,0);
            For(i,0,r*c) if((1<<i)&mask) st[i/c][i%c]=1;
            cur=0;
            //For(i,0,r) For(j,0,c) cout<<st[i][j]<<' ';
            //cout<<endl;
            For(i,0,r) For(j,1,c) if(st[i][j]&&st[i][j-1]) cur++;
            For(i,1,r) For(j,0,c) if(st[i][j]&&st[i-1][j]) cur++;
            ans=min(ans,cur);
        }
        cout<<ans<<endl;
    }
}
