#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int r,c,n;
int ans;
bool map[16][16];
void dfs(int x, int y,int remain,int count)
{
    if (remain == 0)
    {
        if (count < ans) ans = count;
        return;
    }
    int tx = x;
    int ty = y + 1;
    if (ty == c)
    {
        ty = 0; tx = x+1;
    }
    if (r*c-(x*c+y) > remain)
    {
        dfs(tx,ty,remain,count);
    }
    map[x][y] = true;
    int cc = 0;
    if (x != 0) if (map[x-1][y]) cc++;
    if (y != 0) if (map[x][y-1]) cc++;
    dfs(tx,ty,remain-1,count+cc);
    map[x][y] = false;
}

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.txt","w",stdout);
    int times;
    cin >> times;
    for (int t = 0; t < times; t++)
    {
        memset(map,false,sizeof(map));
        scanf("%d %d %d",&r,&c,&n);
        ans = r*c*4;
        dfs(0,0,n,0);
        printf("Case #%d: %d\n",t+1,ans);
    }
}
