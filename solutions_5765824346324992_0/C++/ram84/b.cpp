#include <cstdio>
#include <cmath>
#include <cstdlib>

bool isprime (long i)
{
    long j;
    if (i < 2) {
        return false;
    }
    for (j=2; j<=sqrt(i); j++) {
        if (i % j == 0) {
            return false;
        }
    }
    return true;
}

long rmcf (long a, long b)
{
    long c, d;
    long i;
    c = a;
    d = b;
    if (a < 2 || b < 2) {
        return a;
    }
    for (i=2; i<=a && i<=b; i++) {
        while (isprime(i) && (c%i==0) && (d%i==0)) {
            c /= i;
            d /= i;
        }
    }
    return c;
}

long lcm (long *M, long B)
{
    long i, l;
    l = 1l;
    for (i=0l; i<B; i++) {
        if (l % M[i]) {
            l *= rmcf(M[i], l);
        }
    }
    return l;
}

int main ()
{
    long i, j, m, n;
    long T, B, N;
    long lcd;
    long ans;
    long M[1000];
    long nsteps[1000];
    long totsteps;
    bool busy[1000];

    scanf("%ld\n", &T);
    for (i=0; i<T; i++) {
        scanf("%ld %ld\n", &B, &N);
        for (j=0; j<B; j++) {
            scanf("%ld", &M[j]);
            busy[j] = true;
        }
        if (N <= B) {
            ans = N;
        } else {
            totsteps = 0;
            lcd = lcm(M, B);
            for (j=0; j<B; j++) {
                nsteps[j] = lcd / M[j];
                if (lcd % M[j]) {
                    fprintf(stderr, "lcd %ld doesn't divide M[%ld] which is %ld\n", lcd, j, M[j]);
                }
                totsteps += nsteps[j];
            }
            N = (N-1) % totsteps + 1;
            n = 0;
            for (m=0; n<N; m++) {
                for (j=0; j<B; j++) {
                    if (m % M[j] == 0) {
                        n++;
                    }
                    if (n==N) {
                        ans = j;
                        break;
                    }
                }
            }
        }
        printf("Case #%ld: %ld\n", i+1, ans+1);
    }
    return 0;
}
