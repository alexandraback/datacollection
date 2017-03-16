#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n,r,c,t,cases=0,ans;
bool live[55][55];
int dfs(int x,int y,int num)
{
    if(x>r)
    {
        if(num!=n)
            return 0;
        int tmp=0;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                if(live[i][j])
                {
                    if(live[i-1][j])
                        tmp++;
                    if(live[i][j-1])
                        tmp++;
                }
        ans=min(ans,tmp);
        return 0;
    }
    int X=x,Y=y+1;
    if(Y>c)
    {
        Y=1;
        X++;
    }
    dfs(X,Y,num);
    live[x][y]=1;
    dfs(X,Y,num+1);
    live[x][y]=0;
    return 0;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&r,&c,&n);
        ans=40*n;
        if(n==0)
        {
            printf("Case #%d: 0\n",++cases);
            continue;
        }
        memset(live,0,sizeof(live));
        dfs(1,1,0);
        printf("Case #%d: %d\n",++cases,ans);
    }
    return 0;
}
