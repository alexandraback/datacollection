#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;


typedef long long LL;


int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    LL t;
    cin >> t;
    for (LL q = 1; q <= t; ++q) {
        LL n;
        cin >> n;
        vector < LL > m (n);
        LL md = 0;
        for (LL i = 0; i < n; ++i) {
            cin >> m[i];
            if (i > 0) {
                md = max(md, m[i - 1] - m[i]);
            }
        }

        LL a1 = 0, a2 = 0;
        for (LL i = 0; i < n - 1; ++i) {
            a1 += max(0ll, m[i] - m[i + 1]);
            a2 += min(md, m[i]);
            
        }    
        cout << "Case #" << q <<": " << a1 << " " << a2 << endl;
    }
    return 0;
}