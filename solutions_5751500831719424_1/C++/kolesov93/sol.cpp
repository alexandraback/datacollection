#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <string>
#include <time.h>

using namespace std;

int myabs(int x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    int TESTS;
    scanf("%d", &TESTS);

    for (int _t = 1; _t <= TESTS; ++_t) {
        printf("Case #%d: ", _t);
        
        int n;
        scanf("%d", &n);
        vector<string> a, b;

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            a.push_back(s);
            
            s.resize(unique(s.begin(), s.end()) - s.begin());
            b.push_back(s);
        }

        bool cool = true;
        for (int i = 0; i < n; ++i) {
            if (b[i] != b[0]) {
                cool = false;
                break;
            }
        }
        if (!cool) {
            cout << "Fegla Won" << endl;
            continue;
        }

        int m = b[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            char c = b[0][ b[0].size() - 1 ];
            b[0].resize(b[0].size() - 1);

            vector<int> A;
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                while (a[j].size() > 0 && a[j][ a[j].size() - 1 ] == c) {
                    ++cnt;
                    a[j].resize(a[j].size() - 1);
                }
                A.push_back(cnt);
            }

            int best = 1e9;
            for (int cur = 1; cur <= 100; ++cur) {
                int cand = 0;
                for (int j = 0; j < n; ++j)
                    cand += myabs(cur - A[j]);
                best = min(best, cand);
            }
            
            ans += best;
        }

        cout << ans << endl;
        
        //cerr << "Test " << _t << " completed. Consumed time " << double(clock()) / CLOCKS_PER_SEC << endl;
    }


    
    return 0;
}
