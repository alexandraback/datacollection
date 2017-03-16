#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <cstdlib>

using namespace std;

const int maxn = 100;
const int INF = maxn * maxn * maxn;

string g;
int main()
{
    int test_num;
    cin >> test_num;
    for (int test = 0; test < test_num; ++test) {
        int n;
        vector <pair <char, int> > s[maxn];
        scanf("%d\n", &n);
        for (int i = 0; i < n; ++i) {
            getline(cin, g);
            g += '#';
            char c = g[0];
            int col = 1;
            for (int j = 1; j < g.length(); ++j) {
                if (g[j] != c) {
                    s[i].push_back(make_pair(c, col));
                    c = g[j];
                    col = 1;
                } else
                    ++col;
            }
        }

        bool ok = true;
        for (int i = 1; i < n; ++i)
            if (s[i - 1].size() != s[i].size())
                ok = false;

        if (ok) {
            for (int i = 1; i < n; ++i)
                for (int j = 0; j < s[0].size(); ++j)
                    if (s[i - 1][j].first != s[i][j].first)
                        ok = false;
        }

        cout << "Case #" << test + 1 << ": ";
        if (ok) {
            int res = 0;
            for (int i = 0; i < s[0].size(); ++i) {
                int minadd = INF;
                for (int tobe = 1; tobe <= maxn; ++tobe) {
                    int nowadd = 0;
                    for (int j = 0; j < n; ++j)
                        nowadd += abs(s[j][i].second - tobe);
                    minadd = min(minadd, nowadd);
                }
                res += minadd;
            }
            cout << res << "\n";
        }

        if (!ok)
            cout << "Fegla Won\n";

    }
    return 0;
}
