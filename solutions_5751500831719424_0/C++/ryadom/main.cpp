#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int qw;
    cin >> qw;
    for (int qwe = 0; qwe < qw; ++qwe)
    {
        cout << "Case #" << qwe + 1 << ": ";
        int n;
        cin >> n;
        vector<string> v(n);
        int l = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            l = max(l, (int)v[i].length());
        }
        vector<vector<pair<char, int> > > s(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < v[i].length(); ++j)
                if (j > 0 && v[i][j] == v[i][j - 1])
                    s[i].back().second++;
                else
                    s[i].push_back(make_pair(v[i][j], 1));
        }
        bool f = true;
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (s[i].size() != s[0].size())
            {
                f = false;
                goto end;
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < s[i].size(); ++j)
                if (s[i][j].first != s[0][j].first)
                {
                    f = false;
                    goto end;
                }
        for (int i = 0; i < s[0].size(); ++i)
        {
            int m = 0;
            int mans = 1000000000;
            for (int j = 0; j < n; ++j)
                m = max(m, (int)s[j][i].second);
            for (int j = 1; j <= m; ++j)
            {
                int q = 0;
                for (int k = 0; k < n; ++k)
                    q += abs(s[k][i].second - j);
                mans = min(mans, q);
            }
            ans += mans;
        }
        end:
        if (f)
            cout << ans;
        else
            cout << "Fegla Won";
        cout << endl;
    }
    return 0;
}
