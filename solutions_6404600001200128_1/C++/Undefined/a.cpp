#include <bits/stdc++.h>

using namespace std;

int mush[10000];

int main() {
    int T, t, ans1, ans2, M, m, rate;
    scanf("%d", &T);
    for(t = 0; t < T; ++t) {
        ans1 = ans2 = rate = 0;
        scanf("%d", &M);
        scanf("%d", mush);
        for(m = 1; m < M; ++m) {
            scanf("%d", mush+m);
            if(mush[m-1] > mush[m]) {
                ans1 += mush[m-1] - mush[m];
                rate = max(rate, mush[m-1] - mush[m]);
            }
        }
        for(m = 1; m < M; ++m) {
            ans2 += rate;
            if(mush[m-1] < rate) {
                ans2 -= rate - mush[m-1];
            }
        }
        printf("Case #%d: %d %d\n", t+1, ans1, ans2);
    }
}
