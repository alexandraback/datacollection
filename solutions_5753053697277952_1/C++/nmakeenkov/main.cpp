#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int c = 0; c < t; ++c) {
        int n;
        cin >> n;
        vector<pair<int, char>> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i].first;
            p[i].second = char(int('A') + i);
        }
        cout << "Case #" << c + 1 << ": ";
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        while (p[0].first > p[1].first) {
            cout << p[0].second << " ";
            p[0].first--;
        }
        string res = "";
        for (int i = 2; i < n; ++i) {
            for (int j = 0; j < p[i].first; ++j) {
                res.push_back(p[i].second);
            }
        }
        for (int i = 0; i < (int)res.size(); ++i) {
            cout << res[i];
            if (i % 2 == 1 && i != (int)res.size() - 1) {
                cout << " ";
            }
        }
        if (res.size() > 0) {
            cout << " ";
        }
        for (int i = 0; i < p[0].first; ++i) {
            cout << p[0].second << p[1].second << " ";
        }
        cout << "\n";
    }
    return 0;
}