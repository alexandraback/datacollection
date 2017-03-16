#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 1005;

int mush[N];

int main(void)
{
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &mush[i]);
        int first = 0, rate = 0;
        for (int i = 1; i < n; i++) {
            if (mush[i] < mush[i - 1]) {
                int r = mush[i - 1] - mush[i];
                first += r;
                rate = max(rate, r);
            }
        }
        int second = 0;
        for (int i = 0; i < n - 1; i++)
            second += rate < mush[i] ? rate : mush[i];
        printf("Case #%d: %d %d\n", cases, first, second);
    }
    return EXIT_SUCCESS;
}
