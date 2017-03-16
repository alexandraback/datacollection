#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n;
int table[16][16];
int r,c;
int ans;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool intable(int x,int y)
{
    if(x<r&&x>=0&&y<c&&y>=0)
        return true;
    return false;
}
void dfs(int x,int y,int num)
{
    if(x==r)
    {
        if(num!=0)
            return ;
        else
        {
            int term=0;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if(table[i][j]==1)
                    {
                        for(int k=0;k<4;k++)
                        {
                            if(intable[i+dx[k]][j+dy[k]]&&table[i+dx[k]][j+dy[k]]==1)
                                term++;
                        }
                    }
                }
            }
            term/=2;
            ans=min(ans,term);
            return ;
        }
    }
    table[x][y]=1;
    if(y==c-1)
        dfs(x+1,0,num-1);
    else
        dfs(x,y+1,num-1);
    table[x][y]=0;
    if(y==c-1)
        dfs(x+1,0,num);
    else
        dfs(x,y+1,num);
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        ans=9999999;
        scanf("%d%d%d",&r,&c,&n);
        dfs(0,0,n);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
