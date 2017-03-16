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
#define REP(i, a, b) for(ll i = a;i < b;i++)
#define REP_D(i, a, b) for(ll i = a;i <= b;i++)

typedef long long ll;

using namespace std;

const ll maxn = 1e3 +100;
ll m[maxn], b, n;
ll getNum(ll k)
{
    ll ans = 0;
    REP_D(i, 1, b)
    {
        ans += (k/m[i] + 1);
    }
    if(ans >= n)
        return 1;
    return 0;
}
void solve()
{
    ll l = 0, r = 1e14+100;
    while(l < r)
    {
        ll mid = (l + r)/2;
        if(getNum(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    ll have = 0;
    REP_D(i, 1, b)
    {
        have += (r + m[i]-1)/m[i];
    }
    ll leave = n - have;
    if(leave==0)
    {
        printf("asdfsdafsadfsdfsadffffffffff");
    }
    REP_D(i, 1, b)
    {
        if(r%m[i]==0)
        {
            leave--;
        }
        if(leave==0)
        {
            printf("%d\n", i);
            break;
        }
    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("3Bout.txt", "w", stdout);
    ll ncase;
    scanf("%lld", &ncase);
    REP_D(_, 1, ncase)
    {
        printf("Case #%d: ", _);
        scanf("%lld%lld", &b, &n);
        REP_D(i, 1, b)
        {
            scanf("%lld", &m[i]);
        }
        solve();
    }
    return 0;
}
