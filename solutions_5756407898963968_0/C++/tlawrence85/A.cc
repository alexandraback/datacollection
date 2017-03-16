#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int nC;
    scanf("%d", &nC);

    for (int cC = 0; cC < nC; ++cC) {
        int count[16];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < 2; ++i) {
            int ans;
            scanf("%d", &ans);

            --ans;
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int num;
                    scanf("%d", &num);

                    --num;
                    if (j == ans)
                        count[num]++;
                }
            }
        }

        int solution;
        int numSols = 0;
        for (int i = 0; i < 16; ++i) {
            if (count[i] == 2) {
                ++numSols;
                solution = i + 1;
            }
        }

        printf("Case #%d: ", cC + 1);
        if (numSols == 0) {
            printf("Volunteer cheated!\n");
        } else if (numSols > 1) {
            printf("Bad magician!\n");
        } else {
            printf("%d\n", solution);
        }
    }
}
