#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long I64;
typedef unsigned long long U64;

#define MAXN    26

int gN;
int gP[MAXN];
int gCnt;

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "rt");
    FILE* fout = fopen(argv[2], "wt");

    int T;

    fscanf(fin, "%d", &T);
    for (int tn = 1; tn <= T; tn++) {
        fscanf(fin, "%d", &gN);
        gCnt = 0;
        for (int i = 0; i < gN; i++) {
            fscanf(fin, "%d", &gP[i]);
            gCnt += gP[i];
        }

        fprintf(fout, "Case #%d:", tn);
        while (gCnt > 2) {
            int a = max_element(gP, gP + gN) - gP;
            gP[a]--;
            if (--gCnt == 2) {
                fprintf(fout, " %c", a + 'A');
                break;
            }
            int b = max_element(gP, gP + gN) - gP;
            gP[b]--;
            --gCnt;
            fprintf(fout, " %c%c", a + 'A', b + 'A');
        }
        if (gCnt == 1) {
            int a = max_element(gP, gP + gN) - gP;
            fprintf(fout, " %c", a + 'A');
        } else if (gCnt == 2) {
            int a = max_element(gP, gP + gN) - gP;
            gP[a]--;
            int b = max_element(gP, gP + gN) - gP;
            fprintf(fout, " %c%c", a + 'A', b + 'A');
        }
        fprintf(fout, "\n");
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
