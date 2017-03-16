// Just remember the first selected row and try to match it with the second one
// https://code.google.com/codejam/contest/2974486/dashboard#s=p0
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define NO_RESULT 0
#define MORE_RESULTS -1

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int c=1;c<=cases;c++) {
        int ans1;
        int row1[4];
        scanf("%d", &ans1);
        ans1--;

        int temp;
        FOR(i, 4) FOR(j, 4) scanf("%d", i == ans1 ? &row1[j] : &temp);

        int ans2;
        scanf("%d", &ans2);
        ans2--;

        int result = NO_RESULT;
        FOR(i, 4) FOR(j, 4) {
            scanf("%d", &temp);
            if (i == ans2) {
                FOR(k, 4) {
                    if (row1[k] == temp) {
                        if (result != MORE_RESULTS) result = result == NO_RESULT ? temp : MORE_RESULTS;
                    }
                }
            }
        }
        printf("Case #%d: ", c);
        switch (result) {
            case NO_RESULT:
                printf("Volunteer cheated!\n");
                break;
            case MORE_RESULTS:
                printf("Bad magician!\n");
                break;
            default:
                printf("%d\n", result);
                break;
        }
    }
}
