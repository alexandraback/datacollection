#include <cstdio>

long long count(long long time, int a[], int n)
{
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += time / a[i];
    return sum + n;
}

int main()
{
    const int B = 1005;
    int T, b, m[B];
    long long n;
    scanf("%d", &T);
    for (int tst = 1; tst <= T; ++tst)
    {
        scanf("%d%lld", &b, &n);
        for (int i = 1; i <= b; ++i)
            scanf("%d", &m[i]);
        long long begin = 0, end = n * m[1];
        while (begin < end)
        {
            long long pos = (begin + end) >> 1, who = count(pos, m, b);
            if (who < n)
                begin = pos + 1;
            else
                end = pos;
        }
        long long remain = count(begin, m, b) - n;
        for (int i = b; i && remain >= 0; --i)
        {
            if (begin % m[i] == 0)
            {
                if (remain-- == 0)
                    printf("Case #%d: %d\n", tst, i);
            }
        }
    }
    return 0;
}
