#define y1 JulioCortasar
#define y2 GabrielGarsiaMarkes
#include <bits/stdc++.h>
#undef y1
#undef y2

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define pb push_back
#define mp make_pair
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef double lf;

const ll inf = 1e9 + 100500;

#define TASK_NAME "INSERT_TASK_NAME_HERE"
#define TASK_LETTER "b"

#define STANDART_INPUT

#ifdef LOCAL
void initrand()
{
    ll seed;
    asm("rdtsc":"=A"(seed));
    srand(seed);
}
#endif

const int maxn = 10000;

int n, m, k, a[maxn][maxn];

int solve(int x, int q)
{
    int ans = 0;
    vector<int> all;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = (i + j) % 2 == x ? 1 : 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if ((i + j) % 2 == x) continue;
            const int dx[] = {0, 0, -1, 1};
            const int dy[] = {-1, 1, 0, 0};
            int cnt = 0;
            for (int k = 0; k < 4; ++k)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                cnt += a[nx][ny];
            }
            all.pb(cnt);
        }
    sort(all.begin(), all.end());
    for (int i = 0; i < k - q; ++i)
        ans += all[i];
    return ans;
}

void solve()
{
    cin >> n >> m >> k;
    int w = (n * m + 1) / 2, b = n * m - w;
    if (k <= w)
    {
        cout << 0 << endl;
        return;
    }
    cout << min(solve(0, w), solve(1, b)) << endl;
}

int main()
{
#ifdef LOCAL
    freopen(TASK_LETTER ".in", "r", stdin);
#else
#ifndef STANDART_INPUT
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif
#endif
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
#ifdef LOCAL
    cerr << "Time = " << clock() / 1000 << " ms." << endl;
#endif
	return 0;
}
