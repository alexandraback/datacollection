#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

int num[26];

void run() {
    int n, tot = 0;
    cin >> n;
    REP(i, n) {
        cin >> num[i];
        tot += num[i];
    }
    while (tot > 0) {
        cout << " ";
        int m = (tot - 1) / 2 + 1, cnt = 0;
        REP(i, n) {
            if (num[i] >= m) {
                cout << (char)('A' + i);
                --tot;
                --num[i];
                ++cnt;
                if (cnt >= 2) {
                    break;
                }
            }
        }
        if (cnt == 0) {
            int idx = -1;
            REP(i, n) {
                if (num[i] == 0) continue;
                if (idx == -1 || num[i] > num[idx]) idx = i;
            }
            cout << (char)('A' + idx);
            --tot;
            --num[idx];
        }
    }

    cout << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ":";
        run();
    }
    return 0;
}
