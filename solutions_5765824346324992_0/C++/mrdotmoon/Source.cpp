#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

__int64 N, B, M[1001];

__int64 done(__int64 mid)
{
    __int64 res = 0;
    for (int i = 0; i < (int)B; i++) res += mid / M[i];
    return res;
}

__int64 doing(__int64 mid)
{
    __int64 res = 0;
    for (int i = 0; i < (int)B; i++)
    {
        if (mid % M[i] == 0) res += mid / M[i];
        else res += 1 + mid / M[i];
    }
    return res;
}


void _main()
{
    scanf("%lld%lld", &B, &N);
    for (int i = 0; i < B; i++) scanf("%lld", &M[i]);

    if (N <= B)
    {
        printf("%lld\n", N);
        return;
    }

    __int64 l = 0, r = 1000000000000000LL;

    __int64 found = 0;

    while (l <= r)
    {
        __int64 mid = (l + r) / 2;
        if (doing(mid + 1) >= N)
        {
            if (doing(mid) < N)
            {
                found = mid;
                break;
            }
            else
            {
                r = mid - 1;
            }
        }
        else
        {
            l = mid + 1;
        }
    }

    __int64 res = 0;
    __int64 pos = N - doing(found);
    for (int i = 0; i < (int)B; i++)
    {
        if (found % M[i] == 0)
        {
            if (pos == 1)
            {
                res = i + 1;
                break;
            }
            else
            {
                pos--;
            }
        }
    }

    printf("%lld\n", res);
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        printf("Case #%d: ", cases);
        _main();
    }
}