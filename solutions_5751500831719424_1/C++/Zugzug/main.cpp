#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s[n];
        int a[n];
        int a1[n];
        for (int j = 0; j < n; j++)
        {
            cin >> s[j];
        }
        int j = 0;
        int k = 0;
        bool flag = false;
        int ans = 0;
        for (int l = 0; l < n; l++)
        {
            a[l] = 0;
            a1[l] = 0;
        }
        int anss = 0;
        while (!flag)
        {

            int e = 0;
            for (int l = 0; l < n; l++)
            {
                if (a[l] > s[l].length())
                {
                    e++;
                }
            }
            //cout << e << endl;
            if (e != 0 && e != n) {
                flag = true;
                    cout << "Case #" << i + 1 << ": Fegla Won" << endl;
                    //cout << "*";
                    break;
            }
            if (e == n)
            {
                flag = true;

        cout << "Case #" << i + 1 << ": " << anss << endl;
            }
            if (flag)
                break;
            for (int l = 0; l < n; l++)
            {
                string s1 = s[l];
                a1[l] = a[l];
                while (s1[a1[l]] == s1[a1[l] + 1] && a1[l] + 1 < s1.length())
                    a1[l]++;
            }
            //for (int l = 0; l < n; l++)
           //     cout << a1[l] << " " << a[l] << endl;
           // cout << endl;
            for (int l = 0; l < n - 1; l++)
            {
                string s1 = s[l];
                string s2 = s[l + 1];
                //cout << s1 << " " << s2 << endl;
                //cout << s1[a[l]] << " " << s2[a[l + 1]] << endl;
                if (s1[a[l]] != s2[a[l + 1]])
                {
                    flag = true;
                    cout << "Case #" << i + 1 << ": Fegla Won" << endl;

                    //cout << "#";
                    break;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
            int ansmin = INT_MAX;
            for (int l = 0; l < n; l++)
            {
                int w = a1[l] - a[l] + 1;
                int ans = 0;
                for (int l1 = 0; l1 < n; l1++)
                    ans += abs(w - (a1[l1] - a[l1] + 1));
                if (ans < ansmin)
                    ansmin = ans;

            }
            for (int l = 0; l < n; l++)
            {
                a[l] = a1[l] + 1;
            }
            anss += ansmin;
        }
        if (!flag)
        cout << "Case #" << i + 1 << ": " << anss << endl;
    }

}

