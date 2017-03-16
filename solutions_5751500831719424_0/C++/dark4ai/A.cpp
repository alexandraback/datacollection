#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

const int INF = 1234567890;

int n;
string s[110];
vector<pair<char, int> > sm[110];

vector<pair<char, int> > get_model(int i) {
    vector<pair<char, int> > si;
    char prev = 0;
    for(int k = 0; k < (int)s[i].size(); ++k) {
        if(s[i][k] != prev) {
            prev = s[i][k];
            si.push_back(make_pair(prev, 1));
        } else {
            si.rbegin()->second++;
        }
    }
    return si;
}

int main() {
#ifdef DEBUG
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> n;
        int sz = -1;
        int ans = 0;
        bool ok = true;
        for(int i = 0; i < n; ++i) {
            cin >> s[i];
            sm[i] = get_model(i);
            if(sz == -1) sz = (int)sm[i].size();
            if(sz != (int)sm[i].size()) ok = false;
        }
        if(ok) {
            for(int i = 0; i < sz; ++i) {
                char c = sm[0][i].first;
                int mn = INF, mx = -INF;
                for(int j = 0; j < n; ++j) {
                    if(c != sm[j][i].first) {
                        ok = false;
                        break;
                    }
                    mn = min(mn, sm[j][i].second);
                    mx = max(mx, sm[j][i].second);
                }
                if(!ok) break;
                int cost = INF;
                for(int l = mn; l <= mx; l++) {
                    int l_cost = 0;
                    for(int j = 0; j < n; ++j) {
                        l_cost += abs(sm[j][i].second - l);
                    }
                    cost = min(l_cost, cost);
                }
                ans += cost;
            }
        }
        printf("Case #%d: ", t);
        if(!ok) {
            printf("Fegla Won\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}