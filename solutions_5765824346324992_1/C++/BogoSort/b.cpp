#include "bits/stdc++.h"
using namespace std;

long long served(long long t, vector<long long>& m)
{
    long long cnt = 0;
    for (int i = 0; i < m.size(); ++i)
    {
        cnt += (t + m[i] - 1) / m[i];
    }
    return cnt;
}

int solve()
{
    long long n;
    int b;
    vector<long long> m;
    cin >> b >> n;
    for (int i = 0; i < b; ++i)
    {
        long long x;
        cin >> x;
        m.push_back(x);
    }

    long long l = 0;
    long long r = m[0] * n;
    long long servedAt = -1;
    while (l < r)
    {
        long long mid = (l + r) / 2;
        long long smid = served(mid, m);
        if (smid < n && served(mid + 1, m) >= n)
        {
            servedAt = mid;
            break;
        }
        
        if (smid < n)
            l = mid + 1;
        else r = mid - 1;
    }
    if (servedAt == -1)
        servedAt = l;

    int cleft = (int)(n - served(servedAt, m));
    for (int i = 0; i < b; ++i)
    {
        if (servedAt % m[i] == 0)
        {
            --cleft;
            if (cleft == 0)
            {
                return i + 1;
            }
        }
    }

    *((int*) NULL) = 2;
    return -1;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}
