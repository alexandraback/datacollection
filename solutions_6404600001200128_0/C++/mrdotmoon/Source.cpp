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

int N, M[1001];

int slove1()
{
    int res = 0;
    for (int i = 1; i < N; i++)
    {
        if (M[i - 1] > M[i])
            res += M[i - 1] - M[i];
    }
    return res;
}

int slove2()
{
    int vv = 0;
    for (int i = 1; i < N; i++)
    {
        if (M[i - 1] > M[i])
            vv = max(vv, M[i - 1] - M[i]);
    }
    
    int res = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (M[i] >= vv)
            res += vv;
        else
            res += M[i];
    }
    return res;
}

void _main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &M[i]);

    printf("%d %d\n", slove1(), slove2());
}

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        printf("Case #%d: ", cases);
        _main();
    }
}