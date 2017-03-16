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

const int maxn = 1e3 + 100;
int a[maxn], n;
int getAns(int k)
{
    int ans = 0;
    int chi = k;
    REP_D(i, 2, n)
    {
        int t = a[i-1];
        if(t <= chi)
        {
            ans += t;
        }
        else
        {
            ans += chi;
        }
    }
    return ans;
}
int check(int k)
{
    int chi = k*10;
    REP_D(i, 2, n)
    {
        int t = a[i-1]-a[i];
        if(t>=0)
        {
            if(t > chi)
                return 0;
        }
    }
    return 1;
}
void solve()
{
    int ans;
    ans = 0;
    REP_D(i, 2, n)
    {
        int cha = a[i-1]-a[i];
        if(cha >= 0)
        {
            ans += cha;
        }
        else
        {
            ;
        }
    }
    printf("%d ", ans);
    int max_cha = 0;
    REP_D(i, 2, n)
    {
        max_cha = max(max_cha, a[i-1]-a[i]);
    }
    printf("%d\n", getAns(max_cha));
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("1Aout.txt", "w", stdout);
    int ncase;
    scanf("%d", &ncase);
    REP_D(_, 1, ncase)
    {
        printf("Case #%d: ", _);
        scanf("%d", &n);
        REP_D(i, 1, n)
        {
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}
