#include <iostream>

using namespace std;

void solve(void)
{
    bool vis[17] = {};
    int r;
    cin >> r;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int t;
            cin >> t;
            if (i == r - 1)
            {
                vis[t] = true;
            }
        }
    }
    int cnt = 0;
    int ans;
    cin >> r;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int t;
            cin >> t;
            if ((i == r - 1) && vis[t])
            {
                ++cnt;
                ans = t;
            }
        }
    }
    if (cnt == 1)
    {
        cout << ans << endl;
    }
    else if (cnt == 0)
    {
        cout << "Volunteer cheated!" << endl;
    }
    else
    {
        cout << "Bad magician!" << endl;
    }
}

int main(void)
{
    int numTest;
    cin >> numTest;
    for (int testCase = 1; testCase <= numTest; ++testCase)
    {
        cout << "Case #" << testCase << ": ";
        solve();
    }
    return 0;
}
