#include <cstdio>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
using namespace std;

int rows, cols, n;

bool bit(int mask, int r, int c) {
    return (1 << ((r * cols) + c)) & mask;
}

int solve() {
    int best = 1e7;
    for (int mask = 0; mask < (1 << (rows * cols)); mask++) {
        int bits = 0;
        for (int tmp = mask; tmp; tmp /= 2)
            bits += tmp & 1;
        if (bits == n) {
            int unhappy = 0;
            for (int r = 0; r < rows; r++)
                for (int c = 0; c < cols; c++)
                    if (bit(mask, r, c)) {
                        if (r + 1 < rows and bit(mask, r + 1, c))
                            unhappy++;
                        if (c + 1 < cols and bit(mask, r, c + 1))
                            unhappy++;
                    }
            best = min(best, unhappy);
        }
    }
    assert(best < 1e7);
    return best;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        scanf("%d%d%d", &rows, &cols, &n);
        printf("Case #%d: %d\n", cs, solve());
    }
}
