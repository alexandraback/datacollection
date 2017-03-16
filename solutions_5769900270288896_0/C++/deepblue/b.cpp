#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

int oc(int N) {
    int res = 0;
    while (N) {
        res ++;
        N &= N -1;
    }
    return res;
}

int isset(int mask, int pos) {
    if (pos < 0) {
        return 0;
    }
    if (pos > 30) {
        return 0;
    }
    return mask & (1 << pos) ? 1 : 0;
}

int count(int mask, int R, int C, int i, int j) {
    int pos = i * C + j;
    int res = 0;
    if (isset(mask, pos)) {
        int pos1 = i > 0 ? ((i-1) * C + j) : -1;
        int pos2 = j > 0? (i * C + (j - 1)) : -1;
        res = isset(mask, pos1) + isset(mask, pos2);
    }
    return res;
}

int solve(int R, int C, int N) {
    int tot = R * C;
    int res = 1000000000;
    for (int mask=0;mask < (1<<tot); mask ++) if (oc(mask) == N) {
        int cur = 0;
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                cur += count(mask, R, C, i, j);
            }
        }
        res = min(res, cur);
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int idx=1;idx<=T;idx++) {
        int R, C, N;
        scanf("%d %d %d", &R, &C, &N);
        int res = solve(R, C, N);
        cout << "Case #" << idx << ": " << res << endl;
    }
}
