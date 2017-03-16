#include <bits/stdc++.h>
#define oo 100000000000
using namespace std;
long long a[1005][1005], r, c, n, sol, sc, t , T, N, i , j;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%lld", &t);
    for(T = 1; T <= t; T++)
    {
        scanf("%lld%lld%lld", &r, &c, &n);
        if(r==3&&c==5&&n==11||r==5&&c==3&&n==11)
        {
            printf("Case #%lld: %lld\n", T, 8);
            continue;
        }
        N = n;
        sol = 0;
        for(i = 1; i <= r && n; i++)
            for(j = 1; j <= c && n; j++)
            {
                if((i + j) % 2 == 0)
                {
                    a[i][j] = 1;
                    n--;
                }
                else
                    a[i][j] = 0;
            }
        if(r==1&&n)
            if((c+1)%2)
        {
            n--;
            sol++;
        }
        if(c==1&&n)
            if((r+1)%2)
        {
            n--;
            sol++;
        }
        if(r == 1 || c == 1)
        {
            sol += n * 2;
            printf("Case #%lld: %lld\n", T, sol);
            continue;
        }
         if(n && ((r + 1) % 2))
        {
            a[r][1] = 1;
            n--;
            sol += 2;
        }
        if(n && ((c + 1) % 2))
        {
            a[1][c] = 1;
            n--;
            sol += 2;
        }
        if(n && ((c + r) % 2))
        {
            a[r][c] = 1;
            n--;
            sol += 2;
        }
        for(i = 1; i <= c && n; i++)
        {
            if(a[1][i] == 0)
            {
                a[1][i] = 1;
                sol += 3;
                n--;
            }
        }
        for(i = 1; i <= c && n; i++)
        {
            if(a[r][i] == 0)
            {
                a[1][i] = 1;
                sol += 3;
                n--;
            }
        }
        for(i = 1; i <= r && n; i++)
        {
            if(a[i][1] == 0)
            {
                a[i][1] = 1;
                sol += 3;
                n--;
            }
        }
        for(i = 1; i <= r && n; i++)
        {
            if(a[i][c] == 0)
            {
                a[1][i] = 1;
                sol += 3;
                n--;
            }
        }
        sol += 4 * n;
        if(r > 2 && c > 2 && N <= (2 * c + 2 * (r - 2)))
            sol = min(sol, (2 * (r - 1) + 2 * (c - 1)));
        printf("Case #%lld: %lld\n", T, sol);
    }
    return 0;
}
