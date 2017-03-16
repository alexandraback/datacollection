#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1234567890;
typedef pair<string, vector<int>> psv;
psv signature(const string &s) {
    string t;
    vector<int> cnt;
    int i = 0;
    while (i < (int)s.size()) {
        int j = i+1;
        while (j<(int)s.size() && s[j]==s[i]) {
            ++j;
        }
        t += s[i];
        cnt.push_back(j-i);
        i = j;
    }
    return psv(t, cnt);
}
int calc(int pos, const vector<psv> &v) {
    int lo = INF;
    int hi = -INF;
    for (int i=0; i<(int)v.size(); ++i) {
        lo = min(lo, v[i].second[pos]);
        hi = max(hi, v[i].second[pos]);
    }
    int ret = INF;
    for (int cnt=lo; cnt<=hi; ++cnt) {
        int cand = 0;
        for (int i=0; i<(int)v.size(); ++i) {
            cand += abs(v[i].second[pos]-cnt);
        }
        ret = min(ret, cand);
    }
    return ret;
}
int solve() {
    int n;
    cin >> n;
    vector<psv> v;
    bool failed = false;
    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        v.push_back(signature(s));
        if (i>0 && v[i].first!=v[i-1].first) {
            failed = true;
        }
    }
    if (failed) {
        return INF;
    }
    int sol = 0;
    int numsegments = v[0].first.size();
    for (int i=0; i<numsegments; ++i) {
        sol += calc(i, v);
    }
    return sol;
}

int main() {
    int T;
    cin >> T;
    cerr << T << " cases total\n";
    for (int t=1; t<=T; ++t) {
        int sol = solve();
        if (sol == INF) {
            cout << "Case #" << t << ": " << "Fegla Won" << '\n';
        } else {
            cout << "Case #" << t << ": " << sol << '\n';
        }
        cerr << "Case #" << t << ": " << sol << '\n';
    }
	return 0;
}
