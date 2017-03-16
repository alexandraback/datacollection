#include <assert.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned int UINT;
typedef long long unsigned int ULL;
typedef long long int LL;

const int MAXN = 20;
const int MOD = 1000000007;

UINT count_bits (unsigned int v)
{
    unsigned int c; // store the total here
    static const int S[] = {1, 2, 4, 8, 16}; // Magic Binary Numbers
    static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};

    c = v - ((v >> 1) & B[0]);
    c = ((c >> S[1]) & B[1]) + (c & B[1]);
    c = ((c >> S[2]) + c) & B[2];
    c = ((c >> S[3]) + c) & B[3];
    c = ((c >> S[4]) + c) & B[4];
    return c;
}

ULL get_min(int R, int C, int N)
{
    UINT mask = 0;
    UINT max_mask = 1 << R*C;
    for (int i = 0; i < N; i++) {
        mask = mask << 1 | (UINT) 1;
    }
    ULL minc = (R+1)*(C+1);
    char grid[MAXN][MAXN];
    while (mask < max_mask) {
        if (count_bits(mask) != N) {
            mask++;
            continue;
        }
        UINT aux = mask;
        memset(grid, 0, sizeof grid);
        ULL count = 0;
        //printf("mask %d\n", mask);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                aux <<= 1;
                UINT bit = aux & max_mask;
                if (!bit) continue;
                //printf("%d, %d\n", i, j);
                grid[i][j] = 1;
                if (j - 1 >= 0 && grid[i][j-1] == 1) {
                    //printf("+ %d, %d\n", i, j-1);
                    count++;
                }
                if (i - 1 >= 0 && grid[i-1][j] == 1) {
                    //printf("+ %d, %d\n", i-1, j);
                    count++;
                }
            }
        }
        minc = min(minc, count);
        mask++;
    }
    return minc;
}

int main ()
{
    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        int R, C, N;
        scanf("%d %d %d", &R, &C, &N);
        ULL sol = get_min(R, C, N);
        printf("Case #%d: %llu\n", tt, sol);
    }
    return 0;
}
