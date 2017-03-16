#include <cstdio>
#include <algorithm>

using namespace std;

int bitcount(int n) {
    int bit = 0;
    while (n > 0) {
        if (n & 1) bit++;
        n >>= 1;
    }
    return bit;
}

int calc(int rows, int cols, int n) {
    const int N = 16;
    int k = rows * cols;
    int ans = 1000000;
    for (int i = 0; i < (1<<k); i++) {
        if (n == bitcount(i)) {
            bool g[N][N] = {};

            for (int j = 0; j < k; j++) {
                if (i & (1<<j)) {
                    int r = j / cols;
                    int c = j % cols;
                    g[r][c] = true;
                }
            }

            int sep = 0;
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    if (!g[r][c]) continue;

                    if (r > 0 && g[r-1][c]) sep++;
                    if (c > 0 && g[r][c-1]) sep++;
                }
            }

            ans = min(ans, sep);
        }
    }
    return ans;
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    for (int cc = 0; cc < ncases; cc++) {
        int rows, cols, n;
        scanf("%d %d %d", &rows, &cols, &n);

        printf("Case #%d: %d\n", cc+1, calc(rows, cols, n));
    }
}

