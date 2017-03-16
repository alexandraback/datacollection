#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>


using namespace std;

const int INF=0x3f3f3f3f;

const int N=200;
const int prime=1000000007;
string a,b;
int d[N][N];
int dp(int i,int j)
{
    if(d[i][j]!=-1)
    return d[i][j];
    if(i==a.size()&&j==b.size())
    {
        return (d[i][j]=0);
    }
    d[i][j]=INF;

    if(i<a.size()&&j<b.size()&&a[i]==b[j])
    {
        return (d[i][j]=dp(i+1,j+1));
    }
    if(i>0&&i<a.size()&&a[i-1]==a[i])
    d[i][j]=min(d[i][j],dp(i+1,j)+1);
    if(i>0&&j<b.size()&&a[i-1]==b[j])
    d[i][j]=min(d[i][j],dp(i,j+1)+1);
    if(j>0&&j<b.size()&&b[j-1]==b[j])
    d[i][j]=min(d[i][j],dp(i,j+1)+1);
    if(j>0&&i<a.size()&&b[j-1]==a[i])
    d[i][j]=min(d[i][j],dp(i+1,j)+1);
    return d[i][j];

}
int main()
{
    //freopen("data.txt","r",stdin);
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1; ca<=T; ++ca)
    {
        printf("Case #%d: ",ca);
        int n;
        cin>>n;
        cin>>a>>b;
        memset(d,-1,sizeof(d));
        int ans=dp(0,0);
        if(ans==INF)
        printf("Fegla Won\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}
