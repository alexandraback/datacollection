#include <cstdio>
#include <sstream>
#include <cassert>
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <queue>
#include <utility>

using namespace std;
#define INF (1<<28)

int N;
vector<string> ss;

vector< pair<char, int> > split(const string& s) {
    vector< pair<char, int> > ret;
    char prev = s[0];
    int c = 1;
    int i = 1;
    while (i < s.size()) {
        if (s[i] == prev) {
            c++;
        } else {
            ret.push_back(make_pair(prev, c));
            prev = s[i];
            c = 1;
        }
        i++;
    }
    ret.push_back(make_pair(prev, c));
    return ret;
}

string to_s(int n) {
    ostringstream os;
    os << n;
    return os.str();
}

string solve() {
    typedef vector< pair<char, int> > R;
    vector<R> r;
    for (int i = 0; i < N; i++) {
        r.push_back(split(ss[i]));
    }
    vector<string> x;
    for (int i = 0; i < N; i++) {
        string s;
        for (int j = 0; j < r[i].size(); j++) {
            s.push_back(r[i][j].first);
        }
        x.push_back(s);
    }
    for (int i = 0; i < N; i++) {
        if (x[0] != x[i]) {
            return string("Fegla Won");
        }
    }

    int ans = 0;
    int M = r[0].size();
    for (int m = 0; m < M; m++) {
        int d1 = INF;
        for (int d = 1; d <= 100; d++) {
            int d2 = 0;
            for (int n = 0; n < N; n++) {
                d2 += abs(r[n][m].second - d);
            }
            d1 = min(d1, d2);
        }
        ans += d1;
    }
    return to_s(ans);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        cin >> N;
        ss.resize(N);
        for (int i = 0; i < N; i++) cin >> ss[i];
        cout << solve() << endl;
    }
    return 0;
}
