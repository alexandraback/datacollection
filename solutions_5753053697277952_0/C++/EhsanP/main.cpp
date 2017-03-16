#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 26;

int a[MAX_N];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_)
    {
        int n;
        cin >> n;
        int tot = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            tot += a[i];
        }
        cout << "Case #" << _ << ": ";
        while (tot)
        {
            int mx = max_element(a, a + n) - a;
            int o = 0;
            for (int i = 0; i < n; ++i)
                if (a[i] == 0)
                    o ++;
            if (n - o == 2)
            {
                int my;
                for (int i = 0; i < n; ++i)
                    if (a[i] == a[mx] && i != mx)
                        my = i;
                cout << char(mx + 'A') << char(my + 'A') << ' ';
                a[mx] --;
                a[my] --;
                tot -= 2;
            }
            else
            {
                cout << char(mx + 'A') << ' ';
                a[mx] --;
                tot --;
            }
        }
        cout << '\n';
    }
    return 0;
}
