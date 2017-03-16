#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctype.h>
#include <limits.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#define CLR(a) memset(a, 0, sizeof(a))
#define REP(i, a, b) for(int i = a;i < b;i++)
#define REP_D(i, a, b) for(int i = a;i <= b;i++)

typedef long long ll;

using namespace std;

const int maxn = 3e3 + 100;
const int EPS = 1e-12;

struct Point
{
    double x, y;
    Point shexiang(Point other)
    {
        Point t;
        t.x = other.x - x;
        t.y = other.y - y;
        return t;
    }
    double chaji(Point other)
    {
        return x*other.y-y*other.x;
    }
    double dianji(Point other)
    {
        return x*other.x+y*other.y;
    }
};
Point p[maxn];
int n;

int calcu(int a, int b)
{
    int l = 0, r = 0;
    REP_D(i, 1, n)
    {
        if(i!=a&&i!=b)
        {
            double tmp = p[a].shexiang(p[b]).chaji(p[a].shexiang(p[i]));
            if(fabs(tmp) < EPS)
            {
                ;
            }
            else if(tmp > 0)
            {
                l++;
            }
            else
            {
                r++;
            }
        }
    }
    return min(l, r);
}
void solve()
{
    REP_D(i, 1, n)
    {
        int ans = n - 1;
        REP_D(j, 1, n)
        {
            if(i!=j)
            {
                ans = min(ans, calcu(i, j));
            }
        }
        printf("%d\n", ans);
    }
}

int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("3Cout.txt", "w", stdout);
    int ncase;
    scanf("%d", &ncase);
    REP_D(_, 1, ncase)
    {
        printf("Case #%d:\n", _);
        scanf("%d", &n);
        REP_D(i, 1, n)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        solve();
    }
    return 0;
}
