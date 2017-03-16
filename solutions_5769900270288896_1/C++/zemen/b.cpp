#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    freopen("b.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    cin >> tn;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

int test = 1;

int n, m;

bool iscorn(int x, int y)
{
    return (x == 0 || x == n - 1) &&
        (y == 0 || y == m - 1);
}

bool iswall(int x, int y)
{
    return (x == 0 || x == n - 1) ||
        (y == 0 || y == m - 1);
}

int cor[2], wall[2], in[2];

int solve()
{
    int k;
    cin >> n >> m >> k;
    cor[0] = cor[1] = wall[0] = wall[1] = in[0] = in[1] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (iscorn(i, j))
                cor[(i + j) % 2]++;
            else if (iswall(i, j))
                wall[(i + j) % 2]++;
            else
                in[(i + j) % 2]++;
        }
    int bad = n * (m - 1) + m * (n - 1);
    int ans = INF;
    bool fuck = (n == 1 || m == 1);
    for (int c = 0; c < 2; ++c)
    {
        int cbad = bad;
        int free = n * m - k;
        while (free > 0)
        {
            if (in[c] > 0)
                --free, --in[c], cbad -= 4;
            else if (wall[c] > 0)
                --free, --wall[c], cbad -= 3 - fuck;
            else if (cor[c] > 0)
                --free, --cor[c], cbad -= 2 - fuck;
            else
                break;
        }
        ans = min(ans, cbad);
    }
    if (n == 1 && m == 1)
        ans = 0;
    cout << "Case #" << test++ << ": " << ans << '\n';
    return 0;
}
