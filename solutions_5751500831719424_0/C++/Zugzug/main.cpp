#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    freopen("2A4.in", "r", stdin);
    freopen("2A4.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s1, s2;
        int n;
        cin >> n;
        cin >> s1 >> s2;
        int j = 0;
        int k = 0;
        bool flag = false;
        int ans = 0;
        while (j < s1.length() || k < s2.length())
        {
            int j1 = j;
            if ((j >= s1.length() && k < s2.length()) ||(j < s1.length() && k >= s2.length()))
            {
                flag = true;
                cout << "Case #" << i + 1 << ": Fegla Won" << endl;
                break;
            }
            while (s1[j1] == s1[j1 + 1] && j1 + 1 < s1.length())
                j1++;
            int k1 = k;
            while (s2[k1] == s2[k1 + 1] && k1 + 1 < s2.length())
                k1++;
            if (s1[j] != s2[k])
            {
                flag = true;
                cout << "Case #" << i + 1 << ": Fegla Won" << endl;
                break;
            }
            if (s1[j] == s2[k])
            {
                ans += abs((j1 - j) - (k1 - k));
            }
            j = j1 + 1;
            k = k1 + 1;
        }
        if (!flag)
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }

}
