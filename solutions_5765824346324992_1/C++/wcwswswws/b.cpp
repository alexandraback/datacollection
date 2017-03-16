#include <stdio.h>

int barbers[1000];

bool check(int b, long long n, long long t)
{
    long long sum = 0;
    for (int i = 0; i < b; i++)
    {
        sum += (t / barbers[i]);
        if (t % barbers[i] != (long long)0) { sum++; }
    }
    return (sum >= n);
}

int Work(int b, long long n)
{
    if (n == 1) { return 1; }
    if (n <= b) { return n; }

    long long l = 0, r = (long long)n * (long long)100000;
    while (l < r)
    {
        long long mid = (l + r) / (long long)2;
        if (check(b, n, mid)) { r = mid; }
        else { l = mid + (long long)1; }
    }
    for (int i = 0; i < b; i++)
    {
        if (barbers[i] == 1)
        {
            n -= l - (long long)1;
        } else
        {
            n -= l / (long long)barbers[i];
            if (l % (long long)barbers[i] > (long long)1) { n--; }
        }
    }

    for (int i = 0; i < b; i++)
    {
        if ((l % (long long)barbers[i] == (long long)1) || (barbers[i] == 1))
        {
            if (n == 1) { return  i + 1; }
            n--;
        }
    }
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        int b, n;
        scanf("%d%d", &b, &n);
        for (int i = 0; i < b; i++) { scanf("%d", &barbers[i]); }
        printf("Case #%d: %d\n", t, Work(b, n));
    }
    return 0;
}
