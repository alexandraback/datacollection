#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int A[20][20];
int res;
int T,r,c,n;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
void dfs(int now,int cnt)
{
    if(cnt==0)
    {
        int t=0;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                for(int k=0;k<4&&A[i][j];k++)
                        if(A[i+dx[k]][j+dy[k]]) t++;
        t/=2;
        res=min(res,t);
        return ;
    }
    if(now>r*c) return;
    int x=(now-1)/c+1,y=(now-1)%c+1;
    A[x][y]=1;
    dfs(now+1,cnt-1);
    A[x][y]=0;
    dfs(now+1,cnt);

}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d%d%d",&r,&c,&n);
        memset(A,0,sizeof(A));
        res=9999999;
        dfs(1,n);
        printf("Case #%d: %d\n",kase,res);
    }
    return 0;
}
