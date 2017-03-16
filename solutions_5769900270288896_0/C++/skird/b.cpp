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

const int maxn = 16;

int n, m, k, a[maxn][maxn];

void solve()
{
    cin >> n >> m >> k;
    int ans = (n + 1) * (m + 1);
    for (int msk = 0; msk < (1 << (n * m)); ++msk)
    {
        if (__builtin_popcount(msk) != k)
            continue;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = ((msk >> (i * m + j)) & 1);
        int q = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (i + 1 < n && a[i][j] + a[i + 1][j] == 2)
                    q++;
                if (j + 1 < m && a[i][j] + a[i][j + 1] == 2)
                    q++;
            }
        ans = min(ans, q);
    }
    cout << ans << endl;
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
