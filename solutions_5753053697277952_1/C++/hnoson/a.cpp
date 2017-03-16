#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define RREP(i,s,e) for (i = s; i >= e; i--)
#define rrep(i,n) RREP(i,(int)(n)-1,0)
#define REP(i,s,e) for (i = s; i <= e; i++)
#define rep(i,n) REP(i,0,(int)(n)-1)
#define INF 100000000

typedef long long ll;

int p[26];

void solve(int test) {
    int i, n;
    cin >> n;
    rep (i,n) cin >> p[i];
    cout << "Case #" << test << ": ";
    while (true) {
        int mx = 0;
        int imx = 0;
        rep (i,26) {
            if (mx < p[i]) {
                mx = p[i];
                imx = i;
            }
        }
        if (mx == 0)
            break;
        cout << (char)(imx+'A');
        p[imx]--;
        mx = 0;
        imx = 0;
        int sum = 0;
        rep (i,26) {
            if (mx < p[i]) {
                mx = p[i];
                imx = i;
            }
            sum += p[i];
        }
        if (sum != 2) {
            cout << (char)(imx+'A');
            p[imx]--;
        }
        cout << " ";
    }
    cout << endl;
}

int main() {
    int i, t;
    cin >> t;
    rep (i,t) solve(i+1);
    return 0;
}
