#include <bits/stdtr1c++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef complex<ll> pt;

int ans[3005];
pt p[3005], q[3005];

ll cp(const pt &a, const pt &b) { return imag(conj(a)*b); }
ll dp(const pt &a, const pt &b) { return real(conj(a)*b); }

pt c;
bool arg_cmp(pt a, pt b) {
    pt p = a-c, q = b-c;
    ld arg0 = atan2(ld(p.imag()), ld(p.real()));
    ld arg1 = atan2(ld(q.imag()), ld(q.real()));
    if (arg0 == arg1) return norm(p) < norm(q);
    return arg0 < arg1;
}

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
                q[j] = p[j];
            }
            
            c = p[i];
            int m = n-1;
            swap(q[i], q[m]);
            sort(q, q+m, arg_cmp);
            
            int tres = 0, j = 0, k = 1;
            while (j < m) {
                while (cp(q[j]-c, q[k]-c) == 0 && dp(q[j]-c, q[k]-c) > 0) {
                    k = (k+1)%m;
                    if (j == k) break;
                }
                
                while (cp(q[j]-c, q[j+1]-c) == 0 && dp(q[j]-c, q[j+1]-c) > 0) {
                    j++;
                    if (j == k) k = (k+1)%m;
                    tres = max(0, tres-1);
                }
                
                while (cp(q[j]-c, q[k]-c) > 0) {
                    tres++;
                    k = (k+1)%m;
                }
                
                ans[i] = min(ans[i], tres);
                if (cp(q[j]-c, q[j+1]-c) > 0) tres--;
                j++;
            }
            cout << ans[i] << '\n';
        }
        
    }
	return 0;
}