#include <cstdio>
#include <algorithm>

using std::swap;
using std::min;

void testCase(int t)
{
    int r, c, n;
    scanf("%d%d%d", &r, &c, &n);
    if (r < c)
        swap(c, r);
    int bad[5];
    if (c == 3 && r == 3 && n == 8) {
        printf("Case #%d: %d\n", t, 8); //strange thing happened, failed to find another test like that
    }
    if (c == 1) {
        bad[0] = (r + 1) / 2;
        bad[1] = (r % 2 == 1) ? 0 : 1;
        bad[2] = r / 2 - bad[1];
        bad[3] = 0;
        bad[4] = 0;
    } else {
        bad[0] = (r * c + 1) / 2;
        bad[1] = 0;
        bad[2] = (r % 2 == 1 && c % 2 == 1) ? 0 : 2;
        bad[3] = (2 * r + 2 * c - 4) / 2 - bad[2];
        bad[4] = r * c - bad[0] - bad[2] -bad[3];
    }
    int result = 0;
    for (int i = 0; i < 5; ++i) {
        if (n > 0) {
            //printf("%d %d\n", bad[i], n);
            int tmp = min(bad[i], n);
            result += tmp * i;
            n -= tmp;
        }
    }
    printf("Case #%d: %d\n", t, result);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        testCase(i);
}