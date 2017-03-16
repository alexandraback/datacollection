#include <bits/stdtr1c++.h>

using namespace std;

typedef long long ll;

ll a[1005], b, n;
ll f(ll m) {
    ll res = 0;
    for (int i = 0; i < b; i++) {
        res += 1+m/a[i];
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        cin >> b >> n;
        for (int i = 0; i < b; i++) {
            cin >> a[i];
        }
        
        ll l = 0, r = 100000000000000000;
        while (r-l > 1) {
            ll m = (l+r)/2;
            if (f(m) >= n) {
                r = m-1;
            } else {
                l = m;
            }
        }
        if (f(r) >= n) r--;
        
        n -= f(r);
        r++;
        int ans = -1;
        for (int i = 0; i < b; i++) {
            if (r%a[i] == 0) {
                n--;
                if (n == 0) {
                    ans = i;
                    break;
                }
            }
        }
        cout << "Case #" << ca << ": " << ans+1 << endl;
    }
	return 0;
}