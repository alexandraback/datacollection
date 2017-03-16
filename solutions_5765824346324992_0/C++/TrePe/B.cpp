#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int cases, kejs;
int i, j, k, B, N;
int M[1001];
set<pair<long long, int> > a;
pair<long long, int> plli;
int lcm, gcd;
int nisp[100001];
int ps[10000];
int np;
int cnt[10000];
int mcnt[10000];
int w[9765625];

int _lcm(int a, int b) {
    return a / __gcd(a,b) * b;
}

int main() {
    for (i = 2; i <= 100000; i++) {
        if (!nisp[i]) {
            ps[np++] = i;
            for (j = i+i; j <= 100000; j += i) nisp[j] = true;
        }
    }

    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%d%d", &B, &N);
        lcm = 1;
        a.clear();
        for (i = 0; i < B; i++) {
            scanf("%d", M+i);
            plli.first = 0;
            plli.second = i;
            a.insert(plli);
            lcm = _lcm(lcm, M[i]);
        }
//        fprintf(stderr, "lcm: %d\n", lcm);
        for (i = 0; ; i++) {
            plli = *(a.begin());
            if (plli.first == lcm) break;
            a.erase(a.begin());
            plli.first += M[plli.second];
            a.insert(plli);
            w[i] = plli.second;
//            fprintf(stderr, "%d %d\n", i, w[i]);
        }
        printf("%d\n", w[(N - 1) % i] + 1);
    }
    return 0;
}
