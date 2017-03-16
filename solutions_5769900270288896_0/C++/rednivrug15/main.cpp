/*Author:rednivrug15*/
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define MOD 1000000007

long long power(long long a,long long b,long long mod)
{
    long long ret=1;

    while(b)
    {
        if(b%2==1)
            ret=(ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}

long long int gcd(long long int a,long long int b)
{
    return b==0?a:gcd(b,a%b);
}
int dp[(1<<18)];

int convert(int x,int y,int c)
{
    return x*c+y;
}

int solve(int mask,int n,int r,int c)
{
    int counts=0,temps=mask;

    while(temps)
    {
        counts+=(temps%2);
        temps/=2;
    }

    if(counts==n) return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    dp[mask]=MOD;
    for(int i=0; i<r*c; i++)
    {
        if((mask&(1<<i)))
            continue;
        int ans=0;
        int xcur=(i/c);
        int ycur=i%c;

        if(xcur>0)
        {
           ans+=((mask&(1<<(convert(xcur-1,ycur,c))))>0);
        }
        if(ycur>0)
        {
            ans+=((mask&(1<<(convert(xcur,ycur-1,c))))>0);
        }
        if(xcur<r)
        {
            ans+=((mask&(1<<(convert(xcur+1,ycur,c))))>0);
        }
        if(ycur<c)
        {
            ans+=((mask&(1<<(convert(xcur,ycur+1,c))))>0);
        }
        dp[mask]=min(dp[mask],ans+solve((mask|(1<<i)),n,r,c));
    }
    //printf("%d %d--\n",mask,dp[mask]);
    return dp[mask];
}

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int cases=1; cases<=t; cases++)
    {
        int r,c,n;
        cin>>r>>c>>n;

        memset(dp,-1,sizeof dp);
        printf("Case #%d: %d\n",cases,solve(0,n,r,c));
    }

    return 0;
}
