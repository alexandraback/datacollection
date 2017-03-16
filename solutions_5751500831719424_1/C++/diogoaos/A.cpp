#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

typedef long long lint;

using namespace std;

int main() {
    int ntests, n;
    scanf("%d", &ntests);
    
    char line[110];
    for (int test = 1; test <= ntests; test++) {
        scanf("%d", &n);
        vector< pair<char, int> > str[n];
        
        for (int i = 0; i < n; i++) {
            scanf("%s", line);
            char c = -1;
            for (int j = 0; line[j] != 0; j++) {
                if (line[j] != c) {
                    str[i].push_back(make_pair(line[j], 1));
                    c = line[j];
                } else {
                    str[i].back().second++;
                }
            }
        }
        
        int sz = str[0].size();
        bool ok = true;
        
        for (int i = 0; i < n; i++) {
            if ((int) str[i].size() != sz) {
                ok = false;
            }
        }
        
        if (ok) {
            for (int j = 0; j < sz; j++) {
                for (int i = 1; i < n; i++) {
                    if (str[i][j].first != str[i - 1][j].first) {
                        ok = false;
                    }
                }
            }
        }
        
        if (ok) {
            int ans = 0;
            for (int j = 0; j < sz; j++) {
                int m = 0;
                for (int i = 0; i < n; i++) {
                    m = max(m, str[i][j].second);
                }
                
                int best = 100000;
                for (int k = 1; k <= m; k++) {
                    int s = 0;
                    for (int i = 0; i < n; i++) {
                        s += abs(str[i][j].second - k);
                    }
                    best = min(best, s);
                }
                
                ans += best;
            }
            printf("Case #%d: %d\n", test, ans);
        } else {
            printf("Case #%d: Fegla Won\n", test);
        }
    }
    
    return 0;
}

