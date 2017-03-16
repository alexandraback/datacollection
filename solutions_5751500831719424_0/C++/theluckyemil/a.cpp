#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>

#define ll long long
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int maxn = 105;
const int md = 1e9+7;

string cont[maxn];

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test; cin >> test;
    for (int it=0; it<test; it++) {
        int n; cin >> n;
        for (int i=0; i<n; i++) {
            cin>>cont[i];
        }
        vector<vector<pair<char, int> > > seq(n);
        int ok = 1;

        for (int i=0; i<n; i++) {
            string s = cont[i];
            int sz=s.size();
            int pt = 0;

            while (pt<sz) {
                int amo = 1;
                while (pt+1 < sz && s[pt]==s[pt+1]) {
                    pt++, amo++;
                }
                seq[i].push_back(make_pair(s[pt], amo));
                pt++;
            }
            if (i > 0) {
                if (seq[i].size() != seq[i - 1].size()) {
                    ok = 0;
                } else {
                    for (int j=0; j<seq[i].size(); j++) {
                        if (seq[i][j].first != seq[i - 1][j].first) {
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            if (!ok) {
                break;
            }
        }
        if (!ok) {
            printf("Case #%d: Fegla Won\n", it+1);
        } else {
            int ans = 0;
            int cl = seq[0].size();
            for (int i=0; i<cl; i++) {
                int id = 0, val = int(2e9);
                for (int j=0; j<n; j++) {
                    int x=seq[j][i].second, sum = 0;
                    for (int k=0; k<n; k++) {
                        sum += abs(seq[k][i].second - seq[j][i].second);
                    }
                    if (sum < val) {
                        val = sum, id = j;
                    }
                }
                ans += val;
            }
            printf("Case #%d: %d\n", it+1, ans);
        }
    }
    return 0;
}
