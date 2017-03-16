#include <stdio.h>
#include <stdint.h>
#include <algorithm>

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
    uint64_t max = std::max(a, b);
    uint64_t min = std::min(a, b);
    if (max % min != 0)
    {
        return gcd(min, max % min);
    }
    return min;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++)
    {
        int b, n;
        scanf("%d%d", &b, &n);
        int m[b + 1], a[b + 1];
        uint64_t lcm = 1;
        for (int i = 1; i <= b; i++)
        {
            scanf("%d", &m[i]);
            lcm = lcm * m[i] / gcd(lcm, m[i]);
            a[i] = 0;
        }
        int round = 0;
        for (int i = 1; i <= b; i++)
        {
            round += lcm / m[i];
        }
        n = n % round;
        if (n == 0)
        {
            n = round;
        }
        int idx = 0;
        for (int i = 1; i <= n; i++)
        {
            uint64_t best_score = 1ULL << 63;
            for (int j = 1; j <= b; j++)
            {
                uint64_t score = (uint64_t)m[j] * a[j];
                if (score < best_score)
                {
                    idx = j;
                    best_score = score;
                }
            }
            a[idx]++;
        }
        printf("Case #%d: %d\n", cases, idx);
    }
    return 0;
}
