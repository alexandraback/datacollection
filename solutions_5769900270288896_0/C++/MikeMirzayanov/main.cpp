#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int f[20][20];

int main(int argc, char* argv[])
{
    int tt;
    cin >> tt;

    forn(test, tt)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int result = 100000;
        forn(mask, 1 << (n * m))
        {
            forn(i, 20)
                forn(j, 20)
                    f[i][j] = 0;
            int r = 0;
            forn(p, n * m)
            {
                if (mask & (1 << p))
                {
                    int x = p / m;
                    int y = p % m;
                    f[x][y] = 1;
                    r++;
                }
            }
            int val = 0;
            forn(i, n)
                forn(j, m)
                {
                    if (f[i][j] && f[i + 1][j])
                        val++;
                    if (f[i][j] && f[i][j + 1])
                        val++;
                }
            if (r == k && val < result)
                result = val;
        }

        cout << "Case #" << (test + 1) << ": " << result << endl;
    }

    return 0;
}
