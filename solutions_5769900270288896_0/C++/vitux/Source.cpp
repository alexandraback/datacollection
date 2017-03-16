#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define lol long long
using namespace std;

ifstream in("inputB.txt");
ofstream out("outputB.txt");


#define cin in
#define cout out



int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        lol r, c, n;
        cin >> r >> c >> n;
        vector<int> v;
        for (int i = 0; i < n; ++i)
            v.push_back(0);
        for (int i = n; i < r * c; ++i)
            v.push_back(1);
        int best = 123456789;
        do
        {
            int curr = 0;
            for (int i = 0; i < r - 1; ++i)
                for (int j = 0; j < c; ++j)
                    if (!v[i * c + j] && !v[(i + 1) * c + j])
                        ++curr;
            for (int j = 0; j < c - 1; ++j)
                for (int i = 0; i < r; ++i)
                    if (!v[i * c + j] && !v[i * c + j + 1])
                        ++curr;
            best = min(best, curr);
        } while (next_permutation(v.begin(), v.end()));
        cout << "Case #" << i + 1 << ": " << best << endl;
    }
}




/*
lol rev(lol x)
{
    if (x % 10 == 0)
        return x;
    lol r = 0;
    while (x)
    {
        r *= 10ll;
        r += x % 10ll;
        x /= 10ll;
    }
    return r;
}

lol build(lol x)
{
    return 0;
}

int main()
{
    vector<int> dp(1000001, 1234567890);
    dp[1] = 1;
    dp[0] = 0;
    for (int i = 2; i < 1000001; ++i)
        dp[i] = min(dp[i - 1], dp[rev(i)]) + 1;
    for (int i = 2; i < 1000001; ++i)
    {
        if (rev(i) < i && i % 10 == 1)
        {
            bool z = (dp[rev(i)] + 1 <= dp[i]);
            if (z)
                cout << "ok " << i << endl;
            else
            {
                cout << "fail " << i << endl;
                int x;
                cin >> x;
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        lol ans = 0;
        while (n > 1000000)
        {
            ans += n % 10 - 1;
            n -= n % 10 - 1;
            int r = rev(n);
            if (r < n)
            {
                ++ans;
                n = r;
                continue;
            }
            int x = build(n);
        }
        cout << "Case #" << i + 1 << ": " << ans + dp[n] << endl;
    }
}*/