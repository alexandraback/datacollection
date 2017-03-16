#include <cstdio>

int b, n;
int a[1010];

long long test(long long sec) {
    long long tot = 0;
    for (int i = 0; i < b; i++) {
        tot += sec / a[i] + 1;
    }
    return tot;
}

int Solve(long long sec) {
    int cnt = 0;
    for (int i = 0; i < b; i++) {
        n -= (sec / a[i]);
        if (sec % a[i] == 0) cnt++;
        else n--;
    }
    for (int i = 0; i < b; i++)
        if (sec % a[i] == 0) {
            n--;
            cnt--;
            if (n == 0) return i;
        }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d", &b, &n);
        for (int i = 0; i < b; i++)
            scanf("%d", &a[i]);
        long long left = 0, right = n * 100000LL;
        int ans;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (test(mid) >= n) right = mid - 1;
            else left = mid + 1;
        }
        ans = Solve(left);
        //printf("sec = %d\n", left);
        printf("Case #%d: %d\n", cas, ans + 1);
    }
    return 0;
}
