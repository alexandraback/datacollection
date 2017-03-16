#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        vector<char> possible(17, true);
        int l_n;
        cin >> l_n;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int x;
                cin >> x;
                possible[x] &= i == l_n - 1;
            }
        }
        cin >> l_n;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int x;
                cin >> x;
                possible[x] &= i == l_n - 1;
            }
        }
        vector<int> ans;
        for (int i = 1; i < 17; i++)
            if (possible[i])
                ans.push_back(i);
        cout << "Case #" << tc << ": ";
        if (ans.size() == 1)
            cout << ans.back();
        else if (ans.size() > 1)
            cout << "Bad magician!";
        else cout << "Volunteer cheated!";
        cout << endl;
    }
    return 0;
}
