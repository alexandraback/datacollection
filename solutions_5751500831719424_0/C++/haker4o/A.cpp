#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<pii> disectS(string s) {
    int i, j;
    j=1;
    vector<pii> res;
    for(i=1; i<s.size(); ++i) {
        if (s[i] == s[i-1]) ++j;
        else {
            res.push_back(mp(s[i-1], j));
            j=1;
        }
    }
    res.push_back(mp(s[s.size()-1], j));
    return res;
}

bool compatible(const vector<pii> &v1, const vector<pii> &v2) {
    if (v1.size() != v2.size()) return false;
    for(int i=0; i<v1.size(); ++i) {
        if (v1[i].first != v2[i].first) return false;
    }
    return true;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int i, j;
    vector<vector<pii> > v;
    int T, NT, n;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        v.clear();
        cin>>n;
        for(i=0; i<n; ++i) {
            string s;
            cin>>s;
            v.push_back(disectS(s));
        }
        cout<<"Case #" << T << ": ";
        for(i=1; i<n; ++i) {
            if (!compatible(v[0], v[i])) break;
        }
        if (i < n) {
            cout<<"Fegla Won";
        } else {
            int res=0;
            for(i=0; i<v[0].size(); ++i) {
                int best;
                best = 1000000;
                for(j=1; j<=100; ++j) {
                    int cur;
                    cur = 0;
                    for(int k=0; k<n; ++k) {
                        cur += abs(j-v[k][i].second);
                    }
                    best = min(best, cur);
                }
                res += best;
            }
            cout<<res;
        }
        cout<<endl;
    }
    return 0;
}
