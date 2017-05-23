#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define pii pair<int, int>
#define INF 1000000000

vector<pii> v;
vector<int> v2[110];
int val(int x)
{
    return (x >= 0 ? x : -x);
}
int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 0;
        v.clear();
        while (i < s.length())
        {
            int j = i;
            while (i < s.length() && s[i] == s[j])
                i++;
            v2[v.size()].clear();
            v2[v.size()].push_back(i - j);
            v.push_back(pii(s[j], i - j));
        }
        int ans = 0;
        bool cant = false;
        for (i = 1; i < n; i++)
        {
            string t;
            cin >> t;
            int j = 0, ptr = 0;
            while (j < t.length())
            {
                int k = j;
                while (k < t.length() && t[j] == t[k])
                    j++;
                if (ptr == v.size() || t[k] != v[ptr].first)
                    cant = true;
                else
                {
                    v2[ptr].push_back(j - k);
                    ptr++;
                }
            }
            if (ptr != v.size())
                cant = true;
        }
        for (int i = 0; i < v.size(); i++)
        {
            int tmp = INF;
            //int sumbig = 0, sumlow = 0;
            /*sort(v2[i].begin(), v2[i].end());
            for (int j = 0; j < v2[i].size(); j++)
                sumbig += v2[i][j];
            for (int j = 0; j < v2[i].size(); j++)
            {
                tmp = min(tmp, v2[i][j] * j - sumlow + sumbig - v2[i][j] * ((int)v2[i].size() - j));
                sumbig -= v2[i][j];
                sumlow += v2[i][j];
            }*/
            for (int j = 0; j < v2[i].size(); j++)
            {
                int t2 = 0;
                for (int k = 0; k < v2[i].size(); k++)
                    t2 += val(v2[i][k] - v2[i][j]);
                tmp = min(tmp, t2);
            }
            ans += tmp;
        }
        cout << "Case #" << tc << ": ";
        if (cant)
            cout << "Fegla Won" << endl;
        else
            cout << ans << endl;
    }
}
