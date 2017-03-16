// LUCIFER <3 SLS <3

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, i, n, u = 0, ans1, ans2, mx;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        mx = ans1 = 0;
        for (i = 1; i < n; i++) {
            if (a[i-1] > a[i]) {
                ans1 += (a[i-1] - a[i]);
                mx = max(mx, (a[i-1] - a[i]));
            }
        }
        ans2 = 0;
        for (i = 0; i < n-1; i++)
            ans2 += min(mx, a[i]);
        cout << "Case #" << ++u << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}
