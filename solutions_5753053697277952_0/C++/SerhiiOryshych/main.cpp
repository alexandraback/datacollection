#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int a[101];

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (true)
    {
        int x, y, k1 = 0, k2 = 0;

        if (a[0] > a[1])
        {
            x = 0;
            y = 1;
        }
        else
        {
            x = 1;
            y = 0;
        }

        if (a[0] == a[x]) k1++;
        if (a[1] == a[x]) k1++;
        for (int i = 2; i < n; i++)
        {
            if (a[i] > a[x])
            {
                y = x;
                x = i;
                k1 = 0;
            }
            else
            if (a[i] > a[y])
            {
                y = i;
            }

            if (a[i] == a[x])
                k1++;
            else
            if (a[i] > 0)
                k2++;
        }

        if (a[x] == 0) break;

        if (a[x] > a[y] && a[x] > 1)
        {
            printf("%c%c ", ('A' + x), ('A' + x));
            a[x] -= 2;
            continue;
        }

        if (a[x] > 0)
        {
            printf("%c", ('A' + x));
            a[x]--;

            if (k2 == 0 && k1 > 2)
            {
                printf(" ");
                continue;
            }
        }
        if (a[y] > 0)
        {
            printf("%c", ('A' + y));
            a[y]--;
        }

        printf(" ");
    }
    printf("\n");
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }
}
