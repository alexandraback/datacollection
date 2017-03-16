#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;
FILE* in; FILE* out;

const int MAX = 16;
const int MM = 16;
const int MASK = 65536;
//const int MAX = 104;
//const int MM = 10004;
const int INF = 1000000001;

int n, m, k;
int cnt[MASK];
int dyn[MAX][MM][MASK];

int recurse(int row, int rem, int mask) {
    if (rem == 0)
        return 0;
    if (row >= n)
        return INF;
    if (dyn[row][rem][mask] != -1)
        return dyn[row][rem][mask];
    
    int ans = INF;
    for (int nmask = 0; nmask < (1 << m); nmask++) {
        int cur = cnt[nmask];
        cur += __builtin_popcount(mask & nmask);
        cur += recurse(row + 1, rem - __builtin_popcount(nmask), nmask);
        ans = min(ans, cur);
    }
    return dyn[row][rem][mask] = ans;
}

/*
int eval() {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
        }
    }
}
*/

void solveTest() {
    fscanf(in, "%d %d %d", &n, &m, &k);
    if (m < n)
        swap(n, m);
    
    for (int mask = 0; mask < MASK; mask++) {
        cnt[mask] = 0;
        for (int i = 1; i < m; i++)
            if ((mask & (1 << i)) && (mask & (1 << (i - 1))))
                cnt[mask]++;
    }
    
    memset(dyn, -1, sizeof(dyn));
    fprintf(out, "%d\n", recurse(0, k, 0));
//    fprintf(out, "%d\n", eval());
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("NoisyNeighbors.in", "rt");
	out = fopen("NoisyNeighbors.out", "wt");
	
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 1; test <= numTests; test++) {
		fprintf(stderr, "Currently executing testcase %d...\n", test);
		fprintf(out, "Case #%d: ", test);
		solveTest();
	}
	
	fprintf(stderr, "Total execution time %.3lf seconds.\n",
        (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	return 0;
}
