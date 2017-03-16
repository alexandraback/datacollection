#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a.push_back(s);
    }
    string et;
    vector<vector<int> > p;
    vector<int> govno;
    for (int q = 0; q < n; q++)
    {
        p.push_back(govno);
        string k;
        int l = 0, r = -1;
        while (l < a[q].length())
        {
            while (a[q][r + 1] == a[q][l])
                r++;
            p[q].push_back(r - l + 1);
            k = k + a[q][l];
            l = r + 1;
        }
        if (q == 0)
            et = k;
        else
            if (et != k)
            {
                cout << "Fegla Won\n";
                return;
            }
    }
    
    int result = 0;
    for (int i = 0; i < et.length(); i++){
        int res = 1000000000;
        for (int k = 1; k <= 100; k++)
        {
            int w = 0;
            for (int e = 0; e < n; e++)
                w += abs(k - p[e][i]);
            res = min(res, w);
            //cout << i + 1 << " " << k << " " << res << endl;
        }
        result += res;
    }
    cout << result << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" <<  i + 1 << ": ";
        solve();
    }
}

