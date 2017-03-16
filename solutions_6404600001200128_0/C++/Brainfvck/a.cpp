#include<iostream>
using namespace std;

int m[1005];

int main()
{
    int t;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> m[i];
        int ans1 = 0,ans2 = 0;
        for (int i = 1; i < n; i++)
            if (m[i - 1] > m[i])
                ans1 += m[i - 1] - m[i];
        int r = 0;
        for (int i = 1; i < n; i++)
            r = max(r,m[i - 1] - m[i]);
        for (int i = 1; i < n; i++)
            ans2 += min(m[i - 1],r);
        cout << "Case #" << ii + 1 << ": " << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}
