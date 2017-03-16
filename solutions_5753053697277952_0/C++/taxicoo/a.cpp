#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define RI(x) scanf("%d", &x)
#define RL(x) scanf("%I64d", &x)
#define RD(x) scanf("%f", &x)

pair<int, char> a[30];
set<pair<int, char> > s;


void solve(int case_number)
{
    s.clear();
    int n;
    int sum = 0;
    cin >> n;
    for (int i=0; i<n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i + 'A';
        sum += a[i].first;
        s.insert(a[i]);
    }
    pair<int, char> mx, mn;


    cout << "Case #" << case_number << ": ";
    while (s.size() > 2)
    {
        mx = *(s.rbegin());
        s.erase(mx);

        cout << mx.second << ' ';
        --mx.first;
        if (mx.first > 0)
            s.insert(mx);
        --sum;
    }
    mx = *(s.rbegin());
    mn = *(s.begin());
    while (sum > 0)
    {
        cout << mx.second << mn.second << ' ';
        sum -= 2;
    }

    cout << "\n";
}

int main()
{
    freopen("input1.in", "r", stdin);
    freopen("output1.out", "w", stdout);
    int t;
    cin >> t;
    for (int i=1; i<=t; ++i)
        solve(i);

    return 0;
}

