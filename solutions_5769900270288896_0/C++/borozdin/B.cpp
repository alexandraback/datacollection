#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 20;
const int INF = (int) 1e9;

bool bit(int a, int b)
{
    return (a & (1 << b)) != 0;
}

int r, c, n;
bool occ[N][N];
int ans[N][N][N];

void solve()
{
    int cnt = r * c;
    for (int mask = 0; mask < (1 << cnt); mask++)
    {
        memset(occ, 0, sizeof(occ));
        int bits = 0;
        for (int i = 0; i < cnt; i++)
            if (bit(mask, i))
            {
                bits++;
                occ[i / c][i % c] = true;
            }
        int tot = 0;
        for (int i = 0; i < r - 1; i++)
            for (int j = 0; j < c; j++)
                if (occ[i][j] && occ[i + 1][j])
                    tot++;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c - 1; j++)
                if (occ[i][j] && occ[i][j + 1])
                    tot++;
        ans[r][c][bits] = min(ans[r][c][bits], tot);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                ans[i][j][k] = INF;
    for (int i = 1; i <= 16; i++)
        for (int j = 1; j <= 16; j++)
            if (i * j <= 16)
                for (int k = 0; k <= i * j; k++)
                {
                    r = i;
                    c = j;
                    n = k;
                    solve();
                }

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d%d", &r, &c, &n);
        printf("Case #%d: %d\n", i + 1, ans[r][c][n]);
    }

    eprintf("time = %.3lf\n", (double) clock() / CLOCKS_PER_SEC);

    return 0;
}
