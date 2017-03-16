#include <cstdio>
#include <cstdlib>

int T, Test;
int n, m[1010];

int main() {
    scanf("%d", &Test);
    for (int T = 1; T <= Test; ++T) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", m + i);
        printf("Case #%d:", T);
        int ans = 0, speed = 0;
        for (int i = 1; i < n; ++i)
            if (m[i] < m[i - 1]) {
                ans += m[i - 1] - m[i];
                if (m[i - 1] - m[i] > speed)
                    speed = m[i - 1] - m[i];
            }
        printf(" %d", ans);
        ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (m[i] >= speed) ans += speed;
            else ans += m[i];
        }
        printf(" %d\n", ans);
    }
}
