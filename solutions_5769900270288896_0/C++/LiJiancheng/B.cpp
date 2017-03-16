#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define N 17
bool v[N][N];
int r, c, n;

void pp()
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
            putchar(v[i][j] ? '1' : '0');
        puts("");
    }
    puts("");
}

int solve()
{
    scanf("%d%d%d", &r, &c, &n);
    int m = r * c;
    int mm = 1 << m;
    if (n == 0)
        return 0;
    int ans = (r - 1) * c + r * (c - 1);
    for (int i = 1; i < mm; ++i)
    {
        int s = 0;
        for (int j = 0; j < m; ++j)
            if ((i >> j) & 1)
                ++s;
        if (s != n)
            continue;
        memset(v, 0, sizeof(v));
        for (int j = 0; j < m; ++j)
            if ((i >> j) & 1)
                v[j / c][j % c] = 1;
        s = 0;
        for (int x = 0; x < r; ++x)
            for (int y = 0; y < c; ++y)
                if (v[x][y])
                    s += v[x + 1][y] + v[x][y + 1];
        ans = min(ans, s);
    }
    return ans;
}

int main()
{
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d: ", tt);
        printf("%d\n", solve());
    }
    return 0;
}