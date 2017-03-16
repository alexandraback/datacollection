#include <bits/stdc++.h>
using namespace std;


int const maxn = 1005;
int a[maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int T = 0;
    cin >> T;
    for(int test = 1; test <= T; ++test)
    {
        int n = 0;
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        int ans1 = 0;
        for(int i = 1; i <= n; ++i)
            if (a[i] > a[i-1])
                ans1 += a[i] - a[i-1];
        ans1 -= a[n];

        int cur = 0;
        for(int i = 2; i <= n; ++i)
            if (a[i-1] - a[i] > cur)
                cur = a[i-1] - a[i];
        int ans2 = 0;
        for(int i = 2; i <= n; ++i)
            ans2 += min(cur, a[i-1]);
        cout << "Case #" << test << ": " << ans1 << " " << ans2 << "\n";
    }

    return 0;
}
