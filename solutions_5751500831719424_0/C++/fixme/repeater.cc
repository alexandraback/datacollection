#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cstdlib>

using namespace std;

int solve(int N, const vector<string>& strs)
{
    vector<char> chs0;
    int len0 = (int)strs[0].size();
    for (int j = 0; j < len0; ++j)
    {
        if (j == 0 || strs[0][j] != strs[0][j - 1])
            chs0.push_back(strs[0][j]);
    }
    int runs = (int)chs0.size();
    for (int i = 1; i < N; ++i)
    {
        vector<char> chs;
        int len = (int)strs[i].size();
        for (int j = 0; j < len; ++j)
        {
            if (j == 0 || strs[i][j] != strs[i][j - 1])
                chs.push_back(strs[i][j]);
        }
        if (chs != chs0)
            return -1;
    }
    vector<vector<int> > runlens(N);
    for (int i = 0; i < N; ++i)
    {
        int len = (int)strs[i].size();
        int start = 0;
        for (int j = 1; j <= len; ++j)
        {
            if (j == len || strs[i][j] != strs[i][j - 1])
            {
                runlens[i].push_back(j - start);
                start = j;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < runs; ++i)
    {
        int ans1 = INT_MAX;
        int mn = INT_MAX;
        for (int k = 0; k < N; ++k)
        {
            if (runlens[k][i] < mn)
                mn = runlens[k][i];
        }
        int mx = 0;
        for (int k = 0; k < N; ++k)
        {
            if (runlens[k][i] > mx)
                mx = runlens[k][i];
        }
        for (int j = mn; j <= mx; ++j)
        {
            int ans2 = 0;
            for (int k = 0; k < N; ++k)
                ans2 += abs(runlens[k][i] - j);
            if (ans2 < ans1)
                ans1 = ans2;
        }
        ans += ans1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase)
    {
        int N;
        cin >> N;
        vector<string> strs(N);
        for (int i = 0; i < N; ++i)
            cin >> strs[i];
        int ans = solve(N, strs);
        cout << "Case #" << testcase << ": ";
        if (ans >= 0)
            cout << ans << "\n";
        else
            cout << "Fegla Won\n";
    }
    return 0;
}
