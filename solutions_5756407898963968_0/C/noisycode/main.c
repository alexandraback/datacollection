#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fin = fopen("magic.in", "r");
    FILE* fou = fopen("magic.txt", "w");
    int c, t;
    fscanf(fin, "%d\n", &t);
    for(c = 0; c < t; c++) {
        int i, j, ans, k, x;
        int a[4], candi[4];
        int an = 0;
        memset(candi, 0, sizeof(candi));
        for (k = 0; k < 2; k++) {
            fscanf(fin, "%d\n", &ans);
            for (i = 0; i < 4; i++) {
                if (i + 1 != ans)
                    fscanf(fin, "%d %d %d %d\n", &x, &x, &x, &x);
                else
                    for (j = 0; j < 4; j++) {
                        fscanf(fin, "%d", &x);
                        if (candi[j] == 0)
                            candi[j] = x;
                        else if (candi[0] == x || candi[1] == x || candi[2] == x || candi[3] == x)
                            a[an++] = x;
                    }
            }
        }
        fprintf(fou, "Case #%d: ", c + 1);
        if (an == 0)
            fprintf(fou, "Volunteer cheated!\n");
        else if (an > 1)
            fprintf(fou, "Bad magician!\n");
        else
            fprintf(fou, "%d\n", a[0]);
    }

    fclose(fou);
    fclose(fin);
    return 0;
}
