#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

#define INF (1<<30)
#define mod 666013

using namespace std;
int cs, t, n, m, k, key, i, j, r[20][20][20];

int bck(int pas, int a[20], int n, int m, int t)
{
    int v[20];
    for(int i = 0; i <= 19; i++)
        v[i] = a[i];

    if(pas == 0)
    {
        int a[20][20] = {0};
        int i, j;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                a[i][j] = 1;
        for(i = 1; i <= t; i++)
        {
            int x = 0, y = 0;
            x = v[i] / m;
            y = v[i] % m;
            if(!y)
                y = m;
            else
                x++;
            a[x][y] = 0;
        }
        int sol = 0;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                if(a[i][j])
                {
                    if(a[i + 1][j])
                        sol++;
                    if(a[i][j + 1])
                        sol++;
                }
        return sol;
    }

    int sol = INF;
    for(v[pas] = v[pas + 1] + 1; v[pas] <= n * m - pas + 1; v[pas]++)
    {
        int x = bck(pas - 1, v, n, m, t);
        sol = min(sol, x);
    }
    return sol;
}

void solve(int n, int m, int k)
{
    if((n * m + 1) / 2 >= k)
        return;
    if(k == n * m)
    {
        r[n][m][k] = r[m][n][k] = n * (m - 1) + m * (n - 1);
        return;
    }
    int v[20];
    int i;
    for(i = 0; i < 20; i++)
        v[i] = 0;
    int sol = bck(n * m - k, v, n, m, n * m - k);
    r[n][m][k] = r[m][n][k] = sol;
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    for(i = 1; i <= 5; i++)
        for(j = i; j <= 16; j++)
        {
            if(i * j <= 16)
                for(k = 0; k <= i * j; k++)
                {
                   // printf("Solving %d %d %d\n", i, j, k);
                    solve(i, j, k);
                    //printf("%d %d %d : %d\n", i, j, k, r[i][j][k]);
                    //printf("Solved!\n\n");
                }
            else
                break;
        }
    scanf("%d", &t);
    for(cs = 1; cs <= t; cs++)
    {
        printf("Case #%d: ", cs);
        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", r[n][m][k]);
    }
    return 0;
}
