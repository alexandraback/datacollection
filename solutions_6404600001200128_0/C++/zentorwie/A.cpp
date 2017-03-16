#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[1010];
int n;


bool test(int x) {
    int cur = a[1];
    for (int i = 2; i <= n; i++) {
        cur -= x;
        if (cur > a[i]) return false;
        cur = max(cur, a[i]);
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        ll ans1 = 0;
        for (int i = 2; i <= n; i++) {
            ans1 += max(0, a[i-1] - a[i]);
        }
        ll ans2 = 0;
        int L = -1, R = 10000000;
        while (R - L > 1) {
            int mid = L + (R - L) / 2;
            if (test(mid)) {
                R = mid;
            }
            else L = mid;
        }

        for (int i = 1; i < n; i++) {
            int d = min(a[i], R);
            ans2 += d;
        }

        printf("Case #%d: %lld %lld\n", kase, ans1, ans2);
        
        
    }
    
    return 0;
}
