#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ldb;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

const int MAXN = 20;

bool x[MAXN][MAXN];

int r, c, n;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d ", &T);
    forn(test, T) {
        printf("Case #%d: ", test + 1);

        scanf("%d%d%d", &r, &c, &n);

        int rc = r * c;

        int ans = 100500;

        forn(mask, (1 << rc))
            if (__builtin_popcount(mask) == n) {
                memset(x, 0, sizeof(x));

                forn(i, rc)
                    if ((mask >> i) & 1)
                        x[i / c][i % c] = true;

                int cur = 0;

                forn(i, r)
                    forn(j, c)
                        if (x[i][j]) {
                            if (x[i + 1][j])
                                cur++;
                            if (x[i][j + 1])
                                cur++;
                        }

                ans = min(ans, cur);
            }

        cout << ans << '\n';

    }
    return 0;
}
