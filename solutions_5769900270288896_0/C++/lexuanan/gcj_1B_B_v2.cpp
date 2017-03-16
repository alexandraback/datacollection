#include <bits/stdc++.h>

int x[20][20];

const int hi[] = {0, 0, 1, -1};
const int hj[] = {1, -1, 0, 0};

int res;

void duyet(int ii, int jj, int n, int m, int tong) {
    if (ii >= n) {
        if (tong > 0) return;
        int tmp = 0;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        if (x[i][j] == 1)
        for (int k = 0; k < 4; k++) {
            int ix = i+hi[k];
            int jx = j+hj[k];
            if (ix >= 0 && ix < n && jx >= 0 && jx < m && x[ix][jx] == 1) tmp++;
        }
        tmp /= 2;
        if (tmp < res) res = tmp;
        return;
    }
    if (tong > 0) {
        x[ii][jj] = 1;
        if (jj == m-1) duyet(ii+1, 0, n, m, tong-1);
        else duyet(ii, jj+1, n, m, tong-1);
    }
    x[ii][jj] = 0;
    if (jj == m-1) duyet(ii+1, 0, n, m, tong);
    else duyet(ii, jj+1, n, m, tong);
}

int main() {
    int ct;
    scanf("%d", &ct);
    for (int nt = 1; nt <= ct; nt++) {
        int n, m, tong;
        scanf("%d%d%d", &n, &m, &tong);
        res = 1000000;
        duyet(0, 0, n, m, tong);
        //for (int i = 0; i < 5; i++) printf("i = %d: %d\n", i, cnt[i]);
        printf("Case #%d: %d\n", nt, res);
    }
    return 0;
}
