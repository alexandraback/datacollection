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

int a[N];

int main()
{
    freopen("people.in", "r", stdin);
    freopen("people.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int iii = 0; iii < tt; ++iii)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int k1 = 0, k2 = INF;
        for (int i = 1; i < n; ++i)
            if (a[i] < a[i - 1])
                k1 += a[i - 1] - a[i];
        for (int i = 0; i <= 100000; ++i)
        {
            int t = a[0];
            bool f = 0;
            int sum = 0;
            for (int j = 1; j < n; ++j)
            {
                if (t >= i)
                    sum += i;
                else
                    sum += t;
                t -= i;
                if (t < 0)
                    t = 0;
                if (a[j] < t)
                {
                    f = 1;
                    break;
                }
                t = a[j];
            }
            if (!f)
            {
                k2 = sum;
                break;
            }
        }
        printf("Case #%d: %d %d\n", iii + 1, k1, k2);
    }
    return 0;
}
