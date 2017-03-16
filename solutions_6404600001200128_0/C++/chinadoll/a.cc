#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    const int N = 1005;
    int T, n, m[N];
    scanf("%d", &T);
    for (int tst = 1; tst <= T; ++tst)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &m[i]);
        int y = 0, z = 0, gap = -1;
        for (int i = 1; i < n; ++i)
        {
            if (m[i-1] > m[i])
                y += m[i-1] - m[i];
            gap = max(gap, m[i-1] - m[i]);
        }
        for (int i = n - 2; i >= 0; --i)
            z += min(gap, m[i]);
        printf("Case #%d: %d %d\n", tst, y, z);
    }
    return 0;
}
