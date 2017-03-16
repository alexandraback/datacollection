#include <cstdio>
#include <cmath>
#include <cstdlib>

int main ()
{
    int i, j;
    int T, N;
    int y, z, diff, max;
    int m[1000];

    scanf("%d\n", &T);
    for (i=0; i<T; i++) {
        scanf("%d\n", &N);
        for (j=0; j<N; j++) {
            scanf("%d", &m[j]);
        }
        y = 0;
        z = 0;
        max = 0;
        for (j=1; j<N; j++) {
            diff = m[j-1] - m[j];
            if (diff > 0) {
                y += diff;
            }
            if (diff > max) {
                max = diff;
            }
        }
        for (j=0; j<N-1; j++) {
            z += ((m[j] > max) ? max : m[j]);
        }
        printf("Case #%d: %d %d\n", i+1, y, z);
    }
    return 0;
}
