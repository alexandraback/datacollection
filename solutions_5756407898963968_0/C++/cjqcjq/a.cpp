#include <stdint.h>
#include <stdio.h>
#include <set>

using namespace std;

int32_t N = 4;

void Guess(set<int32_t> *s) {
    int32_t a = 0;
    scanf("%d", &a);
    for (int32_t i = 0; i < N; i++) {
        for (int32_t j = 0; j < N; j++) {
            int32_t d = 0;
            scanf("%d", &d);
            if (i + 1 == a) {
                s->insert(d);
            }
        }
    }
}
int32_t main() {
    int32_t cas;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic ++) {
        set<int32_t> sa, sb;
        Guess(&sa);
        Guess(&sb);
        int32_t c = 0;
        int32_t ans = -1;
        for (set<int32_t>::iterator it = sa.begin(); it != sa.end(); ++it) {
            if (sb.find(*it) != sb.end()) {
                c++;
                ans = *it;
            }
        }
        if (c == 1) {
            printf("Case #%d: %d\n", ic, ans);
        } else if (c > 1) {
            printf("Case #%d: Bad magician!\n", ic);
        } else {
            printf("Case #%d: Volunteer cheated!\n", ic);
        }
    }
}
