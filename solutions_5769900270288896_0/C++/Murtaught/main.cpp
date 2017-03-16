#include <bits/stdc++.h>
using namespace std;
#define print_out(x) cout << "print_out: " << #x << " == " << x << endl;
#define sz(x) int((x).size())
#define pb(x) push_back(x)
#define mkp(a, b) make_pair(a, b)
#define F first
#define S second
#define whole(a) a.begin(), a.end()
#define FOR(i, S, N) for (int i = S; i < N; ++i)
#define contains(C, key) (C.find(key) != C.end())
typedef vector<int> VInt;
typedef vector<VInt> VVInt;
typedef pair<int, int> PII;
typedef long long int int64;
typedef unsigned int uint;


inline int reverse(int num)
{
    VInt digits;
    while (num > 0)
    {
        digits.pb(num % 10);
        num /= 10;
    }

    FOR (i, 0, sz(digits))
    {
        num *= 10;
        num += digits[i];
    }

    return num;
}

void solve()
{
    int r, c, n;
    cin >> r >> c >> n;

    int tp = r * c;
    const int MAX_CNTR = 1 << tp;

    int ans = INT_MAX;
    for (int mask = 0; mask < MAX_CNTR; ++mask)
    {
        int room[r][c];

        int sum = 0;
        FOR (i, 0, tp)
            if ((mask >> i) & 1)
            {
                ++sum;
                room[i / c][i % c] = 1;
            }
            else
                room[i / c][i % c] = 0;

        if (sum != n)
            continue;

        int unh = 0;
        FOR(i, 0, r)
            FOR(j, 0, c)
                if (room[i][j])
                {
                    if (i > 0 && room[i - 1][j]) ++unh;
                    if (j > 0 && room[i][j - 1]) ++unh;
                }

        ans = min(ans, unh);
    }

    cout << ans << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    int T; cin >> T;
    for (int tt = 1; tt <= T; ++tt)
    {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}
