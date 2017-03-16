#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

    ////////////////////////////////////////////////////////////////////////////////
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

bool check(vector<int> &p) {
    int m = -1e9;
    int s = 0;
    for (int i = 0; i < p.size(); ++i) {
        s += p[i];
        if (p[i] > m) {
            m = p[i];

        }
    }
    if (m * 2 > s) {
        return 1;
    }
    return 0;
}

int main(){
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int l = 0; l < t; ++l) {
        cout << "Case #" << l+1 <<": ";
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }


        while (1){
            int m = -1e9, m1 = -1, m2 = -1, c = 0;
            for (int i = 0; i < n; ++i) {
                if (p[i] > m) {
                    m = p[i];
                    m1 = i;
                    c = 0;
                    continue;
                }
                if (p[i] == m) {
                    m2 = i;
                    c += 1;
                    continue;
                }
            }
            if (m == 0) {
                break;
            }
            cout << (char)('A' + (char) m1);
            p[m1]--;
            if (m2 != -1 and c == 1) {
                cout << (char) ('A' + (char) m2);
                p[m2]--;
            }
            cout << ' ';
            if (check(p)) {
                cerr << l+1 << endl;
            }
        }










        cout << '\n';
    }
}