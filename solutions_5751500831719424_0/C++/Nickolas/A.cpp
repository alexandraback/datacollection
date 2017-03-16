#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string simplify(string s) {
    string ret = "";
    ret += s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            ret += s[i];
        }
    }
    return ret;
}

void debvi(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int equalize(vector<int> v) {
    int N = v.size();
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    int minm = v.size() * (mx - mn) * 2;
    for (int target = 1; target <= v[N - 1]; ++target) {
        // try to bring all numbers to target
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += abs(v[i] - target);
        }
        minm = min<int>(sum, minm);
    }
    return minm;
}

void solve(int ind) {
    // input
    int N;
    cin >> N;
    vector<string> str(N);
    for (int i = 0; i < N; ++i) {
        cin >> str[i];
    }

    // check possibility
    vector<string> simple(N);
    for (int i = 0; i < N; ++i) {
        simple[i] = simplify(str[i]);
        if (simple[i] != simple[0]) {
            // can't be brought to each other
            cout << "Case #" << ind << ": " << "Fegla Won" << endl;
            return;
        }
    }
    string simpl = simple[0];
    
    // [i][j] = how many times letter i is present in string j
    vector<vector<int> > nletters(simpl.size(), vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        int iletter = 0;
        for (int j = 0; j < str[i].size(); ) {
            if (simpl[iletter] == str[i][j]) {
                ++nletters[iletter][i];
                ++j;
            } else {
                ++iletter;
            }
        }
    }
//    for (int i = 0; i < simpl.size(); ++i) {
//        debvi(nletters[i]);
//    }
    // count moves necessary
    int moves = 0;
    for (int i = 0; i < simpl.size(); ++i) {
        moves += equalize(nletters[i]);
    }

    // output
    cout << "Case #" << ind << ": " << moves << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
}