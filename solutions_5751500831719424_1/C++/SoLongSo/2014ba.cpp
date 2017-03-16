#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdint>

#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <set>

#include <string>

#include <stdint.h>
#include <limits>

using namespace std;

#define INF 1000000000
//FORE only want to repeat, so iterator will not be visible outside
#define FORE(a, b, c) for(int a = b; a < c; a++)

typedef pair<int, int> pii;
typedef long long ll;

struct A {
    char p[50];
    bool operator < (const A &q) const {
        return strcmp(p, q.p) < 0;
    }
} q[200], tar[200];

int main() {
    freopen("2014ba.in", "r", stdin);
    freopen("2014ba.ot", "w", stdout);
    int T, t = 0;
    cin >> T;
    string tstr;
    getline(cin,tstr); 

    while (t++ < T) {
        printf("Case #%d: ", t);
        vector< string> strs(150);
        int N;
        cin >> N;
        getline(cin,tstr); 
        FORE (i, 0, N)
            getline(cin, strs[i]);

        int ans = 0;
        while (true) {
            if (strs[0].size() == 0) {
                for (int j = 0; j < N; j++) {
                    if (strs[j].size() != 0)
                        goto fail;
                }
                goto finish;
            }

            int v[N+1];
            char ch = strs[0][0];
            for (int i = 0; i < N; i++) {
                int n = 0;
                while(strs[i][n] == ch) n++;
                if (n == 0) goto fail;
                v[i] = n;
                strs[i] = strs[i].substr(n);
            }

            int ans_i = INF;
            for (int i = 0; i < N; i++) {
                int t = v[i];
                int t_ans = 0;
                for (int j = 0; j < N; j++) {
                    t_ans += abs(t - v[j]);
                }
                ans_i = min(ans_i, t_ans);
            }
            ans += ans_i;
        }

    fail:
            printf("Fegla Won\n");
            continue;
    finish:
            printf("%d\n", ans);
    }
}
