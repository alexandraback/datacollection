#define _USE_MATH_DEFINES
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cmath>
#include <queue>
#include <functional>
#include <cstdio>

#define mp make_pair
#define mt(x,y,z) mp((x), mp((y), (z)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

// globals starts here

int R, C;

int ones(int mask, int len)
{
    int res = 0;
    for (int j = 0; j < len; ++j)
    {
        if ((1 << j) & mask)
        {
            ++res;
        }
    }
    return res;
}

int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

int bu[200];
int score(int mask)
{
    int sz = R * C;
    for (int j = 0; j < sz; ++j)
    {
        if ((1 << j) & mask)
        {
            bu[j] = 1;
        }
        else
        {
            bu[j] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (bu[i * C + j])
            {
                for (int k = 0; k < 2; ++k)
                {
                    int to_i = i + dy[k];
                    int to_j = j + dx[k];
                    int to = to_i * C + to_j;
                    if (to_i >= 0 && to_i < R && to_j >= 0 && to_j < C)
                    {
                        if (bu[to])
                        {
                            ++ans;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
#ifdef DEBUGAGA
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
#elif defined(CONTEST)
    freopen(CONTEST ".in", "r", stdin);
    freopen(CONTEST ".out", "w", stdout);
#endif

    int tests;
    cin >> tests;
    for (int tc = 0; tc < tests; ++tc)
    {
        int n;
        cin >> R >> C >> n;

        int sz = R * C;
        int min_score = 100000;
        for (int i = 0; i < (1 << sz); ++i)
        {
            int ons = ones(i, sz);

            if (ons == n)
            {
                int sc = score(i);
                min_score = min(sc, min_score);
            }
        }

        printf("Case #%d: %d\n", tc + 1, min_score);
    }


    return 0;
}