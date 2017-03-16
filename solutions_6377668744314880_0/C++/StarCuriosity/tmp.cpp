#include <bits/stdc++.h>
using namespace std;


int const maxn = 3005;
pair<int,int> a[maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int T = 0;
    cin >> T;
    for(int test = 1; test <= T; ++test)
    {
        int n = 0;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i].first >> a[i].second;
        }

        vector<int> ans(n,max(0,n-3));
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    int left = 0;
                    int right = 0;
                    for(int k = 0; k < n; ++k)
                        if (i !=k && j != k)
                        {
                            long long tmp = (a[j].first - a[i].first)*1LL*(a[k].second - a[i].second) - (a[j].second - a[i].second)*1LL*(a[k].first - a[i].first);
                            if (tmp > 0)
                                ++left;
                            else
                                ++right;
                        }
                    ans[i] = min(ans[i], left);
                    ans[i] = min(ans[i], right);
                }
            }
        }
        cout << "Case #" << test << ":\n";
        for(int i = 0; i < n; ++i)
            cout << ans[i] << "\n";
    }

    return 0;
}
