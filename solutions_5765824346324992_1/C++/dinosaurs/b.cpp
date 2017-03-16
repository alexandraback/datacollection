#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAX = 1010;

int T, N, B, m[MAX];
long long n[MAX];

// returns # people cut at time t
long long test(long long t) {
    long long tot = 0;
    for (int i = 0; i < B; ++i) {
        if (m[i] == 1) {
            tot += t;
        } else if (t % m[i] == 0) {
            tot += t / m[i];
        } else {
            tot += 1 + t / m[i];
        }
    }
    return tot;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &B, &N);
        for (int i = 0; i < B; ++i) {
            scanf("%d", &m[i]);
        }

        // what is the maximum time t such that the Nth person in line has not gotten the haircut?
        long long low = 0, high = 100000000000000LL;
        while (low < high) {
            long long mid = (low + high) / 2 + 1;

            if (test(mid) < N) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        // who cuts person N's hair?
        int answer = -1;
        long long tot = test(high);
        long long first = 100000000000000LL;
        for (int i = 0; i < B; ++i) {
            n[i] = (high / m[i]) * m[i]; // next available time
            if (n[i] < high) {
                n[i] += m[i];
            }
        }

        while (tot < N) {
            answer = -1;
            first = 100000000000000LL;
            for (int i = 0; i < B; ++i) {
                if (n[i] < first) {
                    answer = i;
                    first = n[i];
                }
            }
            n[answer] += m[answer];
            tot++;
        }

        printf("Case #%d: %d\n", t, answer + 1);
    }

    return 0;
}
