#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 3) {
        printf("USAGE:\n\t%s in out\n", argv[0]);
        return -1;
    }
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Failed to open in file %s\n", argv[1]);
        return -1;
    }

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Failed to open out file %s\n", argv[2]);
        fclose(fin);
        return -1;
    }
    int T;
    fscanf(fin, "%d", &T);
    int i;
    for (i = 0; i < T; ++i) {
        int N;
        fscanf(fin, "%d", &N);
        int v[N];
        int j;
        int sum = 0;
        for (j = 0; j < N; ++j) {
            fscanf(fin, "%d", &v[j]);
            sum += v[j];
        }
        fprintf(fout, "Case #%d: ", i+1);
        while (sum) {
            int max = 0;
            int maxj = -1;
            for (j = 0; j < N; ++j) {
                if (v[j] > max) {
                    max = v[j];
                    maxj = j;
                }
            }
            int max2 = 0;
            int max2j = -1;
            for (j = 0; j < N; ++j) {
                if (j == maxj)
                    continue;
                if (v[j] > max2) {
                    max2 = v[j];
                    max2j = j;
                }
            }
            if (max == max2 && (max != 1 || sum != 3)) {
                v[maxj]--;
                v[max2j]--;
                sum -= 2;
                fprintf(fout, "%c%c ", 'A' + maxj, 'A' + max2j);
                continue;
            }
            //try remove 2 max
            if (max != 1) {
                int bad = 0;
                for (j = 0; j < N; ++j) {
                    if (j == maxj)
                        continue;
                    if (v[j] > (sum - 2)/2) {
                        bad = 1;
                        break;
                    }
                }
                if (!bad) {
                    v[maxj] -= 2;
                    sum -= 2;
                    fprintf(fout, "%c%c ", 'A' + maxj, 'A' + maxj);
                    continue;
                }
            }
            //remove 1 max
            v[maxj] --;
            sum--;
            fprintf(fout, "%c ", 'A' + maxj);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
    fclose(fin);
    return 0;
}
