#include <bits/stdtr1c++.h>

using namespace std;

int a[1005];
int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int ans0 = 0, ans1 = 1000000000;
        // first method:
        for (int i = 0; i < n-1; i++) {
            ans0 += max(0, a[i]-a[i+1]);
        }
        
        // second method:
        for (int r = 0; r <= 10000; r++) {
            int tans = 0, valid = 1;
            for (int i = 1; i < n; i++) {
                tans += min(a[i-1], r);
                if (a[i-1]-r > a[i]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) ans1 = min(ans1, tans);
        }
        
        cout << "Case #" << ca << ": " << ans0 << " " << ans1 << endl;
    }
	return 0;
}