#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main () {
    freopen ("A-small-attempt0.out", "w", stdout);
    freopen ("A-small-attempt0.in", "r", stdin);
    int table1[4][4], table2[4][4];
	int T, nm= 1;
	int i, j, k;
	scanf("%d", &T);
    while (T--) {
        int ans1;
        scanf("%d", &ans1);
        ans1--;
        for (i=0;i<4;i++) {//row
            for (j=0;j<4;j++) {//column
                scanf("%d", &table1[i][j]);
            }
        }
        int ans2;
        scanf("%d", &ans2);
        ans2--;
        for (i=0;i<4;i++) {//row
            for (j=0;j<4;j++) {//column
                scanf("%d", &table2[i][j]);
            }
        }
        int tmp[17] = {0};
        for (i=0;i<4;i++) {
            tmp[table1[ans1][i]]= 1;
        }
        int ct= 0, ans;
        for (i=0;i<4;i++) {
            if (tmp[table2[ans2][i]] == 1) {
                ct++;
                ans= table2[ans2][i];
            }
        }

        if (ct == 1) printf("Case #%d: %d\n", nm++, ans);
        else if (ct > 1) printf("Case #%d: Bad magician!\n", nm++);
        else printf("Case #%d: Volunteer cheated!\n", nm++);
    }
    return 0;
}
