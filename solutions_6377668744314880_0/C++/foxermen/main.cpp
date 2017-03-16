#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <stack>
#include <iterator>

#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> point;
typedef pair<ll, ll> pll;
typedef pair<ld, int> pdi;

const int N = (int)(3e3) + 7;
const int M = (int)(86400) + 7;
const ld eps = 1e-12;
const ll MOD = (ll)(1e9) + 9;
const ll INF = (ll)(1e9) + 7;
const ld PI = 3.14159265358979310000;

pii a[N];
int n;

int get(pii x, pii y)
{
    ll aa = x.y - y.y;
    ll bb = y.x - x.x;
    ll cc = -(aa * x.x + bb * x.y);
    int p = 0, o = 0;
    for (int i = 0; i < n; ++i)
    {
        if (aa * a[i].x + bb * a[i].y + cc < 0)
            ++o;
        if (aa * a[i].x + bb * a[i].y + cc > 0)
            ++p;
    }
    return min(o, p);
}

int main()
{
    freopen("people.in", "r", stdin);
    freopen("people.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int iii = 0; iii < tt; ++iii)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &a[i].x, &a[i].y);
        printf("Case #%d:\n", iii + 1);
        if (n == 1)
        {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; ++i)
        {
            int mini = n + 1;
            for (int j = 0; j < n; ++j)
                if(i != j)
                    mini = min(mini, get(a[i], a[j]));
            printf("%d\n", mini);
        }
    }
    return 0;
}
