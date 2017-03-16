#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string t;

vector<int> compress(string s)
{
    t = s[0];
    vector<int> ans(1, 1);
    for (int i = 1; i < (int)s.size(); ++i)
    {
        if (s[i] == t[t.size() - 1])
        {
            ++ans.back();
        }
        else
        {
            t += s[i];
            ans.push_back(1);
        }
    }
    return ans;
}

int main(void)
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> s[j];
        }
        vector<vector<int> > compressed;
        compressed.push_back(compress(s[0]));
        string backup = t;
        for (int j = 1; j < n; ++j)
        {
            compressed.push_back(compress(s[j]));
            if (t != backup)
            {
                break;
            }
        }
        if (t != backup)
        {
            cout << "Case #" << (i + 1) << ": Fegla won\n";
            continue;
        }
        int price = 0;
        for (int j = 0; j < (int)compressed[0].size(); ++j)
        {
            int sum = 0;
            for (int k = 0; k < n; ++k)
            {
                sum += compressed[k][j];
            }
            int len = round(sum * 1.0 / n);
            for (int k = 0; k < n; ++k)
            {
                price += abs(compressed[k][j] - len);
            }
        }
        cout << "Case #" << (i + 1) << ": " << price << "\n";
    }
    return 0;
}
