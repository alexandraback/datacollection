#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int tt = 3333;
typedef long long ll;

struct point
{
    int x, y, num;
    bool p;
    bool operator < (const point& b) const
    {
        return x < b.x || (x == b.x && y > b.y);
    }
} v[tt], g[tt], h[tt], stk[tt];
bool pd[tt],otb[tt];
int ans[tt];

bool f(point a, point b, point c)
{
    return (b.x-a.x)*ll(c.y-b.y) > (b.y-a.y)*ll(c.x-b.x);
}

void ck(int n)
{
    sort(h, h+n);
    int cnt = 0;
    stk[cnt++] = h[0];
    for (int i = 1; i < n; ++i)
    {
        for (;cnt > 1 && f(stk[cnt-2],stk[cnt-1],h[i]); cnt--);
        stk[cnt++] = h[i];
    }
    for (int i = 0; i < cnt; ++i)
        otb[stk[i].num] = true;
}

void checker(int n, int t = 0)
{
    point mp = g[0];
    int cnt = 0, mixx = 1<<25, maxx = -(1<<25);
    for (int i = 0; i < n; ++i)
    {
        if (g[i] < mp) mp = g[i];
        mixx = min(mixx, g[i].x);
        maxx = max(maxx, g[i].x);
    }
    for (int i = 0; i < n; ++i)
    {
        h[cnt++] = g[i];
        //if (g[i].y >= mp.y) h[cnt++] = g[i];
    }
    for (int i = 0; i < n; ++i)
        if (g[i].x == mixx || g[i].x == maxx) otb[g[i].num] = true;
    ck(cnt);
    if (t == 0)
    {
        for (int i = 0; i < n; ++i)
            g[i].y = -g[i].y;
        checker(n,1);
    }
}

void check(int n)
{
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (pd[i])
        {
            g[res++] = v[i];
            otb[v[i].num] = false;
        }
    }
    if (res == 0) return;
    checker(res);
    for (int i = 0; i < n; ++i)
    {
        if (pd[i] && otb[v[i].num])
        {
            /*
            if (n - res < ans[v[i].num])
            {
                cerr << v[i].num << endl;
                for (int j = 0; j < n; ++j)
                    cerr << pd[j] << ' ';
                cerr << endl;
            }*/
            ans[v[i].num] = min(ans[v[i].num],n-res);
        }
    }
}

void search(int n, int x)
{
    if (x == n)
    {
        check(n);
        return;
    }
    pd[x] = true;
    search(n,x+1);
    pd[x] = false;
    search(n,x+1);
}

int main(int argv, char** argc)
{
    int T;
    if (argv > 1)
        freopen(argc[1], "r", stdin);
    if (argv > 2)
        freopen(argc[2], "w", stdout);
    scanf("%d",&T);
    for (int t = 1; t <= T; ++t)
    {
        int n;
        printf("Case #%d:\n", t);
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &v[i].x, &v[i].y);
            v[i].num = i;
            ans[i] = n;
        }
        memset(pd, true, sizeof pd);
        search(n,0);
        for (int i = 0; i < n; ++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}