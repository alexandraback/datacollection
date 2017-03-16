#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int T, n;
vector<pair<char, int> > a[N+5];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        vector<string> sl;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            char c = s[0];
            int count = 1;
            for (int j = 1; j < s.length(); j++) {
                if (s[j] == c) count++;
                else {
                    a[i].push_back(make_pair(c, count));
                    c = s[j];
                    count = 1;
                }
            }
            a[i].push_back(make_pair(c, count));
        }   
        bool possible = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (a[i].size() != a[j].size()) possible = false;
                for (int z = 0; z < a[i].size(); z++) 
                    if (a[i][z].first != a[j][z].first) possible = false;
            }
        if (!possible) printf("Case #%d: Fegla Won\n", t);
        else {
            int res = 0;
            for (int z = 0; z < a[0].size(); z++) {
                int max_possible = 1;
                for (int i = 0; i < n; i++) max_possible = max(max_possible, a[i][z].second);   
                int cur_res = 100000000;
                for (int i = 1; i <= max_possible; i++) {
                    int cur = 0;
                    for (int j = 0; j < n; j++) 
                        cur += abs(a[j][z].second-i);
                    cur_res = min(cur_res, cur);
                }
                res += cur_res;
            }
            printf("Case #%d: %d\n", t, res);
        }
        for (int i = 0; i < n; i++) a[i].clear();
    }   
    return 0;
}
