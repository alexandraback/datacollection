#include <bits/stdc++.h>

int main() {
    int ct;
    scanf("%d", &ct);
    for (int nt = 1; nt <= ct; nt++) {
        int n, m, tong;
        scanf("%d%d%d", &n, &m, &tong);
        // TH1
        int cnt[5];
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = cnt[4] = 0;
        if (n == 1) {
            if (m == 1) {
                printf("Case #%d: 0\n", nt);
                continue;
            }
            cnt[0] = (m+1)/2;
            if (m%2 == 0) cnt[1] = 1;
            cnt[2] = (m+1)/2-1;
        }
        else if (m == 1) {
            cnt[0] = (n+1)/2;
            if (n%2 == 0) cnt[1] = 1;
            cnt[2] = (n+1)/2-1;
        }
        else {
            cnt[0] = (n/2)*m;
            cnt[1] = 0;
            if (n&1) cnt[0] += (m+1)/2;
            cnt[2] = 0, cnt[3] = 0;
            if (m&1) cnt[2] += 0;
            else cnt[2] += 1;
            if (n&1) cnt[2] *= 2;
            else {
                if (m&1) cnt[2] += 2;
                else cnt[2] += 1;
            }
            if (m&1) cnt[3] += m/2;
            else cnt[3] += m/2-1;
            if (n&1) cnt[3] *= 2;
            else {
                cnt[3] += m/2-1;
            }
            cnt[3] += (n-1)/2;
            if (m&1) cnt[3] += (n-1)/2;
            else cnt[3] += (n-2)/2;
            cnt[4] = n*m-cnt[0]-cnt[2]-cnt[3];
        }
        int res = 0, tmp = tong;
        for (int i = 0; i < 5; i++) {
            if (tmp <= cnt[i]) {
                res += tmp*i;
                tmp = 0;
            }
            else {
                res += cnt[i]*i;
                tmp -= cnt[i];
            }
        }
        //for (int i = 0; i < 5; i++) printf("i = %d: %d\n", i, cnt[i]);
        // TH2
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = cnt[4] = 0;
        if (n == 1) {
            cnt[0] = m/2;
            if (m%2 == 0) cnt[1] = 1;
            else cnt[1] = 2;
            cnt[2] = m/2-1;
        }
        else if (m == 1) {
            cnt[0] = n/2;
            if (n%2 == 0) cnt[1] = 1;
            else cnt[1] = 2;
            cnt[2] = n/2-1;
        }
        else {
            cnt[0] = (n/2)*m;
            cnt[1] = 0;
            if (n&1) cnt[0] += m/2;
            cnt[2] = 0;
            cnt[3] = 0;
            if (m&1) cnt[2] += 2;
            else cnt[2] += 1;
            if (n&1) cnt[2] *= 2;
            else {
                if (m&1) cnt[2] += 0;
                else cnt[2] += 1;
            }
            cnt[3] += m/2-1;
            if (n&1) cnt[3] *= 2;
            else {
                if (m&1) cnt[3] += m/2;
                else cnt[3] += m/2-1;
            }
            cnt[3] += (n-2)/2;
            if (m&1) cnt[3] += (n-2)/2;
            else cnt[3] += (n-1)/2;
            cnt[4] = n*m-cnt[0]-cnt[2]-cnt[3];
        }
        int res2 = 0;
        tmp = tong;
        for (int i = 0; i < 5; i++) {
            if (tmp <= cnt[i]) {
                res2 += tmp*i;
                tmp = 0;
            }
            else {
                res2 += cnt[i]*i;
                tmp -= cnt[i];
            }
        }
        if (res > res2) res = res2;
        //for (int i = 0; i < 5; i++) printf("i = %d: %d\n", i, cnt[i]);
        printf("Case #%d: %d\n", nt, res);
    }
    return 0;
}
