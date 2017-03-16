// LUCIFER <3 SLS <3

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, b, n, u = 0, gcd, tmp, tot, j, ans, i;
    cin >> t;
    while (t--) {
        cin >> b >> n;
        int a[b];
        ans = 1;
        for (i = 0; i < b; i++) {
            cin >> a[i];
            ans *= a[i];
        }
        if (b == 1)
            gcd = a[0];
        else {
            gcd = __gcd(a[0], a[1]);
            for (i = 2; i < b; i++)
                gcd = __gcd(gcd, a[i]);
        }
        tmp = ans / gcd;
        tot = 0;
        for (i = 0; i < b; i++)
            tot += (tmp / a[i]);
        if (n % tot == 0)
            n = tot;
        else
            n %= tot;
        for (i = 0; i < tmp && n; i++) {
            for (j = 0; j < b && n; j++) {
                if (i % a[j] == 0) {
                    tot = j;
                    n--;
                }
            }
        }
        cout << "Case #" << ++u << ": " << tot+1 << endl;
    }
    return 0;
}
