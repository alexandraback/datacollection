#include <bits/stdc++.h>
using namespace std;
int n, m;
int main () {
	ios :: sync_with_stdio (false);
    cin.tie (0);
    freopen ("C:\\B-small-attempt0.in", "r", stdin);
	freopen ("D:\\outputB.txt", "w", stdout);
    int c;
    cin >> c;
    for (int cn = 1; cn <= c; ++cn) {
         cout << "Case #" << cn << ": ";
         int n, m, p;
         cin >> n >> m >> p;
         int ans = (int) 1e9;
         for (int s = 0; s < 1 << (n * m); ++s) {
             int ts = s;
             int ct = 0;
             int a [20][20];
             memset (a, 0, sizeof (a));
             for (int i = 1; i <= n; ++i)
                 for (int j = 1; j <= m; ++j) {
                     if (ts & 1) {
                         a [i][j] = 1;
                         ++ct;
                     }
                     ts >>= 1;
                 }
                if (ct == p) {
             int sans = 0;
             for (int i = 1; i <= n; ++i)
                 for (int j = 1; j <= m; ++j)
                     if (a [i][j]) {
                         if (a [i - 1][j])
                             ++sans;
                         if (a [i + 1][j])
                             ++sans;
                         if (a [i][j - 1])
                             ++sans;
                         if (a [i][j + 1])
                             ++sans;
					 }
			sans /= 2;
			ans = min (ans, sans);}
		 }
         cout << ans << endl;
	}
	return 0;
}

