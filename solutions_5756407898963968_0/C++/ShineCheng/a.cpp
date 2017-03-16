//http://code.google.com/codejam/contest/2974486/dashboard

#include <cstdio>
#include <cstring>

int maybe[20];

int main() {
    int t;
    scanf("%d", &t);
    int cas = 1;
    while (t--) {
        printf("Case #%d: ", cas++);
        memset(maybe, 0, sizeof(maybe));
        int row;
        scanf("%d",&row);
        for (int i = 1; i <= 4; i++) {
            int a[5];
            for (int j = 1; j <= 4; j++) {
                scanf("%d", &a[j]);
            }
            if (i == row) {
                for (int j = 1; j <= 4; j++) {
                    maybe[a[j]] = true;
                }
            }
        }

        int maynum = 0;
        int ans = -1;
        scanf("%d", &row);
        for (int i = 1; i <= 4; i++) {
            int a[5];
            for (int j = 1; j <= 4; j++) {
                scanf("%d", &a[j]);
            }
            if (i == row) {
                for (int j = 1; j <= 4; j++) {
                    if (maybe[a[j]]) {
                        ans = a[j];
                        maynum++;
                    }
                }
            }
        }
        if (maynum == 0) puts("Volunteer cheated!");
        else if (maynum > 1) puts("Bad magician!");
        else if (maynum == 1) {
            printf("%d\n", ans);
        }
    }
    return 0;
}
