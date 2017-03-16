#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
void solve (int r, int c, int n, int i, vector<vector<bool> > &m, int &ans)
{
    if (i == r * c)
    {
        if (n > 0)
        {
            return;
        }
        int j, k, cr = 0;
        for (j = 0; j < r; ++j)
        {
            for (k = 0; k < c; ++k)
            {
                if (m[j][k])
                {
                    if (k > 0 && m[j][k - 1])
                    {
                        ++cr;
                    }
                    if (j > 0 && m[j -1][k])
                    {
                        ++cr;
                    }
                }
                //cout << j << " " << k << " " << cr << endl;
            }
        }
        ans = min(ans, cr);
        return;
    }
    solve(r, c, n, i + 1, m, ans);
    if (n > 0)
    {
        m[i / c][i % c] = 1;
        solve(r, c, n - 1, i + 1, m, ans);
        m[i / c][i % c] = 0;
    }
}
int main()
{
    ifstream cin("///Users/Zetilov/Downloads/B-small-attempt0.in-3.txt");
    ofstream fout("///Users/Zetilov/Documents/programs/test/test/outfile.txt");
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int t, z;
    cin >> t;
    for (z = 0; z < t; ++z)
    {
        int r, c, n, ans = 100;
        cin >> r >> c >> n;
        vector<vector<bool> > m(r, vector<bool>(c));
        solve(r, c, n, 0, m, ans);
        cout << z << endl;
        fout << "Case #" << z + 1 << ": " << ans << "\n";
    }
    return 0;
}