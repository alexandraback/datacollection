#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef pair<string, vector<int>> profile;

profile canonise(string &s) {
    vector<int> v;
    string r;
    r += s[0];
    int g = 0;
    for(int i = 1; i < s.length(); i ++)
        if(s[i-1] == s[i])
            g ++;
        else {
            v.push_back(g);
            r += s[i];
            g = 1;
        }
    v.push_back(g);
    return make_pair(r, v);
}

void solve() {
    int n;
    cin >> n;
    profile prfy[n];
    string s;
    for(int i = 0; i < n; i ++) {
        cin >> s;
        prfy[i] = canonise(s);
    }
    string cs = prfy[0].first;
    vector<int> medi[cs.length()];
    for(int i = 0; i < n; i ++) {
        if(prfy[i].first != cs) {
            cout << "Fegla Won";
            return;
        }
        for(int j = 0; j < cs.length(); j ++)
            medi[j].push_back(prfy[i].second[j]);
    }
    for(int i = 0; i < cs.length(); i ++)
        sort(medi[i].begin(), medi[i].end());
    int w = 0;
    for(int i = 0; i < cs.length(); i ++)
        for(int j = 0; j < n; j ++)
            w += abs(medi[i][j] - medi[i][n/2]);
    cout << w;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++) {
        cout << "Case #"<< i << ": ";
        solve();
        cout << endl;
    }
}