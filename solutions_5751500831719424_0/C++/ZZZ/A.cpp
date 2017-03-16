#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>

#include <algorithm>

#include <vector>

#include <stack>
#include <queue>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int clapse(string &s, string &p, vector<int> &freq) {
    int cur = 0;
    int beg = 0;
    int end = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i + 1 == s.size() || (i+1 < s.size() && s[i] != s[i+1])) {
            end = i+1;
            p.push_back(s[i]);
            freq.push_back(end-beg);
            beg = end;
        }
    }
}

int minDist(string &word1, string &word2) {
    int n = word1.size();
    int m = word2.size();
    int f[n+1][m+1];
    for (int i = 0; i <= n; ++i) f[i][0] = i;
    for (int j = 0; j <= m; ++j) f[0][j] = j;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[i-1] == word2[j-1]) 
                f[i][j] = f[i-1][j-1];
            else
                f[i][j] = min(f[i-1][j], f[i][j-1]);

        }
    }
    return f[n][m];
}

int abs(int x) { return x >= 0? x: -x; }

int f(vector<vector<int> > freqs, int idx, int max_len) {
    int min_val = -1;
    for (int x = 1; x <= max_len; ++x) {
        int tmp = 0;
        for (int i = 0; i < freqs.size(); ++i) {
            tmp += abs(x - freqs[i][idx]);
        }
        if (min_val == -1) {
            min_val = tmp;
        } else  {
            min_val = min(min_val, tmp);
        }
    }
    return min_val;
}
int max(int a, int b) {
    return a > b? a: b;
}

int main() {
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; Case++) {
        int n;
        cin >> n;
        vector<string> vs;
        string s;
        int len = 0;
        int max_len = -1;
        vector<vector<int> > freqs;
        vector<string> ps;
        for (int i = 0; i < n; ++i)  {
            cin >> s;
            max_len = max(max_len, s.size());
            string p;
            vector<int> freq;
            clapse(s, p, freq);
            len = p.size();
            freqs.push_back(freq);
            ps.push_back(p);
        }

        set<string> ss(ps.begin(), ps.end());

        if (ss.size() == 1) {
            int sum = 0;
            for (int idx = 0; idx < len; ++idx) {
                sum += f(freqs, idx, max_len);
            }
            printf("Case #%d: %d\n", Case, sum);
        } else {
            printf("Case #%d: Fegla Won\n", Case);
        }

        freqs.clear();
        ps.clear();
    }
}
