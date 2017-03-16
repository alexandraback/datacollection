#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define INF 1000000000

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int r,c,n;

int sum(int mask)
{
    int s = 0;
    while (mask != 0)
    {
        s += mask & 1;
        mask >>= 1;
    }
    return s;
}

bool occupied(int mask, int i, int j)
{
    return (mask & (1 << (c*i+j))) != 0;
}

int unhappiness(int mask)
{
    if (sum(mask) != n)
        return INF;
    int unhap = 0;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            if (i+1 < r && occupied(mask, i, j) && occupied(mask, i+1, j))
                unhap++;
            if (j+1 < c && occupied(mask, i, j) && occupied(mask, i, j+1))
                unhap++;
        }
    }
    return unhap;
}

int main()
{
    int T;
    cin >> T;
    for (int t=1; t<=T; t++)
    {
        cin >> r >> c >> n;
        int min_unhap = INF;
        for (int mask = 0; mask < (1 << (r*c)); mask++)
            min_unhap = min(min_unhap, unhappiness(mask));
        printf("Case #%d: %d\n", t, min_unhap);
    }
}
