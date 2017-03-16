#include <stdio.h>
#define INF 100000000000000LL
#define lli long long int

int v[1005];

int main(void) {
    int t;
    int b, n;
    lli low, high, mid;
    lli done;
    int idx = 0;

    scanf(" %d", &t);

    for (int caso = 1; caso <= t; caso++) {
        scanf(" %d %d", &b, &n);

        for (int i = 0; i < b; i++) {
            scanf(" %d", &v[i]);
        }

        if (n <= b) {
            printf("Case #%d: %d\n", caso, n);
        } else {
            low = 0;
            high = INF;
            while(low + 1 < high) {
                done = b;
                mid = (low + high) / 2;

                for (int i = 0; i < b; i++) {
                    done += mid / v[i];
                }
                //printf("low = %d, high = %d, done = %d\n", low, high, done);
                if (done >= n) {
                    high = mid - 1;
                } else {
                    low = mid;
                }
            }

            //printf("low = %lld, done = %lld\n", low, done);
            for (int i = low + 1; done < n; i++) {
                for (int j = 0; j < b; j++) {
                    done += (i % v[j] == 0) ? 1 : 0;
                    //printf("summing = %d\n", (i % v[j] == 0) ? 1 : 0);
                    if (done == n) {
                        idx = j;
                        break;
                    }
                }
            }
            printf("Case #%d: %d\n", caso, idx + 1);
        }
    }
    return 0;
}
