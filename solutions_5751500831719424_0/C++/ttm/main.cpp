#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        cout << "Case #" << cas << ": ";
        int n; cin >> n;
        vector<string> s(n);
        for (string& str : s) cin >> str;
        vector<vector<pair<char, int>>> p(n);
        for (int i = 0; i < n; ++i) {
            char prev = '\0';
            for (char c : s[i]) {
                if (c == prev) p[i].back().second++;
                else p[i].emplace_back(c, 1);
                prev = c;
            }
        }
        bool ok = true;
        for (int i = 1; ok && i < n; ++i) {
            if (p[i].size() != p[i - 1].size()) ok = false;
        }
        for (int j = 0; ok && j < p[0].size(); ++j) {
            for (int i = 1; ok && i < n; ++i) {
                ok = p[i][j].first == p[i-1][j].first;
            }
        }
        if (!ok) {
            cout << "Fegla Won\n";
            continue;
        }
        int pts = 0;
        for (int j = 0; j < p[0].size(); ++j) {
            sort(p.begin(), p.end(), [=](const vector<pair<char, int>>& a, const vector<pair<char, int>>& b) -> bool { return a[j].second < b[j].second; });
            int med = p[n / 2][j].second;
            for (int i = 0; i < n; ++i) {
                pts += abs(p[i][j].second - med);
            }
        }
        cout << pts << "\n";
    }
}
