#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n , c , r;

typedef long long ll;
#define int ll
int dye_odd()
{
    int n = ::n;
    int ans = 0;

    int c0 = (r * c) >> 1;
    if (n <= c0)
        return 0;
    n -= c0;

    int c2 = ((r & c) & 1) ? 4 : 2;
    if (n <= c2)
        return n * 2;
    n -= c2;
    ans += 2 * c2;

    int c3 = 0;
    int i = 0;
        for(i = 1; i < r - 1; ++ i) {
            if (!(i & 1)) ++ c3;
            if (!((i + c - 1) & 1)) ++ c3;
        }
        for(i = 1; i < c - 1; ++ i) {
            if (!(i & 1)) ++ c3;
            if (!((i + r - 1) & 1)) ++ c3;
        }

    if (n <= c3)
        return n * 3 + ans;

    n -= c3;
    ans += 3 * c3;

    return ans + 4 * n;
}

int dye_even()
{
    int n = ::n;
    int ans = 0;

    int c0 = (r * c + 1) >> 1;
    if (n <= c0)
        return 0;
    n -= c0;


    int c2 = ((r & c) & 1) ? 0 : 2;
    if (n <= c2)
        return n * 2;
    n -= c2;
    ans += 2 * c2;


    int c3 = 0;
    int i = 0;
        for(i = 1; i < r - 1; ++ i) {
            if ((i & 1)) ++ c3;
            if (((i + c - 1) & 1)) ++ c3;
        }
        for(i = 1; i < c - 1; ++ i) {
            if ((i & 1)) ++ c3;
            if (((i + r - 1) & 1)) ++ c3;
        }

    if (n <= c3)
        return n * 3 + ans;

    n -= c3;
    ans += 3 * c3;

    return ans + 4 * n;
}

int process()
{
    cin >> r >> c >> n;
    if (r < c)
        swap(r, c);
    /* one column */
    if (c == 1)
        {
            if (n <= ((r + 1) >> 1))
                return 0;
            if (r & 1)
                {
                    n -= (r + 1) >> 1;
                    return n * 2;
                }
            else
                {
                    n -= r >> 1;
                    return n * 2 - 1;
                }
        }

    int empty = (r * c + 1) / 2;
    if (n <= empty)
        return 0;
    int ans1 = dye_odd();
    int ans2 = dye_even();
    return min(ans1 , ans2);
}
#undef int
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t ; ++i)
        cout << "Case #" << i << ": " << process() << endl;
    return 0;
}