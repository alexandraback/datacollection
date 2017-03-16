#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <list>
#include <ctime>

#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> lint;

const int N = (int)(1e2) + 7;
const ll MD = 1000000000;
const int KOL = 9;
const int M = (int)(1e6) + 7;
const ll INF = (ll)(1e9) + 7;
const ll MOD = (ll)(1e9) + 7;
const ld eps = 1e-12;

vector<pci> a[N];
vector<int> v;

int ok()
{
    int n = v.size();
    int mini = INF;
    for (int i = 1; i <= 100; ++i)
    {
        int kol = 0;
        for (int j = 0; j < n; ++j)
            kol += abs(i - v[j]);
        mini = min(mini, kol);
    }
    return mini;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int ii = 0; ii < tt; ++ii)
    {
        for (int i = 0; i < N; ++i)
            a[i].clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            for (int j = 0; j < (int)(s.size()); ++j)
                if (!j || s[j] != s[j - 1])
                    a[i].pb(mp(s[j], 1));
                else
                    a[i][(int)(a[i].size()) - 1].y++;
        }
        printf("Case #%d: ", ii + 1);
        bool f = 0;
        int kk = a[0].size();
        for (int i = 0; i < n; ++i)
            if ((int)a[i].size() != kk)
                f = 1;
        if (f)
        {
            printf("Fegla Won\n");
            continue;
        }
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < kk; ++j)
                if (a[i][j].x != a[0][j].x)
                    f = 1;
        if (f)
        {
            printf("Fegla Won\n");
            continue;
        }
        int res = 0;
        for (int i = 0; i < kk; ++i)
        {
            v.clear();
            for (int j = 0; j < n; ++j)
                v.pb(a[j][i].y);
            res += ok();
        }
        cout << res << endl;
    }
    return 0;
}
