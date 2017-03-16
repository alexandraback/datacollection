#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;

template <class T> inline T sqr(const T& a) { return a * a; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }




void solution()
{
    int r, c, n;
    cin >> r >> c >> n;

    vector < vector<bool> > field(r, vector<bool>(c, false));
    int total = r * c;
    int ans = total * 5 + 100;
    for (int mask = 0; mask < (1 << total); ++mask)
    {
        int cnt = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < total; ++i)
        {
            if (mask & (1 << i))
            {
                ++cnt;
                field[y][x] = true;
            }
            else
            {
                field[y][x] = false;
            }

            ++y;
            if (y == r)
            {
                ++x;
                y = 0;
            }
        }

        if (cnt != n)
            continue;

        int sum = 0;
        for (y = 0; y < r; ++y)
        {
            for (x = 0; x < c; ++x)
            {
                if (!field[y][x])
                    continue;

                if (y < r - 1 && field[y + 1][x])
                    ++sum;
                if (x < c - 1 && field[y][x + 1])
                    ++sum;
            }
        }
        updMin(ans, sum);
    }

    cout << ans;
}


int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);


    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; ++test)
    {
        cout << "Case #" << test << ": ";
        solution();
        cout << "\n";
    }



    return 0;
}
