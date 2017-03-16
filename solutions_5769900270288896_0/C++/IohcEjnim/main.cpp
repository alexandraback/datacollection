#include <stdio.h>

int t, tc;
int r, c, n;
int state[20][20];
int cnt, ans;

void back(int x, int y, int re)
{
    if (re == 0)
    {
        if (cnt < ans) ans = cnt;
        return;
    }
    if (x == r+1) return;
    
    if (y != c) back(x, y+1, re);
    else back(x+1, 1, re);
    
    cnt += state[x-1][y]+state[x][y-1];
    state[x][y] = 1;
    
    if (y != c) back(x, y+1, re-1);
    else back(x+1, 1, re-1);
    
    cnt -= state[x-1][y]+state[x][y-1];
    state[x][y] = 0;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("result.out", "w", stdout);
    scanf("%d", &t);
    for (tc = 1; tc <= t; tc++)
    {
        scanf("%d %d %d", &r, &c, &n);
        ans = 0x3fffffff;
        back(1, 1, n);
        printf("Case #%d: %d\n", tc, ans);
    }
}