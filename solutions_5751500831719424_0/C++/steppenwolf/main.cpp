#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test)
    {
        int n;
        cin >> n;

        vector<string> s(n);
        vector<int> pos(n, 0);

        for (int i = 0; i < n; ++i)
        {
            cin >> s[i];
        }

        bool bad = false;
        int res = 0;
        while (pos[0] < s[0].size())
        {
            char cur = s[0][pos[0]];
            vector<int> qnt(n);

            int mx = 0;

            for (int j = 0; j < n; ++j)
            {
                while (pos[j] < s[j].size() && s[j][pos[j]] == cur)
                {
                    ++pos[j];
                    ++qnt[j];
                }
                if (!qnt[j])
                {
                    bad = true;
                }
                else
                {
                    mx = max(mx, qnt[j]);
                }
            }

            int minDiff = 1000000000;
            for (int r = 1; r <= mx; ++r)
            {
                int diff = 0;
                for (int j = 0; j < n; ++j)
                {
                    diff += abs(qnt[j] - r);
                }
                minDiff = min(minDiff, diff);
            }

            res += minDiff;
        }

        for (int i = 0; i < n; ++i)
        {
            if (pos[i] < s[i].size()) bad = true;
        }

        cout << "Case #" << test << ": ";
        if (bad)
        {
            cout << "Fegla Won" << endl;
        }
        else
        {
            cout << res << endl;
        }
    }

    return 0;
}
