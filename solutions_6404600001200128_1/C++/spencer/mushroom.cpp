#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int arbitrary(vector<int> v)
{
    int total = 0;
    for (int i = 1; i < (int)v.size(); i++)
        if (v[i-1] > v[i])
            total += v[i-1] - v[i];
    return total;
}

int constant(vector<int> v)
{
    int rate = 0;
    for (int i = 1; i < (int)v.size(); i++)
        if (v[i-1] > v[i])
            rate = max(rate, v[i-1] - v[i]);

    int total = 0;
    for (int i = 0; i < (int)v.size() - 1; i++)
        total += min(v[i], rate);
    return total;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N; cin >> N;
        vector<int> glimpses;
        for (int i = 0; i < N; i++)
        {
            int m; cin >> m;
            glimpses.push_back(m);
        }

        printf("Case #%d: %d %d\n", t, arbitrary(glimpses), constant(glimpses));
    }
    return 0;
}
