#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void Solved(int nT)
{
    int N;
    vector<string> ret;
    vector<vector<pair<char, int> > > use;
    cin >> N;
    ret.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> ret[i];
    for (int i = 0; i < N; ++i)
    {
        int cnt = 1;
        vector<pair<char, int> > tmp;
        for (int j = 1; j <= ret[i].size(); ++j)
        {
            if (j == ret[i].size() || ret[i][j - 1] != ret[i][j])
            {
                tmp.push_back(make_pair(ret[i][j - 1], cnt));
                cnt = 1;
            }
            else
                ++cnt;
        }
        use.push_back(tmp);
    }
    printf("Case #%d: ", nT);
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        if (use[i].size() != use[0].size())
        {
            puts("Fegla Won");
            return ;
        }
        for (int k = 0; k < use[0].size(); ++k)
        {
            if (use[0][k].first != use[i][k].first)
            {
                puts("Fegla Won");
                return ;
            }
        }
    }
    for (int k = 0; k < use[0].size(); ++k)
    {
        vector<int> t;
        for (int i = 0; i < N; ++i)
        {
            t.push_back(use[i][k].second);
        }
        sort(t.begin(), t.end());
        int pos = t.size() >> 1;
        for (int i = 0; i < N; ++i)
            result += abs(use[i][k].second - t[pos]);
    }
    printf("%d\n", result);
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int T = 0;
    cin >> T;
    for (int nT = 1; nT <= T; ++nT)
    {
        Solved(nT);
    }

    return 0;
}