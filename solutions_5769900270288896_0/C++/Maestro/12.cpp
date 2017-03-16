#include<bits/stdc++.h>
using namespace std;
int a[50][50],r,c,cnt,f,t,ans;
int calc(){
    int res=0;
    for(int i=1;i<=r;++i)
    for(int j=1;j<=c;++j)
    res+=a[i][j]*(a[i+1][j]+a[i-1][j]+a[i][j+1]+a[i][j-1]);
    return res;
}
void dfs(int x,int y){
    if(x==r+1){
        if(cnt==f)ans=min(ans,calc());
        return;
    }
    a[x][y]=1;
    ++cnt;
    if(y==c)dfs(x+1,1);
    else dfs(x,y+1);
    a[x][y]=0;
    --cnt;
    if(y==c)dfs(x+1,1);
    else dfs(x,y+1);
}
void solve(){
    ans=91919;
    dfs(1,1);
}
main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int t;
    cin>>t;
    for(int tt=1;tt<=t;++tt){
        cin>>r>>c>>f;
        solve();
        cout<<"Case #"<<tt<<": "<<ans/2<<endl;
    }
}
