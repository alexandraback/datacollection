#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;

int a[MAXN];
int n;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int mm = 0, res1 = 0;
    for(int i = 2; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            res1 += a[i - 1] - a[i];
            mm = max(mm, a[i - 1] - a[i]);
        }
    }
    int res2 = 0;
    for(int i = 1; i <= n - 1; i++) {
        res2 += min(a[i], mm);
    }
    cout << res1 << " " << res2 << endl;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}
