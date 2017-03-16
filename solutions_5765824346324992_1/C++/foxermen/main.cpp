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

const int N = (int)(1e3) + 7;
const int M = (int)(86400) + 7;
const ld eps = 1e-12;
const ll MOD = (ll)(1e9) + 9;
const ll INF = (ll)(1e9) + 7;
const ld PI = 3.14159265358979310000;

ll a[N];

bool ok(ll m, ll n, ll k)
{
    ll sum = 0;
    for (int i = 0; i < n; ++i)
        sum += (m - 1) / a[i] + 1;
    return (sum < k);
}

int main()
{
    freopen("people.in", "r", stdin);
    freopen("people.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int iii = 0; iii < tt; ++iii)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        ll l = 0, r = (ll)1e16;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (ok(m, n, k))
                l = m;
            else
                r = m;
        }
        ll sum = 0;
        for (int i = 0; i < n; ++i)
            sum += (l - 1) / a[i] + 1;
        for (int i = 0; i < n; ++i)
            if (!(l % a[i]))
            {
                ++sum;
                if (sum == k)
                {
                    k = i + 1;
                    break;
                }
            }
        printf("Case #%d: %d\n", iii + 1, k);
    }
    return 0;
}
