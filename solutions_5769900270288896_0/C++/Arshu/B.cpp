#include<bits/stdc++.h>
using namespace std;
int dp[17][17],r,c,n;

int func(int x,int y,int cnt,int hap)
{
    int R,S;

    if(cnt==n)
        return hap;
    if(y>=c+1)
        return func(x+1,1,cnt,hap);
    if(x>=r+1)
        return 10000;
    dp[x][y]=1;
    R=func(x,y+1,cnt+1,hap+dp[x-1][y]+dp[x][y-1]);
    dp[x][y]=0;
    S=func(x,y+1,cnt,hap);
    return min(R,S);
}

int t,X;
int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        X++;
        memset(dp,0,sizeof(dp));
        scanf("%d %d %d",&r,&c,&n);
        printf("Case #%d: %d\n",X,func(1,1,0,0));
    }
    return 0;
}
