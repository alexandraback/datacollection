//
//  A.cpp
//  
//
//  Created by John Nevard on 5/3/14.
//
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<string> VS;
typedef vector<int> VI;

string get_grps(const string& s) {
    string ltrs;
    ltrs.push_back(s[0]);
    for (int j = 1; j < s.size(); ++j)
        if (s[j] != s[j - 1])
            ltrs.push_back(s[j]);
    return ltrs;
}

int make_equal(VI& a) {
/*
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << ' ';
    cout << '\n';
*/
    sort(a.begin(), a.end());
    int ng = a.size();
    int lo = a[0];
    int hi = a[ng - 1];
    int best = 2000000000;
    for (int i = lo; i <= hi; ++i) {
        int ne = 0;
        for (int j = 0; j < ng; ++j)
            ne += abs(i - a[j]);
        if (ne < best)
            best = ne;
    }
    return best;
}

int main() {
    int nc;
    cin >> nc;
    for (int i = 1; i <= nc; ++i) {
        int n;
        cin >> n;
        VS s(n);
        for (int j = 0; j < n; ++j)
            cin >> s[j];
        string ltrs = get_grps(s[0]);
        bool can = true;
        for (int j = 1; j < n; ++j) {
            string l2 = get_grps(s[j]);
            if (l2 != ltrs) {
                can = false;
                break;
            }
        }
        if (!can) {
            cout << "Case #" << i << ": " << "Fegla Won" << '\n';
            continue;
        }
        int n_grps = ltrs.size();
        vector<VI> g(n_grps, VI(n, 0));
        for (int j = 0; j < n; ++j) {
            int prev = 0;
            for (int k = 1, l = 0; k < s[j].size(); ++k) {
                if (s[j][k] != s[j][k - 1]) {
                    g[l++][j] = k - prev;
                    prev = k;
                }
            }
            g[n_grps - 1][j] = s[j].size() - prev;
        }
/*
        for (int j = 0; j < n_grps; ++j) {
            for (int k = 0; k < n; ++k)
                cout << g[j][k] << ' ';
            cout << '\n';
        }
        cout << '\n';
*/
        
        int n_edits = 0;
        for (int j = 0; j < n_grps; ++j)
            n_edits += make_equal(g[j]);
        cout << "Case #" << i << ": " << n_edits << '\n';
    }
    return 0;
}