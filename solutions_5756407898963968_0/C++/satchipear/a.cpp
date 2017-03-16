#include <stdio.h>
#include <string.h>

int main() {
    int tn;
    bool mark[18];
    scanf("%d", &tn);
    for (int cn = 1; cn <= tn; cn++) {
        memset(mark, false, sizeof(mark));
        int inRow;
        scanf("%d", &inRow);
        for (int r = 1; r <= 4; r++) {
            for (int c = 1; c <= 4; c++) {
                int x;
                scanf("%d", &x);
                if (r == inRow) {
                    mark[x] = true;
                }
            }
        }

        scanf("%d", &inRow);
        int matchCount = 0;
        int ans = -1;
        for (int r = 1; r <= 4; r++) {
            for (int c = 1; c <= 4; c++) {
                int x;
                scanf("%d", &x);
                if (r == inRow && mark[x]) {
                    matchCount++;
                    ans = x;
                }
            }
        }
        printf("Case #%d: ", cn);
        if (matchCount == 0) {
            printf("Volunteer cheated!\n");
        } else if (matchCount == 1) {
            printf("%d\n", ans);
        } else {
            printf("Bad magician!\n");
        }
    }
    return 0;
}
