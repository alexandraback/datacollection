/* 
 
Google Code Jam Round 1A
April 17, 2015

Jesse Pritchard
Public contact: chaserdevelopment@gmail.com
 
Problem A

*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int compare(const void* a, const void* b) {
    const long* al = a, *bl = b;
    if (*al < *bl) {
        return -1;
    }
    if (*bl < *al) {
        return 1;
    }
    else return 0;
}

long lcm(long* v, long num) {
    int jjj;
    long min = v[0];
    for (jjj = 0; jjj < num; jjj++) {
        if (v[jjj] < min) {
            min = v[jjj];
        }
    }
    long max = min;
    for (jjj = 1; 1; jjj++) {
        int iii, good = 1;
        for (iii = 0; iii < num; iii++) {
            if (max % v[iii] != 0) {
                good = 0;
            }
        }
        if (good) {
            break;
        }
        max = min * jjj;
    }
    return max;
}

int main() {
    int num, iii;
    scanf(" %d", &num);
    for (iii = 0; iii < num; iii++) {
        
        long N, B;
        scanf(" %ld %ld", &B, &N);
        long M[B], C[B], jjj;
        for (jjj = 0; jjj < B; jjj++) {
            scanf(" %ld", &M[jjj]);
            C[jjj] = M[jjj];
        }
        
        long least = lcm(M, B);
        long mod = 0;
        for (jjj = 0; jjj < B; jjj++) {
            mod += least / M[jjj];
        }
        N %= mod;
        int kkk = 0;
        long needed = N - B;
        while (needed <= 0) {
            needed += mod;
        }
        for (jjj = 1; 1; jjj++) {
            for (kkk = 0; kkk < B; kkk++) {
                if (M[kkk] == jjj) {
                    M[kkk] += C[kkk];
                    if (needed == 1) {
                        goto done;
                    }
                    needed--;
                }
            }
        }
    done:
        
        printf("Case #%d: %d\n", iii + 1, kkk + 1);
    }
    return 0;
}
