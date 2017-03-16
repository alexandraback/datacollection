#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 26;

int n;
int cnt[N];

int get_sum()
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += cnt[i];
    return s;
}

int get_max()
{
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, cnt[i]);
    return mx;
}

bool good()
{
    return 2 * get_max() <= get_sum();
}

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &cnt[i]);

    while (get_sum() > 0)
    {
        bool done = false;
        for (int i = 0; i < n && !done; i++)
            for (int j = i + 1; j < n && !done; j++)
            {
                if (cnt[i] == 0 || cnt[j] == 0)
                    continue;
                cnt[i]--;
                cnt[j]--;
                if (good())
                {
                    printf("%c%c ", (char)('A' + i), (char)('A' + j));
                    done = true;
                    break;
                }
                cnt[i]++;
                cnt[j]++;
            }
        for (int i = 0; i < n && !done; i++)
        {
            if (cnt[i] == 0)
                continue;
            cnt[i]--;
            if (good())
            {
                printf("%c ", (char)('A' + i));
                done = true;
                break;
            }
            cnt[i]++;
        }
        assert(done);
    }

    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}
