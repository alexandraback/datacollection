#include <bits/stdc++.h>

using namespace std;

const int MX_A = 30;

inline bool gr(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}

void solve(int z)
{
    cout << "Case #" << z << ": ";
    int n;
    cin >> n;
    pair<int, int> a[MX_A];
    fill(a, a + MX_A, make_pair(0, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        cnt += a[i].first;
    }
    sort(a, a + n, gr);
    while (cnt != 0)
    {
        a[0].first--;
        cout << (char)(a[0].second + 'A');
        if (cnt == 3)
        {
            cout << " ";
            cnt--;
        }
        else
        {
            if (a[0].first > a[1].first)
            {
                a[0].first--;
                cout << (char)(a[0].second + 'A') << " ";
            }
            else
            {
                a[1].first--;
                cout << (char)(a[1].second + 'A') << " ";
            }
            cnt -= 2;
        }

        sort(a, a + n, gr);
    }
    cout << '\n';
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
}
