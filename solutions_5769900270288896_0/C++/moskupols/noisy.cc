// License {{{
// <=================================================================>
//
//             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//                     Version 2, December 2004
//
//  Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
//
//  Everyone is permitted to copy and distribute verbatim or modified
//  copies of this license document, and changing it is allowed as long
//  as the name is changed.
//
//             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//    TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
//   0. You just DO WHAT THE FUCK YOU WANT TO.
//
// <=================================================================>
// }}}

#include <bits/stdc++.h>
using namespace std;

#ifdef moskupols
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 42
#endif

#define timestamp(x) debug("["#x"]: %.3f\n", (double)clock() / CLOCKS_PER_SEC) // thank PavelKunyavskiy i am not pregnant!

#define hot(x) (x)
#define sweet(value) (value)
#define lovelyCute(nine) 9

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).begin(),(v).end()
#define UNIQ(v) (v).erase(unique(ALL(v)),(v).end())

typedef long long int64;
typedef unsigned long long uint64;
typedef long double kingsized;

#define BIT(m,i,j) (((m)>>((i)*c+(j)))&1)

void solve()
{
    int r, c, n;
    cin >>r >> c >> n;

    int ans = 1<<30;
    for (int mask = 0; mask< (1 << (r*c)); ++mask)
    {
        if (__builtin_popcount(mask) != n)
            continue;
        int here = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
            {
                if (i && BIT(mask, i, j) && BIT(mask, i-1, j))
                    here++;
                if (j && BIT(mask, i, j) && BIT(mask, i, j-1))
                    ++here;
            }
        ans = min(ans, here);
    }
    cout << ans << endl;
}

int main()
{
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        debug("%d ", i);
        timestamp(multi);
    }

    timestamp(end);
    return 0;
}

