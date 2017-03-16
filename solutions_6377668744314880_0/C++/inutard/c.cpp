#include <bits/stdtr1c++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> pt;

int ans[3005];
pt p[3005];

ll cp(const pt &a, const pt &b) { return imag(conj(a)*b); }

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            p[i] = pt(x,y);
        }
        
        memset(ans, 0x3f, sizeof ans);
        if (n == 1) ans[0] = 0;
        cout << "Case #" << ca << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int tres = 0;
                for (int k = 0; k < n; k++) {
                    if (cp(p[j]-p[i], p[k]-p[i]) > 0) {
                        tres++;
                    }
                }
                ans[i] = min(ans[i], tres);
            }
            cout << ans[i] << '\n';
        }
        
    }
	return 0;
}