#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<string, int> > v(n, make_pair("", 0));
    for (int i = 0; i < n; ++i) cin >> v[i].first;
    
    int cc = 0;
    for (;;) {
        vector<int> c;
        char ch = -1;
        for (auto& p: v) {
            string& ss = p.first;
            int& i = p.second;
            if (i >= ss.size()) continue;
            int start = i;
            if (ch == -1) ch = ss[i];
            else if (ch != ss[i]) {
                cout << "Fegla Won" << endl;
                return;
            }
            ++i;
            while (i < ss.size() && ss[i] == ss[i - 1]) ++i;
            c.push_back(i - start);
        }
        if (c.size() == 0) {
            cout << cc << endl;
            return;
        } else if (c.size() < n) {
            cout << "Fegla Won" << endl;
            return;
        } else {
            sort(c.begin(), c.end());
            int m = c[n / 2];
            for (int ii: c) cc += abs(ii - m);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    cout.flush();
    return 0;
}
