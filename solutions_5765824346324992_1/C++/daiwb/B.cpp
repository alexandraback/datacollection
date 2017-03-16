#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define EPS 1e-10
typedef long long LL;

void run() {
    LL b, n;
    cin >> b >> n;
    vector<LL> m(b);
    REP(i, b) cin >> m[i];
    REP(can, b) {
        LL lt = 0, rt = n;
        while (lt <= rt) {
            LL mt = (lt + rt) / 2;
            LL tm = mt * m[can];
            LL tot = 0;
            LL idx, cnt = 0;
            REP(i, b) {
                tot += tm / m[i];
                if ((tm % m[i]) == 0) {
                    ++cnt;
                    if (i == can) idx = cnt;
                }
                else {
                    ++tot;
                }
            }
            idx += tot;
            if (idx == n) {
                cout << can + 1 << endl;
                return;
            }
            else if (idx < n) {
                lt = mt + 1;
            }
            else {
                rt = mt - 1;
            }
        }
    }
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
