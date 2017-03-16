#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>

#define pb push_back
#define mkp make_pair

using namespace std;
typedef long long ll;

const int maxn = 1005;

int cn[5],r,c,tot;
bool vis[maxn][maxn];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int g(int all)
{
    int res = 0;
    for(int i=0;i<5;i++)
        if(all)
        {
            res+=min(cn[i],all)*i;
            all-=min(cn[i],all);
        }
    return res;
}
void dye(int x,int y,int co)
{
    if(x>r)
        return;
    vis[x][y] = co;
    if(co)
        tot++;
    if(y==c)
        dye(x+1,1,vis[x][1]^1);
    else
        dye(x,y+1,co^1);
}
int sol(int n)
{
    for(int i=0;i<=r+1;i++)
        for(int j=0;j<=c+1;j++)
            vis[i][j] = 0;
    tot = 0;
    dye(1,1,1);
    if(n<=tot)
        return 0;
    memset(cn,0,sizeof(cn));
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        {
            if(vis[i][j])
                continue;
            int cnt = 0;
            for(int k=0;k<4;k++)
                if(vis[i+dx[k]][j+dy[k]])
                    cnt++;
            cn[cnt]++;
        }
    /*for(int i=0;i<5;i++)
    {
        printf("cn[%d]=%d\n",i,cn[i]);
    }*/
    int res = g(n-tot);
    for(int i=0;i<=r+1;i++)
        for(int j=0;j<=c+1;j++)
            vis[i][j] = 0;
    tot = 0;
    dye(1,1,0);
    if(n<=tot)
        return 0;
    memset(cn,0,sizeof(cn));
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
        if(vis[i][j])
            continue;
        int cnt = 0;
        for(int k=0;k<4;k++)
            if(vis[i+dx[k]][j+dy[k]])
                cnt++;
        cn[cnt]++;
    }
    res = min(res,g(n-tot));
    return res;
}
int main()
{
    int t,cas= 0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d%d%d",&r,&c,&n);
        printf("Case #%d: %d\n",++cas,sol(n));
    }
}
