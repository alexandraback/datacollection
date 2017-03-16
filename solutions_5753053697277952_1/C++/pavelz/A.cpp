// Description
// URL

#include <bits/stdc++.h>
using namespace std;

#define FOR(c, m) for(int c=0;c<(int)(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)
#define LLI long long int
#define MOD 1000000007

int power(int a, int b) {
    int sq = a;
    int result = 1;
    while (b > 0) {
        if ((b & 1) == 1) result = result * (LLI)sq % MOD;
        sq = sq * (LLI)sq % MOD;
        b >>= 1;
    }
    return result;
}

int inv(int a) {
    return power(a, MOD - 2);
}

void fail() {
    *((char *)0) = 0;
}



int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int cc=1;cc<=cases;cc++) {
        int n;
        int p[100];
        scanf("%d", &n);
        FOR(i, n) scanf("%d", &p[i]);
        int total = 0;
        int distinct = 0;
        FOR(i, n) total += p[i];
        FOR(i, n) if (p[i] > 0) distinct++;

        printf("Case #%d:", cc);
        if (distinct == 2) {
            int v1, v2;
            FOR(j, n) if (p[j] != 0) { v1 = j; break;}
            FOR(j, n) if (p[j] != 0 && j != v1) { v2 = j; break;}
            while (p[v1] > p[v2]) { printf(" %c", v1 + 'A'); p[v1]--;}
            while (p[v2] > p[v1]) { printf(" %c", v2 + 'A'); p[v2]--;}
            while (p[v1] > 0){ printf(" %c%c", v1 + 'A', v2 + 'A'); p[v1]--;}
        } else {
            FOR(i, total) {
                int mx = 0;
                int pm = 0;
                FOR(j, n) if (p[j] > mx) { mx = p[j]; pm = j; }
                if (mx == 1) break;
                p[pm]--;
                printf(" %c", pm + 'A');
            }
            total = 0;
            FOR(i, n) total += p[i];
            if ((total & 1) == 1) {
                FOR(j, n) if (p[j] == 1) {
                    printf(" %c", j + 'A');
                    p[j] = 0;
                    total--;
                    break;
                }
            }
            FOR(i, total / 2) {
                printf(" ");
                FOR(j, n) if (p[j] == 1) {
                    printf("%c", j + 'A');
                    p[j] = 0;
                    break;
                }
                FOR(j, n) if (p[j] == 1) {
                    printf("%c", j + 'A');
                    p[j] = 0;
                    break;
                }
            }
        }
        printf("\n");
    }
}
