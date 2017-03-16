#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define EPS 1e-10
typedef long long LL;

void run() {
    int n;
    cin >> n;
    vector<int> mm(n);
    REP(i, n) cin >> mm[i];

    int res1 = 0;
    FOR(i, 1, n - 1) res1 += max(0, mm[i - 1] - mm[i]);

    int res2 = 0, mi = 0;
    FOR(i, 1, n - 1) mi = max(mi, mm[i - 1] - mm[i]);
    FOR(i, 1, n - 1) res2 += min(mm[i - 1], mi);
    //int res2 = 0;
    //double mi = 0;
    //FOR(i, 1, n - 1) mi = max(mi, (mm[i - 1] - mm[i]) / 10.0);
    //FOR(i, 1, n - 1) res2 += min(mm[i - 1] + 0.0, mi * 10 + EPS);

    cout << res1 << " " << res2 << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
