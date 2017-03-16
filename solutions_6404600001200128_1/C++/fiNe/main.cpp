#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 1010
#define inf 0x3f3f3f3f
#define pre m[i - 1]

int n, m[maxn], x, y, maxd;

int main()
{
    freopen("A-large (1).in", "r", stdin);
    freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        x = y = 0;
        maxd = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &m[i]);
        }
        for(int i = 1; i < n; i++)
        {
            x += (pre - m[i]) > 0 ? pre - m[i] : 0;
            if(maxd < pre - m[i])
                maxd = pre - m[i];
        }

        for(int i = 0; i < n - 1; i++)
        {
            y += m[i] - maxd >= 0 ? maxd : m[i];
        }
        printf("Case #%d: %d %d\n", Case, x, y);
    }
    return 0;
}
