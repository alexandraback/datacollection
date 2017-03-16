// Just brute force solution
// https://code.google.com/codejam/contest/6224486/dashboard#s=p1
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_TOTAL_POS 20

int r, c, n;
int result;
int totalPos;

bool used[MAX_TOTAL_POS];

char cc = 0;
int getInt() {
    int r = 0;
    while (!(cc >= '0' && cc <= '9')) cc = getc_unlocked(stdin);
    while (cc >= '0' && cc <= '9') {
        r = r * 10 + (cc - '0');
        cc = getc_unlocked(stdin);
    }
    return r;
}


void test(int index, int first) {
    if (index < n) {
        FORE(i, first, totalPos - (n - 1 - index)) {
            used[i] = true;
            test(index + 1, i + 1);
            used[i] = false;
        }
    } else {
        int local = 0;
        FOR(i, r) FOR(j, c) if (used[i * c + j]) {
            if (i > 0 && used[i * c + j - c]) local++;
            if (j > 0 && used[i * c + j - 1]) local++;
        }
        if (local < result) result = local;

    }
}


int main(void) {
    int cases = getInt();
    for(int cc=1;cc<=cases;cc++) {
        r = getInt();
        c = getInt();
        n = getInt();
        totalPos = r * c;
        FOR(i, totalPos) used[i] = false;
        result = r * c * 10;
        test(0, 0);
        printf("Case #%d: %d\n", cc, result);
    }
}
