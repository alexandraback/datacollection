#include <bits/stdc++.h>

using namespace std;

long long n, t, m[100];

int main()
{
    freopen("aaa.in","r",stdin);
    freopen("aaa.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (long long j = 0; j < t; ++j)
    {
        cin >> n;
        for (long long i = 0; i < n; ++i)
            cin >> m[i];
        long long sum1 = 0, sum2 = 0, rez = 0;
        for (long long i = 1; i < n; ++i)
            if (m[i] < m[i - 1])
            {
                sum1 += m[i - 1] - m[i];
                sum2 = max(sum2, m[i - 1] - m[i]);
            }
        for (long long i = 0; i < n - 1; ++i)
        {
            if (m[i] - sum2< 0)
                rez += m[i];
            else rez += sum2;
        }
        cout << "Case #" << j + 1 << ": " << sum1 << ' ' << rez << '\n';
    }
    return 0;
}
