#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <complex>
#include <cmath>
#include <algorithm>
using namespace std;

string unique(const string &s) {
    string ret = s;
    ret.erase(unique(begin(ret), end(ret)), end(ret));
    return ret;
}

vector<int> tokenize(const string &s) {
    char prev = s[0];
    int cnt = 1;
    vector<int> ret;
    for (int i = 1; i < s.length(); ++i) {
        if (prev != s[i]) {
            ret.push_back(cnt);
            cnt = 0;
        }
        prev = s[i];
        cnt++;
    }
    ret.push_back(cnt);
    return ret;
}

void solve() {
    int N;
    cin>>N;
    vector<string> S(N), U(N);
    for (int i = 0; i < N; ++i) cin>>S[i];
    const string goal = unique(S[0]);
    for (int i = 0; i < N; ++i) {
        if (goal != unique(S[i])) {
            cout<<"Fegla Won"<<endl;
            return;
        }
    }

    vector<vector<int>> tokens;
    for (int i = 0; i < N; ++i) tokens.push_back(tokenize(S[i]));
    int ans = 0;
    for (int c = 0; c < tokens[0].size(); ++c) {
        int cans = 1<<29;
        for (int p = 0; p < N; ++p) {
            int r = 0;
            for (int i = 0; i < N; ++i) {
                r += abs<int>(tokens[p][c] - tokens[i][c]);
            }
            cans = min<int>(cans, r);
        }
        ans += cans;
    }
    cout<<ans<<endl;
}

int main() {
    int T;
    cin>>T;
    for (int tc=1; tc<=T; ++tc) {
        cout<<"Case #"<<tc<<": ";
        solve();
    }
}
