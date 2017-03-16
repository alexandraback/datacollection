#include <bits/stdc++.h>

using namespace std;

void solution();

int main()
{
    ios_base::sync_with_stdio(false);
#ifdef HOME
    freopen("A.in", "rt", stdin);
    clock_t start = clock();
#endif
    solution();
#ifdef HOME
    cerr.precision(3);
    cerr << endl << "Total time: " << fixed << double(clock() - start) / double(CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}

typedef long long ll;
#define int ll

int n;
pair<int,int> p[32];

void solve()
{
    sort(p, p + n);
    reverse(p, p + n);
    while (p[0].first > p[1].first)
    {
        cout << " " << char('A' + p[0].second);
        --p[0].first;
    }
    for (int i = n - 1; i >= 2; --i)
    {
        while (p[i].first--)
            cout << " " << char('A' + p[i].second);
    }
    while (p[0].first--)
    {
        cout << " " << char('A' + p[0].second) << char('A' + p[1].second);
    }
    cout << endl;
}

void solution()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << t + 1 << ":";
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i].first;
            p[i].second = i;
        }
        solve();
    }
}
