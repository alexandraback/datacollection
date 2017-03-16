#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

void convert(string s, vector<int> &c, string &r) {
    char last = '\0';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == last) {
            c[c.size() - 1] += 1;
            continue;
        } else {
            last = s[i];
            r += last;
            c.push_back(1);
        }
    }
}

int find(vector<int> v) {
    int min_i = 100000, max_i = 0;
    for (auto i : v) {
        min_i = min(min_i, i);
        max_i = max(max_i, i);
    }
    int best = 100000;
    for (int j = min_i; j <= max_i; j++) {
        int g  = 0;
        for (auto i : v) {
            g += abs(i - j);
        }
        best = min(best, g);
    }
    return best;
}

int main() {
    int tcc;
    scanf("%d", &tcc);
    for (int tc = 1; tc <= tcc; tc++) {
        int n;
        scanf("%d", &n);
        vector<string> ss;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            ss.push_back(s);
        }
        vector<vector<int> > counts(n);
        string c;
        convert(ss[0], counts[0], c);
        bool match = true;
        for (int i = 1; i < n; i++) {
            string h;
            convert(ss[i], counts[i], h);
            match = h == c;
            if (!match) break;
        }
        printf("Case #%d: ", tc);
        if (match) {
            int r = 0;
            for (int j = 0; j < c.size(); j++) {
                vector<int> v;
                for (int i = 0; i < n; i++) {
                    v.push_back(counts[i][j]);
                }
                r += find(v);
            }
            printf("%d\n", r);
        } else {
            printf("Fegla Won\n");
        }
    }
    return 0;
}
