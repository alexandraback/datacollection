#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int getId(int x, int y, int r, int c) {
    return x * c + y;
}

int calcVal(int mask, int r, int c) {
    int val = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (!(mask & (1 << getId(i, j, r, c))))
                continue;
            int i1 = i + 1;
            int j1 = j + 1;
            if (i1 < r) {
                if (mask & (1 << getId(i1, j, r, c)))
                    val++;
            }
            if (j1 < c) {
                if (mask & (1 << getId(i, j1, r, c)))
                    val++;
            }
        }
    return val;
}

int getCntBit(int mask) {
    int ans = 0;
    while (mask)
        ans += mask & 1, mask >>= 1;
    return ans;
}

int solve(int r, int c, int n) {
    int bestAns = 1000000000;
    int len = r * c;
    for (int mask = 0; mask < (1 << len); mask++) {
        if (getCntBit(mask) != n) continue;
        bestAns = min(bestAns, calcVal(mask, r, c));
    }
    return bestAns;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    int i = 1;
    while (t--) {
        int r, c, n;
        cin >> r >> c >> n;
        cout << "Case #" << i << ": " << solve(r, c, n) << endl;
        i++;
    }
}
