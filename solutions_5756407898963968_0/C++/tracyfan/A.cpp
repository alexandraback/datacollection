#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    freopen("a-sm.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int f[17];
        memset(f, 0, sizeof(f));
        for (int k = 1; k <= 2; k++) {
            int ans1;
            scanf("%d",&ans1);
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <= 4; j++) {
                    int x;
                    scanf("%d", &x);
                    if (i == ans1) {
                        f[x]++;
                    }
                }
            }
        }
        int cnt = 0, single = 0;
        for (int i = 1; i <= 16; i++) {
            if (f[i] == 2) {
                cnt++;
                single = i;
            }
        }
        printf("Case #%d: ", cas);
        if (cnt == 1) {
            printf("%d\n", single);
        } else if (cnt > 1) {
            printf("Bad magician!\n");
        } else {
            printf("Volunteer cheated!\n");
        }
    }
}
