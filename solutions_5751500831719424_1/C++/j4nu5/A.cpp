#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <cmath>

using namespace std;

string convert(string &s) {
    string ans;
    int len = 0;
    for (char ch : s) {
        if ((!len) || (ans[len-1] != ch)) {
            ans += ch;
            len++;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int CN = 1; CN <= t; CN++) {
        int N;
        cin >> N;

        vector<string> strings;

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            strings.push_back(s);
        }

        string mstring = convert(strings[0]);
        bool possible = true;
        for (int i = 1; i < N; i++) {
            if (mstring != convert(strings[i])) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << "Case #" << CN << ": Fegla Won\n";
            continue;
        }

        // Calculate continous char f
        vector< vector<int> > charf(mstring.length());
        for (int i = 0; i < N; i++) {
            string s = strings[i];

            int f = 1, lim = s.length(), c = 0;
            for (int j = 1; j < lim; j++) {
                if (s[j] == s[j-1]) {
                    f++;
                }
                else {
                    charf[c++].push_back(f);
                    f = 1;
                }
            }
            charf[c++].push_back(f);
        }
        int ans = 0;
        for (int i = 0; i < charf.size(); i++) {
            sort(charf[i].begin(), charf[i].end());

            int m = charf[i][N/2];
            for (int j = 0; j < N; j++)
                ans += abs(charf[i][j] - m);
        }

        cout << "Case #" << CN << ": " << ans << "\n";
    }

    return 0;
}

