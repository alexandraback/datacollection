#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;

int solve(int R, int C, int N) {
    int n = R*C;
    int tmp = (n+1) / 2;
    if (tmp >= N) return 0;
    N -= tmp;
    if (R == 1 || C == 1) {
        if (R < C) swap(R, C);
        if (R % 2) {
            return 2*N;
        } else {
            return 1+(N-1)*2;
        }
    }
    if (R % 2 == 1 && C % 2 == 1) {
        N++;
        if (N <= 4) return 2*N;
        N -= 4;
        int hen = (R/2-1)*2+(C/2-1)*2;
        if (N <= hen) return N*3;
        return hen*3+(N-4)*4;
    } else if (R%2 == 0 && C % 2 == 0) {
        if (N <= 2) return 2*N;
        N -= 2;
        int hen = (R/2-1) * 2 + (C/2-1) * 2;
        if (N <= hen) return 4+N*3;
        return 4+hen*3+(N-hen)*4;
    } else if (R%2 == 0 && C % 2 == 1) {
        if (N <= 2) return 2*N;
        N -= 2;
        int hen = (R/2-1) * 2 + C/2;
        if (N <= hen) return 4+N*3;
        return 4+hen*3+(N-hen)*4;
    } else {
        swap(R, C);
        if (N <= 2) return 2*N;
        N -= 2;
        int hen = (R/2-1) * 2 + C/2;
        if (N <= hen) return 4+N*3;
        return 4+hen*3+(N-hen)*4;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int R, C, N;
        cin >> R >> C >> N;
        printf("Case #%d: %d\n", t, solve(R, C, N));
    }
    return 0;
}
