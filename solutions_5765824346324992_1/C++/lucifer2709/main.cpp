// LUCIFER <3 SLS <3

#include <bits/stdc++.h>

using namespace std;

long long int calc(long long int a[], long long int b, long long int n, long long int m, long long int &j)
{
    long long int cnt, i, tmp;
    cnt = tmp = 0;
    for (i = 0; i < b; i++) {
        tmp += (m % a[i] == 0) ? (m / a[i]) : ((m / a[i]) + 1);
        cnt += (m % a[i] == 0) ? 1 : 0;
    }
    if (cnt == 0 || (cnt + tmp) < n || tmp >= n)
        return (tmp+cnt);
    cnt = n - tmp;
    for (i = 0; i < b; i++) {
        if (m % a[i] == 0) {
            j = i;
            cnt--;
            if (!cnt)
                return n;
        }
    }
    return n;
}

long long int bin_search(long long int a[], long long int b, long long int n, long long int l, long long int r)
{
    long long int tmp, m, j;
    while (l <= r) {
        m = (l + r) / 2;
        j = -1;
        tmp = calc(a, b, n, m, j);
        if (j != -1 && tmp == n)
            return j;
        else if (tmp < n)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long long int t, b, n, u = 0, gcd, tmp, tot, j, ans, i;
    cin >> t;
    while (t--) {
        cin >> b >> n;
        long long int a[b];
        for (i = 0; i < b; i++)
            cin >> a[i];
        cout << "Case #" << ++u << ": " << bin_search(a, b, n, 0, 1000000000000000LL)+1 << endl;
    }
    return 0;
}
