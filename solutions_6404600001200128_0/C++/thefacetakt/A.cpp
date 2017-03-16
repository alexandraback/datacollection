#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 1; z <= T; ++z)
    {
        printf("Case #%d: ", z);
        int n;
        scanf("%d", &n);
        vector <int> m(n);
        long long sum = 0;
        long long secondAns = 0;
        long long maxDiff = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &m[i]);
            if (i)
                if (m[i - 1] > m[i])
                {
                    sum += m[i - 1] - m[i];
                    maxDiff = max(maxDiff, 1ll * (m[i - 1] - m[i]));
                }
        }
        for (int i = 1; i < n; ++i)
        {
            secondAns += min(m[i - 1] * 1ll, maxDiff);
        }
        printf("%lld %lld\n", sum, secondAns);
    }
    return 0;
}