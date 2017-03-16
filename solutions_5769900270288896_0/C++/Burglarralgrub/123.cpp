#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 20
using namespace std;
int malt[MAXN][MAXN];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int num;
int ans;
bool inMap(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else
        return true;
}
void print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(j != 0) printf(" ");
            printf("%d", malt[i][j]);
        }
        puts("");
    }
    puts("");
}
void solve()
{
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(malt[i][j])
            {
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if(inMap(nx, ny) && malt[nx][ny]) res++;
                }
            }
        }
    }
    res /= 2;
    ans = min(ans, res);
}
void dfs(int x, int y)
{
    //print();
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) sum += malt[i][j];
    }
    if(sum >= num)
    {
        //print();
        solve();
        return;
    }
    if(y >= m)
    {
        x++;
        y = 0;
    }
    if(x >= n) return;
    malt[x][y] = 1;
    dfs(x, y + 1);
    malt[x][y] = 0;
    dfs(x, y + 1);
}
int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("outB.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int ii = 1; ii <= t; ii++)
    {
        ans = 100000000;
        scanf("%d%d%d", &n, &m, &num);
        //memset(malt, 0, sizeof(malt));
        //print();
        dfs(0, 0);
        printf("Case #%d: %d\n", ii, ans);
    }
    return 0;
}
