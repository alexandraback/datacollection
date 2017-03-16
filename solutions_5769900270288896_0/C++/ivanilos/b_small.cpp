#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;

int mask[16];
int big;
int res;
int r, c, n;

int calc(void) {
    int aux = 0;
    int count = 0;
    int b1, b2;

    count = __builtin_popcount(mask[0]);
    for (int i = 1; i < r; i++) {
        count += __builtin_popcount(mask[i]);
        aux += __builtin_popcount(mask[i - 1] & mask[i]);
    }
    //printf("here aux = %d, count = %d\n", aux, count);
    if (count != n) {
        return INF;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            b1 = (mask[i] >> (j - 1)) & 1;
            b2 = (mask[i] >> j) & 1;
            aux += (b1 & b2);
        }
    }
    //printf("aux = %d\n", aux);
    return aux;
}

void solve(int row) {
    if (row == r) {
        res = min(res, calc());
        return;
    }

    for (int i = 0; i < 1 << c; i++) {
        mask[row] = i;
        solve(row + 1);
    }
    return;
}

int main(void) {
    int t;

    scanf(" %d", &t);

    for (int caso = 1; caso <= t; caso++) {
        res = INF;
        scanf(" %d %d %d", &r, &c, &n);
        solve(0);

        printf("Case #%d: %d\n", caso, res);
    }
    return 0;
}


