#include <bits/stdc++.h>

using namespace std;

long long m[1005];
int b, n;

long long p(long long x) {
    long long ret = 0;
    for(int i = 0 ; i < b; i++) {
        ret += x/m[i] + 1;
    }
    //cout << x << ": " << ret << endl;
    return ret;
}

int main() {
    freopen("B-small-attempt0.in", "r" , stdin);
    freopen("B-small-attempt0.out", "w" , stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas ++) {
        cin >> b >> n;
        long long mx = -1;
        for(int i = 0 ; i < b ; i++) {
            cin >> m[i];
            mx = max(mx, m[i]);
        }

        long long l = 0;
        long long r = mx * n + 5;

        while(l < r) {
            long long mid = l + (r - l) / 2;
            if(p(mid) >= n) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        int ans = -1;
        long long k = p(l) - n;
        for(int i = b-1 ; i >= 0 ; i--) {
            if(l % m[i] == 0) {
                if(k == 0) {
                    ans = i+1;
                    break;
                } else {
                    k --;
                }
            }
        }
        
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}
