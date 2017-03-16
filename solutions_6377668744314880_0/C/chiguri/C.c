#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int N;
int X[15];
int Y[15];
int min[15];

int main(void) {
    int dataset_num, case_num;
    int i, j, k;


    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        scanf("%d", &N);
        for(i = 0; i < N; ++i) {
            scanf("%d %d", X+i, Y+i);
            min[i] = 16;
        }

        for(i = 0; i < N; ++i) {
            for(j = 0; j < N; ++j) {
                int l, r;
                l = 0;
                r = 0;
                if(i == j) continue;
                if(X[i] == X[j]) {
                    for(k = 0; k < N; ++k) {
                        if(X[k] < X[i]) ++l;
                        else if(X[k] > X[i]) ++r;
                    }
                }
                else {
                    long long x, y, xd, yd;
                    for(k = 0; k < N; ++k) {
                        x = X[i] - X[j];
                        y = Y[i] - Y[j];
                        xd = X[i] - X[k];
                        yd = Y[i] - Y[k];
                        if(x * yd < y * xd) l++;
                        else if(x * yd > y * xd) r++;
                    }
                }
                if(min[i] > l) {
                    min[i] = l;
                    //printf("%d %d %d %d\n", i, j, l, r);
                }
                if(min[i] > r) {
                    min[i] = r;
                    //printf("%d %d %d %d\n", i, j, l, r);
                }
            }
        }
        printf("Case #%d:\n", case_num);
        for(i = 0; i < N; ++i) {
            printf("%d\n", min[i]);
        }
    }

    return 0;
}
