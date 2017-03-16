#include <cstdio>
#include <cstdlib>

const int N = 1005;

int T, b;
long long n, barber[N];

long long count(long long t) {
    long long res = 0;
    for (int i = 1; i <= b; i++)
        res += t / barber[i] + 1;
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        scanf("%d %lld", &b, &n);
        for (int i = 1; i <= b; i++)
            scanf("%lld", &barber[i]);
        long long l = 0, r = (long long)1e15, m = l;
        while (l < r) {
            long long mid = l + ((r - l) >> 1);
            if (count(mid) >= n) {
                m = mid;
                r = mid;
            }
            else
                l = mid + 1;
        }
        int res = 0;
        long long num = n;
        if (m > 0)
            num -= count(m - 1);
        for (int i = 1; i <= b; i++) {
            if (m % barber[i] == 0) {
                num--;
                res = i;
                if (num <= 0)
                    break;
            }
        }
        printf("Case #%d: %d\n", cases, res);
    }
    return EXIT_SUCCESS;
}

