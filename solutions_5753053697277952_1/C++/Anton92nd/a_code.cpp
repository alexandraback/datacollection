#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int const maxN = 26;

int cnt[maxN], sum, n;

void solve()
{
    if (n == 2)
    {
        vector<int> ar;
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] > 0)
            {
                ar.push_back(i);
            }
        }
        int a = ar[0], b = ar[1];
        for (int i = 0; i < cnt[a]; i++)
        {
            printf("%c%c ", 'A' + a, 'A' + b);
        }
        printf("\n");
        return;
    }
    while (sum > 2)
    {
        int indMax = -1;
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] > 0 && (indMax < 0 || cnt[indMax] < cnt[i]))
            {
                indMax = i;
            }
        }
        printf("%c ", 'A' + indMax);
        cnt[indMax]--;
        sum--;
    }
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] > 0)
        {
            ar.push_back(i);
        }
    }
    printf("%c%c\n", 'A' + ar[0], 'A' + ar[1]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int q;
    scanf("%d", &q);
    for (int t = 1; t <= q; ++t)
    {
        scanf("%d", &n);
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            sum += x;
            cnt[i] = x;
        }
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}