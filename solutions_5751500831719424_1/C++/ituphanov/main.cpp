#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>

using namespace std;

const int maxn = 110;

string s[maxn];
vector<int> rep[maxn];
vector<char> c[maxn];

int main()
{
    int T;
    cin >> T;
    for (int sc = 0; sc < T; sc++) {
        int n, i, j, k;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> s[i];
            s[i] += ' ';
            rep[i].clear();
            c[i].clear();
            k = 0;
            for (j = 0; j < s[i].length()-1; j++) {
                if (s[i][j] != s[i][j+1]) {
                    rep[i].push_back(j+1-k);
                    c[i].push_back(s[i][j]);
                    k = j+1;
                }
            }
        }

        int ok = 1;
        for (i = 1; i < n; i++) {
            if (c[i] != c[i-1])
                ok = 0;
        }

        if (ok) {
            int ans = 0;
            for (j = 0; j < c[0].size(); j++) {
                int min = rep[0][j];
                int max = rep[0][j];
                for (i = 0; i < n; i++) {
                    if (rep[i][j] < min) min = rep[i][j];
                    if (rep[i][j] > max) max = rep[i][j];
                }
                int best = -1;
                for (k = min; k <= max; k++) {
                    int cur = 0;
                    for (i = 0; i < n; i++)
                        cur += abs(rep[i][j] - k);
                    if (cur < best || best == -1)
                        best = cur;
                }
                ans += best;
            }
            cout << "Case #" << sc+1 << ": ";
            cout << ans;
            cout << endl;
        } else {
            cout << "Case #" << sc+1 << ": ";
            cout << "Fegla Won";
            cout << endl;
        }
    }
    
    return 0;
}
