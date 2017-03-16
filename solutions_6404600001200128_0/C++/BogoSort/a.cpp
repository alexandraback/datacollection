#include "bits/stdc++.h"
using namespace std;

int m1(int, vector<int>);
int m2(int, vector<int>);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        vector<int> v;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << "Case #" << i + 1 << ": " << m1(n, v) << ' ' << m2(n, v) << endl;
    }
    return 0;
}

int m1(int n, vector<int> v)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] > v[i + 1])
        {
            cnt += v[i] - v[i + 1];
        }
    }
    return cnt;
}

int m2(int n, vector<int> v)
{
    int maxd = 0;
    int cnt = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] - v[i + 1] > maxd)
            maxd = v[i] - v[i + 1];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] > maxd)
            cnt += maxd;
        else
            cnt += v[i];
    }
    return cnt;
}
