#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int z = 0; z < t; ++z)
    {
        cout << "Case #" << z + 1 << ": ";
        int n;
        cin >> n;
        vector <string> s(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> s[i];
        }
        vector <vector <pair<char, int> > > x(n);
        for (int i = 0; i < n; ++i)
        {
            char c = s[i][0];
            int cnt = 1;
            for (int j = 1; j < s[i].size(); ++j)
            {
                if (s[i][j] == c)
                {
                    ++cnt;
                }
                else
                {
                    x[i].push_back(make_pair(c, cnt));
                    c = s[i][j];
                    cnt = 1;
                }
            }
            x[i].push_back(make_pair(c, cnt));
        }
        bool flag = false;
        vector <vector <int> > ints(x[0].size());
        for (int i = 0; i < x[0].size(); ++i)
            ints[i].push_back(x[0][i].second);
        for (int i = 1; i < n; ++i)
        {
            if (x[i - 1].size() != x[i].size())
            {
                flag = true;
            }
            else
            {
                for (int j = 0; j < x[i].size(); ++j)
                {
                    if (x[i][j].first != x[i - 1][j].first)
                        flag = 1;
                    ints[j].push_back(x[i][j].second);
                }
            }
        }
        if (flag)
        {
            cout << "Fegla Won\n";
            continue;
        }
        long long answer = 0;
        for (int i = 0; i < x[0].size(); ++i)
        {
            sort(ints[i].begin(), ints[i].end());
            long long xx = ints[i][ints[i].size() / 2];
            for (int j = 0; j < n; ++j)
                answer += abs(xx - ints[i][j]);
        }
        cout << answer << "\n";
    }
}