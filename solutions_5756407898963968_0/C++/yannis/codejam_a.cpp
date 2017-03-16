#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt[30];

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, T, t, i, j, x, a, ans;

    scanf("%d", &T);
    for (t=1; t<=T; ++t) {
        memset(cnt, 0, sizeof(cnt));

        scanf("%d", &a);

        for (i=1; i<=4; ++i) {
            for (j=1; j<=4; ++j) {
                scanf("%d", &x);
                if ( i == a ) cnt[x]++;
            }
        }

        scanf("%d", &a);

        for (i=1; i<=4; ++i) {
            for (j=1; j<=4; ++j) {
                scanf("%d", &x);
                if ( i == a ) cnt[x]++;
            }
        }

        ans = -1;
        for (i=1; i<=16; ++i) {
            if ( cnt[i] == 2 ) {
                if ( ans == -1 ) ans = i;
                else ans = -2;
            }
        }

        if ( ans == -1 ) {
            printf("Case #%d: Volunteer cheated!\n", t);
        }
        else if ( ans == -2 ) {
            printf("Case #%d: Bad magician!\n", t);
        }
        else {
            printf("Case #%d: %d\n", t, ans);
        }
    }

    return 0;
}
