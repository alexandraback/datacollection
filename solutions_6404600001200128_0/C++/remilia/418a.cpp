#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int t, n, m[N];

bool judge(int v) {
    int u = 0;
    for (int i = 0; i < n; i++) {
        if (u > m[i]) return false;
        u = m[i];
        u = max(0, u - v);
    }
    return true;
}

int main() {
    int cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &m[i]);
        int ans1 = 0, ans2 = 0, u = 0;
        for (int i = 0; i < n; i++) {
            if (u > m[i])
                ans1 += u - m[i];
            u = m[i];
        }
        int l = 0, r = 10001;
        while (l < r) {
            int mid = (l + r) / 2;
            if (judge(mid)) r = mid;
            else l = mid + 1;
        }
        for (int i = 0; i < n - 1; i++)
            ans2 += min(m[i], l);
        printf("Case #%d: %d %d\n", ++cas, ans1, ans2);
    }
    return 0;
}
