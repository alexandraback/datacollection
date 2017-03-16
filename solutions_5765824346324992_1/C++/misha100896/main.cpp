#include <bits/stdc++.h>

using namespace std;

long long n, t, m[1000000], k;

int main()
{
    freopen("aaa.in","r",stdin);
    freopen("aaa.out","w",stdout);
    cin >> t;
    for (long long j = 0; j < t; ++j)
    {
        cin >> n >> k;
        for (long long i = 0; i < n; ++i)
            cin >> m[i];

        long long l = 0, r = 1;
        for (int z = 0; z < 14; ++z)
            r *= 10;
        r += 1;
        while (l <= r)
        {
            long long kk = (l + r) / 2, z = k;
            for (int i = 0; i < n && z > 0; ++i)
                z -= kk / m[i] + 1;
            if (z > 0)
                l = kk + 1;
            else r = kk - 1;
        }
        long long z = k - 1;
        for (int i = 0; i < n; ++i)
            if (l % m[i] == 0)
                z -= l / m[i];
            else z -= l / m[i] + 1;
        int rez;
        for (int i = 0; i < n; ++i)
            if (z == 0 && l % m[i] == 0)
            {
                rez = i;
                break;
            }
            else
            if (l % m[i] == 0)
                --z;
        cout << "Case #" << j + 1 << ": " << rez + 1 << '\n';
    }
    return 0;
}
