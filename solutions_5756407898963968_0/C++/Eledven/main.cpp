#include <cstdio>
#include <cassert>

int main() {
    int nt;
    assert(scanf("%d", &nt) == 1);
    for (int tt = 1; tt <= nt; tt++) {
        bool fs[17] = {false};
        bool sc[17] = {false};
        int r1, r2;
        assert(scanf("%d", &r1) == 1);
        --r1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int a;
                assert(scanf("%d", &a) == 1);
                if (i == r1) {
                    fs[a] = true;
                }
            }
        }
        assert(scanf("%d", &r2) == 1);
        --r2;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int b;
                assert(scanf("%d", &b) == 1);
                if (i == r2) {
                    sc[b] = true;
                }
            }
        }
        int y = -1;
        int cnt = 0;
        for (int i = 1; i <= 16; i++) {
            if (fs[i] && sc[i]) {
                y = i;
                cnt++;
            }
        }
        if (cnt == 0) {
            printf("Case #%d: Volunteer cheated!\n", tt);
        } else if (cnt > 1) {
            printf("Case #%d: Bad magician!\n", tt);
        } else {
            printf("Case #%d: %d\n", tt, y);
        }
    }
    return 0;
}
