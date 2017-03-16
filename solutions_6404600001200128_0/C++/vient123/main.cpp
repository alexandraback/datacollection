#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TESTS;
    cin >> TESTS;
    for (int TEST = 1; TEST <= TESTS; TEST++)
    {
        cout << "Case #" << TEST << ": ";
        int n;
        cin >> n;
        vector<long long> V(n);
        for (auto & x : V)
            cin >> x;
        long long a = 0, b = 0, rate = 0, now = 0;
        for (int i = 1; i < n; i++)
            if (V[i] < V[i - 1])
                a += V[i - 1] - V[i];
        for (int i = 1; i < n; i++)
            rate = max(rate, V[i - 1] - V[i]);
        if (rate != 0)
        {
            now = V[0];
            for (int i = 1; i < n; i++)
            {
                b += min(now, rate);
                now = V[i];
            }
        }
        cout << a << ' ' << b << '\n';
    }
}
