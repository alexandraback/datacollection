#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

bool ordcheck(vector<string> trg) {
    for (int i = 0; i < trg.size(); ++i) {
        trg[i].resize(unique(trg[i].begin(), trg[i].end()) - trg[i].begin());
        if (i > 0 && trg[i] != trg[i - 1])
            return false;
    }
    return true;
}

vector<int> grsz(const string& src) {
    char prv = src[0];
    int cnt  = 0;
    vector<int> ans;
    for (int i = 0; i < src.size(); ++i) {
        if (prv ==  src[i]) {
            ++cnt;
        } else {
            ans.push_back(cnt);
            cnt = 1;
        }
        prv = src[i];
        if (i + 1 == src.size()) ans.push_back(cnt);
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        int N; cin >> N;
        vector<string> inp(N, "");
        for (int i = 0; i < N; ++i) {
            cin >> inp[i];
        }
        bool can = ordcheck(inp);
        if (!can) {
            cout << "Case #" << _ << ": " << "Fegla Won" << endl;
            continue;
        }
        vector<int> fv = grsz(inp[0]);
        vector<int> sv = grsz(inp[1]);
        int res = 0;
        for (int i = 0; i < fv.size(); ++i) {
            int diff = fv[i] - sv[i];
            if (diff < 0) diff = - diff;
            res += diff;
        }

        cout << "Case #" << _ << ": " << res  << endl;
    }
}
