#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int slen[200];
char str[200][200];
char l[200][200];
int lc[200][200];
int lcnt[200];

void an(int s) {
    int i;

    for (i=1; i<=slen[s]; ++i) {
        if (str[s][i] != str[s][i-1]) {
            lc[s][lcnt[s]] = 1;
            l[s][lcnt[s]++] = str[s][i];
        }
        else {
            lc[s][lcnt[s]-1]++;
        }
    }
}
int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, T, i, N, ans = 0, w, j, x, r, cur;

    scanf("%d\n", &T);

    for (t=1; t<=T; ++t) {
        printf("Case #%d: ", t);
        scanf("%d\n", &N);

        memset(lcnt, 0, sizeof(lcnt));
        memset(lc, 0, sizeof(lc));
        w = 0;

        for (i=1; i<=N; ++i) {
            scanf("%s", &str[i][1]);
            slen[i] = strlen(&str[i][1]);
            an(i);
        }
        for (i=2; i<=N; ++i) {
            if ( lcnt[1] != lcnt[i] ) {
                w = 1;
                goto end;
            }
            for (j=0; j<lcnt[1]; ++j) {
                if ( l[1][j] != l[i][j] ) { w = 1; goto end; }
            }
        }
        ans = 0;
        for (i=0; i<lcnt[1]; ++i) {
            x = 0x3f3f3f3f;
            for (r=1; r<=100; ++r) {
                cur = 0;
                for (j=1; j<=N; ++j) {
                    cur += abs(r-lc[j][i]);
                }
                if ( x > cur ) x = cur;
            }
            ans += x;
        }
end:
        if ( w == 1 ) {
            printf("Fegla Won\n");
        }
        else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
