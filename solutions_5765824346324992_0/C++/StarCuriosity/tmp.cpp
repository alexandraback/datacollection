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

        vector<int> ans;
        int right = 1;
        for(int i = 0; i < b; ++i)
        {
            int tmp = __gcd(a[i], right);
            right *= a[i]/tmp;
        }

        for(int i = 0; i < right; ++i)
        {
            for(int j = 0; j < b; ++j)
                if ( i % a[j] == 0)
                    ans.push_back(j+1);
        }
        --n;
        n %= ans.size();
        cout << "Case #" << test << ": " << ans[n] << "\n";
    }

    return 0;
}
