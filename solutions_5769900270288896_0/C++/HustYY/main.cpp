#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int n,r,c,ans,grid[17][17];

void dfs(int i,int j,int k,int sum)
{
    if (k>n||sum>=ans) return;
    if (j>c) j=1,++i;
    if (i>r)
    {
        if (k==n) ans=sum;
        return;
    }
    dfs(i,j+1,k,sum);
    sum+=grid[i-1][j]==1?1:0;
    sum+=grid[i][j-1]==1?1:0;
    grid[i][j]=1;
    dfs(i,j+1,k+1,sum);
    grid[i][j]=0;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d%d%d",&r,&c,&n);
        ans=r*c*4;
        dfs(1,1,0,0);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
