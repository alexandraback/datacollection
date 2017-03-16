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

int getopt(vector<int>& fact) {
    sort(fact.begin(), fact.end());
    int ln = fact.size(), sum = 0;
    for (int i = 0; i < fact.size(); ++i) sum += fact[i];
    int bst = sum;
    for (int i = 0; i < fact.size(); ++i) {
        int dlt = (i > 0) ?  (fact[i] - fact[i - 1]) : fact[0];
        sum -= dlt * (ln - i);
        sum += dlt * (i);
        bst = min(bst, sum);
    }
    return bst;
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
        int res = 0;
        vector<vector<int> > tabl;
        for(int i = 0; i < N; ++i) {
            tabl.push_back(grsz(inp[i]));
        }
        int grct = tabl[0].size();
        for (int i = 0; i < grct; ++i) {
            vector<int> curg;
            for (int j = 0; j < N; ++j) {
                curg.push_back(tabl[j][i]);
            }
            res += getopt(curg);
        }

        cout << "Case #" << _ << ": " << res  << endl;
    }
}
