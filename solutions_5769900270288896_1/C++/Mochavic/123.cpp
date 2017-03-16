#include <stdio.h>
#include <algorithm>
using namespace std;
int f(int n, int m, int k) {
    int ans = (n - 1) * m + (m - 1) * n;
    k = n * m - k;
    if (n == 1) {
        ans -= k * 2;
    } else {
        if (k <= ((n - 2) * (m - 2) + 1) / 2) {
            ans -= k * 4;
        } else {
            ans -= ((n - 2) * (m - 2) + 1) / 2 * 4;
            k -= ((n - 2) * (m - 2) + 1) / 2;
            int tot = (n * m + 1) / 2 - ((n - 2) * (m - 2) + 1) / 2;
            int cnt;
            if (n % 2 == 1 && m % 2 == 1) cnt = 4;
            else cnt = 2;
            if (k <= tot - cnt) {
                ans -= k * 3;
            } else {
                ans -= (tot - cnt) * 3;
                k -= (tot - cnt);
                ans -= k * 2;
            }
        }
    }
    return ans;
}
int g(int n, int m, int k) {
    int ans = (n - 1) * m + (m - 1) * n;
    k = n * m - k;
    if (n == 1) {
        ans -= k * 2;
    } else {
        if (n % 2 == 0 || m % 2 == 0) return n * m * 4;
        int tot = (n * m) / 2;
        if (k > tot) return n * m * 4;
        int cnt = n / 2 * 2 + m / 2 * 2;
        if (k <= tot - cnt) return ans - k * 4;
        else return ans - (tot - cnt) * 4 - (k - tot + cnt) * 3;
    }
    return ans;
}
int main(){
    int T, ri = 1, n, m, k;
    freopen("B-large (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &m, &k);
        printf("Case #%d: ", ri++);
        if ((n * m + 1) / 2 >= k) {
            printf("0\n");
            continue;
        }
        if (n > m) swap(n, m);
        printf("%d\n", min(f(n, m, k), g(n, m, k)));
    }
    return 0;
}
