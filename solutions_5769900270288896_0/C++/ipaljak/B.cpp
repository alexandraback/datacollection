#include <algorithm>
#include <cstdio>

using namespace std;

int T;
int R, C, N;

int dr[] = {1, 0, -1, 0};
int ds[] = {0, 1, 0, -1};

int get_r(int n) {
    return n / C;
}

int get_c(int n) {
    return n % C;
}

inline bool adj(int j, int k) {
    
    int r1 = get_r(j), s1 = get_c(j);
    int r2 = get_r(k), s2 = get_c(k);
    
    for (int i = 0; i < 4; ++i) {
        if (r2 == r1 + dr[i] && s2 == s1 + ds[i]) return true;
    }
    return false;
}

int brute() {

    int ret = 1000000000;
    
    for (int i = 0; i < (1 << (R*C)); ++i) {
        if (__builtin_popcount(i) != N) continue; 
        int tmp = 0;
        for (int j = 0; j < R * C; ++j) {
            if ((i & (1 << j)) == 0) continue;
            for (int k = 0; k < R * C; ++k) {
                if ((i & (1 << k)) == 0) continue;
                if (k == j) continue;
                tmp += adj(j, k);
            }
        }
        ret = min(ret, tmp);
    }

    return ret / 2;
    
}

void solve(int t) {

    scanf("%d%d%d", &R, &C, &N);
    printf("Case #%d: %d\n", t, brute());

}

int main(void) {

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) solve(i + 1);

    return 0;

}
