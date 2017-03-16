
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#define MAXN 100

using namespace std;

int N;
string s[MAXN];

string get_reduced(const string &t) {
    string r = "";
    r += t[0];
    for (int i = 1; i < t.size(); i++)
        if (t[i] != t[i - 1])
            r += t[i];
    //cerr << r << endl;
    return r;
}

vector <int> get_cnts(const string &t) {
    vector <int> cnts;
    char cur = t[0];
    int cnt = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != cur)
            cnts.push_back(cnt), cur = t[i], cnt = 1;
        else
            cnt++;
    }
    cnts.push_back(cnt);
    /*
    for (int i = 0; i < cnts.size(); i++)
        cerr << cnts[i] << " ";
    cerr << endl;
    */
    return cnts;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> s[i];

    string r = get_reduced(s[0]);
    vector <vector <int>> all_cnts;
    all_cnts.push_back(get_cnts(s[0]));
    for (int i = 1; i < N; i++) {
        if (get_reduced(s[i]) != r) {
            cout << "Fegla Won" << endl;
            return;
        }
        all_cnts.push_back(get_cnts(s[i]));
    }

    int total = 0;
    for (int j = 0; j < all_cnts[0].size(); j++) {
        vector <int> vals;
        for (int i = 0; i < N; i++)
            vals.push_back(all_cnts[i][j]);
        sort(vals.begin(), vals.end());

        int median = vals[N / 2];
        for (int i = 0; i < N; i++)
            total += abs(median - vals[i]);
    }
    cout << total << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

