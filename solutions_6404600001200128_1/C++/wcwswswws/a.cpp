#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case #%d: ", t);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        int y = 0, z = 0, rate = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                y += a[i - 1] - a[i];
                rate = max(rate, a[i - 1] - a[i]);
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] >= rate) { z += rate; }
            else { z += a[i]; }
        }

        printf("%d %d\n", y, z);
    }
    return 0;
}
