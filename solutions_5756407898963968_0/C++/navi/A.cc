#include <cstdio>

int gao() {
    int ret = 0, n;
    scanf("%d", &n);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int a;
            scanf("%d", &a);
            if (i == n - 1) {
                ret |= 1 << a;
            }
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int A = gao();
        int B = gao();
        int res = A & B;
        if (res == 0) {
            printf("Case #%d: Volunteer cheated!\n", caseNum);
        } else if ((res & -res) == res) {
            printf("Case #%d: %d\n", caseNum, __builtin_ctz(res));
        } else {
            printf("Case #%d: Bad magician!\n", caseNum);
        }
    }
    return 0;
}
