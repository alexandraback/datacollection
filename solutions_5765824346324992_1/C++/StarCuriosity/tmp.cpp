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
        int b,n;
        cin >> b >> n;
        for(int i = 0; i < b; ++i)
            cin >> a[i];

        long long left = -1;
        long long right = 1000000000000000000LL;
        while (right - left > 1)
        {
            long long mid = (left + right)/2;
            long long cnt = b;
            for(int i = 0; i < b; ++i)
                cnt += mid/a[i];
            if (cnt >= n)
                right = mid;
            else
                left = mid;
        }
        int ans = 0;
        long long cnt = 0;
        if (right > 0)
        {
            cnt = b;
            for(int i = 0; i < b; ++i)
                cnt += (right - 1)/a[i];
        }

        for(int i = 0; i < b; ++i)
        {
            if (right% a[i] == 0)
            {
                ++cnt;
                if (cnt == n)
                {
                    ans = i+1;
                    break;
                }
            }
        }
        cout << "Case #" << test << ": " << ans << "\n";
    }

    return 0;
}
